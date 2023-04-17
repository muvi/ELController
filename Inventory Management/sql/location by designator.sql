SELECT
  project.project,
  bom.designator,
  bom.designator_nr,
  part.value,
  part.part,
  part.location
FROM bom
  LEFT JOIN project ON project.project = bom.project
  LEFT JOIN part ON part.part = bom.part
WHERE project.short = 'elcontroller2'
  AND bom.designator || bom.designator_nr IN ('C98')