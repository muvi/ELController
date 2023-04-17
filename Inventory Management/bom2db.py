#
# Python script to generate a BOM from a KiCad netlist and write it to the inventory management system
#

"""
    @package
    Output: Writes BOM to SQLite database
    Grouped By:
    Sorted By:
    Fields: Ref, Value, Part, Footprint, Datasheet, DNP

    Command line:
    python "pathToFile/bom2db.py" "%I" "%O-bom-log.csv"
"""

#from __future__ import print_function

# Import the KiCad python helper module
import kicad_netlist_reader
import kicad_utils
import kicad_sheet_metadata
import csv
import sys
import sqlite3
import re
import os
import csv

inputFile = sys.argv[1]
logFile = sys.argv[2]
dbFile = os.path.join(os.path.dirname(__file__), 'inventory_management.db')

# A helper function to convert a UTF8/Unicode/locale string read in netlist
# for python2 or python3
def fromNetlistText( aText ):
    if sys.platform.startswith('win32'):
        try:
            return aText.encode('utf-8').decode('cp1252')
        except UnicodeDecodeError:
            return aText
    else:
        return aText

# override csv.writer's writerow() to support utf8 encoding:
def writerow( acsvwriter, columns ):
    utf8row = []
    for col in columns:
        utf8row.append( fromNetlistText( str(col) ) )
    acsvwriter.writerow( utf8row )

# Generate an instance of a generic netlist, and load the netlist tree from
# the command line option. If the file doesn't exist, execution will stop
net = kicad_netlist_reader.netlist(inputFile)
components = net.getInterestingComponents()
metadata = kicad_sheet_metadata.sheet_metadata(net)

# Open a file to write to, if the file cannot be opened output to stdout
# instead
try:
    outfile= kicad_utils.open_file_write(sys.argv[2], 'w')
except IOError:
    e = "Can't open output file for writing: " + sys.argv[2]
    print( __file__, ":", e, sys.stderr )
    outfile = sys.stdout

# Create a new csv writer object to use as the output formatter
out = csv.writer(outfile, lineterminator='\n', delimiter=',', quotechar="\"", quoting=csv.QUOTE_ALL)

# Get project metadata
title = metadata.getTitle()
revision = metadata.getRevision()

# Output a field delimited header line
writerow(out, ['Title:', title])
writerow(out, ['Revision:', revision])
writerow(out, ['Date:', net.getDate()])
writerow(out, ['Ref', 'Error message', 'Value', 'Footprint', 'Datasheet'])

hasErrors = False
def writeError(designator, txt, value, footprint, datasheet):
    global hasErrors
    hasErrors = True
    print(designator + ' ("' + value + '" footprint ' + footprint + ')' + ': ' + txt)
    writerow(out, [designator, txt, value, footprint, datasheet])

print ('\n')

con = sqlite3.connect(dbFile)
cur = con.cursor()

#find project in database and update name, revision and uuid
result = cur.execute("""
    SELECT
        project.project
    FROM project
    WHERE project.name = ?
        AND project.revision = ?
""", (title, revision))
row = result.fetchone()
if not row is None:
    project = row[0]
else:
    cur.execute("""
        INSERT INTO project(name, revision, short)
        VALUES(?, ?, ?)
    """, (title, revision, title.replace(' ', '').replace('-', '').replace('_', '').lower() + revision))
    con.commit()
    result = cur.execute("""
        SELECT
            project.project
        FROM project
        WHERE project.name = ?
            AND project.revision = ?
    """, (title, revision))
    row = result.fetchone()
    project = row[0]

# Clear the BOM for the current project
cur.execute("""
    DELETE FROM bom
    WHERE project = ?
""", (project,))

# Output all of the component information
for c in components:
    value = c.getValue()
    footprint = c.getFootprint()
    datasheet = c.getDatasheet()
    ref = c.getRef()
    refLetterEnd = re.search('[0-9]', ref).span()[0]
    refLetter: str = ref[:refLetterEnd]
    refNumber: int = ref[refLetterEnd:]
    
    #ignore uninteresting parts like mounting holes, ect...
    result = cur.execute("""
       SELECT
           designator.partcategory
       FROM designator
       WHERE designator.designator = ?
    """, (refLetter,))
    row = result.fetchone()
    if row is None:
        writeError(ref, 'Designator ' + refLetter + ' undefined', value, footprint, datasheet)
        continue
    if row[0] is None:
        continue
    
    #retrieve part id
    result = cur.execute("""
    	SELECT
    	    part.part,
    	    part.value,
    	    part.footprint
    	FROM part
    	    LEFT JOIN footprint_kicad ON footprint_kicad.footprint = part.footprint
    	WHERE part.value = ?
    	    AND footprint_kicad.footprint_kicad = ?
    """, (value, footprint))
    row = result.fetchone()
    
    #print error output if part has not been found
    if row is None:
        writeError(ref, 'Missing part', value, footprint, datasheet)
        continue
    else:
        part = row[0]
        cur.execute("""
            INSERT INTO bom(project, designator, designator_nr, part)
            VALUES (?, ?, ?, ?)
        """, (project, refLetter, refNumber, part))

if hasErrors:
    con.rollback()
else:
    con.commit()

con.close()
outfile.close()
