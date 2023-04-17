SELECT
  vendor
FROM import_column
LEFT JOIN
  (SELECT
    column1 As "index",
    column2 As name
  FROM
    (VALUES
      (0, 'Index'),
      (1, 'Menge'),
      (2, 'Teilenummer'),
      (3, 'HerstellerTeilenummer'),
      (4, 'Beschreibung'),
      (5, 'Kundenreferenz'),
      (6, 'Lieferrckstnde'),
      (7, 'Stckpreis'),
      (8, 'Gesamtpreis')
    )
  ) AS cart_data ON cart_data."index" = import_column."index" AND cart_data.name = import_column.name

GROUP BY vendor
HAVING SUM(cart_data."index" IS NULL) = 0