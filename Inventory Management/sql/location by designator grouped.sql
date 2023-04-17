SELECT
  project.project,
  bom.designator,
  bom.designator_nr,
  part.value,
  part.part,
  part.location,
  COUNT(*) AS amount_needed,
  part.amount AS amount_available
FROM bom
  LEFT JOIN project ON project.project = bom.project
  LEFT JOIN part ON part.part = bom.part
WHERE project.short = 'idealdiode1'
  AND bom.designator || bom.designator_nr IN ('R1', 'R2', 'R3', 'R4', 'R5', 'R6', 'D1', 'D2', 'U1', 'Q1')
GROUP BY part.part