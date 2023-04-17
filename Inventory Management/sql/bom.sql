SELECT *
FROM bom
  LEFT JOIN project ON project.project = bom.project
WHERE project.short = 'idealdiode1'
ORDER BY designator, designator_nr