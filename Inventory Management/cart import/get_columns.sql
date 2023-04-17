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
WHERE vendor = 'mouser'