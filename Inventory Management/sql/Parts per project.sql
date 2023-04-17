SELECT COUNT(*)
FROM bom
  LEFT JOIN project ON project.project = bom.project
WHERE project.short = 'elcontroller2'