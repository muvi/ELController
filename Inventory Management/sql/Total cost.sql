SELECT
  SUM(cost*amount) AS total_cost,
  (CASE
    WHEN MAX(vendor IS NULL) = 1 THEN 'FALSE'
	ELSE 'TRUE'
  END) AS all_parts_included,
  SUM((vendor IS NULL) * amount) AS ignored_parts
FROM (
  SELECT
    COUNT(bom.part) AS amount,
    supply.cost,
	supply.vendor
  FROM bom
    LEFT JOIN project ON project.project = bom.project
    LEFT JOIN part ON part.part = bom.part
    LEFT JOIN supply ON supply.part = bom.part AND cost = (
      SELECT MIN(cost)
	  FROM supply
	  WHERE supply.part = bom.part
    )
  WHERE project.short = 'idealdiode1'
  GROUP BY bom.part
) AS cheapest_vendors
