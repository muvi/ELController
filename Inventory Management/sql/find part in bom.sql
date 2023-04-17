SELECT *
FROM bom
  LEFT JOIN project ON project.project = bom.project
WHERE bom.part = 63