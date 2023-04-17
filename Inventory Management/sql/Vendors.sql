SELECT
  project.name,
  project.revision,
  part.part,
  part.value,
  COUNT(bom.part) AS amount,
  supply.vendor,
  supply.vendor_part,
  supply.cost,
  supply.cost * COUNT(bom.part) AS full_cost
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