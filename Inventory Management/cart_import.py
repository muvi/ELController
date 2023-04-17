import tkinter as tk
from tkinter import filedialog as fd
import sys
import os
import pandas as pd
import sqlite3
import re
from datetime import datetime

use_graphics = len(sys.argv) < 2

def printError(s):
    if use_graphics:
        tk.messagebox.showerror(title='Error importing cart', message=s)
    else:
        print(s)
    sys.exit()

def printInfo(s):
    if use_graphics:
        tk.messagebox.showinfo(title='Importing cart', message=s)
    else:
        print(s)

#open cart file
if (not use_graphics):
    fname = sys.argv[1]
else:
    fname = fd.askopenfilename(
        title = 'Open cart',
        filetypes = (
            ('Supported files', '*.xls *.csv'),
            ('Excel files', '*.xls'),
            ('CSV files', '*.csv')
        )
    )
    if not fname:
        sys.exit()
(filepath, ext) = os.path.splitext(fname)

if ext == '.xls':
    df = pd.read_excel(fname)
elif ext == '.csv':
    df = pd.read_csv(fname)
else:
    printError("Unsupported file format: " + ext)

#assign db 
dbFile = os.path.join(os.path.dirname(__file__), 'inventory_management.db')

#get order nr
ordernr = os.path.basename(filepath)

#detect vendor
def cleanStr(s):
    return re.sub('[^abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ]', '', s)

i = 0
query = ""
for column in df.columns.values:
    if i > 0:
        query += "),\n          ("
    query += str(i) + ", '" + cleanStr(column) + "'"
    i += 1
query = '''
    SELECT
      vendor
    FROM import_column
    LEFT JOIN
      (SELECT
        column1 As "index",
        column2 As name
      FROM
        (VALUES
          (''' + query + ''')
        )
      ) AS cart_data ON cart_data."index" = import_column."index" AND cart_data.name = import_column.name
    WHERE import_column."index" IS NOT NULL
    GROUP BY vendor
    HAVING SUM(cart_data."index" IS NULL) = 0
    '''

con = sqlite3.connect(dbFile)
cur = con.cursor()
result = cur.execute(query)

row = result.fetchone()
if row is None:
    printError("Vendor could not be identified")
row2 = result.fetchone()
if row2 is not None:
    printError("Multiple possible vendors found")
if len(row) != 1:
    printError("Query for getting vendor contains an error")
vendor = row[0]

#unify data
result = cur.execute('''
    SELECT
      import_column."index",
      import_column.format
    FROM (VALUES
        ('part'),
        ('vendor_part'),
        ('manufacturer_part'),
        ('amount'),
        ('cost_per_item'),
        ('date')
      ) AS columns
      LEFT JOIN import_column ON import_column.import_property = columns.column1
    WHERE vendor = ?
''', (vendor,))
rows = result.fetchall()

INDEX_PART = 0
INDEX_VENDOR_PART = 1
INDEX_MANUFACTURER_PART = 2
INDEX_AMOUNT = 3
INDEX_COST_PER_ITEM = 4
INDEX_DATE = 5

empty_column = len(df.columns)
df["empty"] = None

columns = []
i = 0
dateformat = None
for row in rows:
    (index, fmt) = row
    if index is None:
        columns += [empty_column]
    else:
        columns += [index]
        if i == INDEX_DATE:
            dateformat = fmt
    i += 1

df = df.iloc[:, columns]

#retrieve date
if len(df.index) < 1:
    printError("order is empty")

date = df.iloc[0, INDEX_DATE]
if date is None:
    date = datetime.now()
else:
    if dateformat is None:
        printError("Dateformat for vendor " + vendor + " is not set")
    date = datetime.strptime(date, dateformat)

#import into temporary table
cur.execute('''
    CREATE TEMPORARY TABLE import_orderitem (
      "index" INTEGER,
      part INTEGER,
      vendor_part TEXT,
      manufacturer_part TEXT,
      amount INTEGER,
      cost_per_item NUMERIC,
      date TEXT,
      supply INTEGER
);''')

data = tuple(df.itertuples())
cur.executemany('INSERT INTO import_orderitem VALUES (?, ?, ?, ?, ?, ?, ?, NULL)', data)

#delete empty rows (sometimes there are summing rows at the bottom)
cur.execute('DELETE FROM import_orderitem WHERE vendor_part IS NULL')

#fill supply
cur.execute('''
    UPDATE import_orderitem
    SET
      supply = supply.supply
    FROM supply
    WHERE supply.vendor_part = import_orderitem.vendor_part
''')

#unify cost column
cur.execute('''
    UPDATE import_orderitem
    SET
      cost_per_item = REPLACE(REPLACE(REPLACE(cost_per_item, '€', ''), ' ', ''), ',', '.') + 0
''')

#look for missing supply
result = cur.execute('SELECT * FROM import_orderitem WHERE supply IS NULL')
rows = result.fetchall()
if (len(rows) > 0):
    error = "Some supply entries are missing:\n\n"
    for row in rows:
        error += str(row) + "\n"
    printError(error)

#insert order
result = cur.execute('SELECT "order"."order" FROM "order" WHERE vendor = ? AND ordernr = ?', (vendor, ordernr))
row = result.fetchone()
if row is None:
    cur.execute('INSERT INTO "order"(vendor, ordernr, date) VALUES (?, ?, ?)', (vendor, ordernr, date.strftime('%Y-%m-%d')))
    result = cur.execute('SELECT "order"."order" FROM "order" WHERE vendor = ? AND ordernr = ?', (vendor, ordernr))
    row = result.fetchone()
order = row[0]

#delete existing items in current order
cur.execute('DELETE FROM orderitem WHERE "order" = ?', (order,))

#insert new order items
cur.execute('''
    INSERT INTO orderitem("order", supply, amount, cost_per_item)
    SELECT
      ?AS "order",
      supply,
      amount,
      cost_per_item
    FROM import_orderitem
''', (order,))

con.commit()

printInfo("Cart imported successfully")
