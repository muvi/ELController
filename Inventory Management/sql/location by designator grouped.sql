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
WHERE project.short = 'elcontroller2'
  AND bom.designator || bom.designator_nr IN ('U12', 'Q9', 'C50', 'Q10', 'L7', 'Q8', 'C46', 'R60', 'R61', 'R59', 'R54', 'R55', 'R56', 'R58')
GROUP BY part.part