SELECT
  project.name,
  project.revision,
  bom.designator,
  bom.designator_nr,
  part.value,
  part.footprint,
  part.part
FROM bom
  LEFT JOIN project ON project.project = bom.project
  LEFT JOIN part ON part.part = bom.part
  LEFT JOIN supply ON supply.part = bom.part
--    AND supply.vendor = 'mouser'
WHERE supply.vendor IS NULL
--  AND project.short = 'elcontroller2'