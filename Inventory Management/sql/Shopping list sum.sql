SELECT
  (CASE
    WHEN SUM (full_cost) IS NULL THEN 0
	ELSE SUM (full_cost)
  END) AS cost
FROM (
SELECT
  group_concat(project_parts.project, ', ') AS project,
  project_parts.part,
  part.value,
  MAX(SUM(project_parts.target_quantity * (project_parts.project = 'Part targets')), SUM(project_parts.target_quantity * (project_parts.project <> 'Part targets'))) - part.amount AS amount_to_buy,
  supply.vendor,
  supply.vendor_part,
  supply.cost AS cost_per_item,
  supply.cost * (MAX(SUM(project_parts.target_quantity * (project_parts.project = 'Part targets')), SUM(project_parts.target_quantity * (project_parts.project <> 'Part targets'))) - part.amount) AS full_cost
FROM (
  SELECT
    project.name || ' Rev.' || project.revision AS project,
    part.part,
    COUNT(bom.part) * project.target_quantity AS target_quantity
  FROM bom
    LEFT JOIN project ON project.project = bom.project
    LEFT JOIN part ON part.part = bom.part
  WHERE project.target_quantity > 0
  GROUP BY bom.part, project.project

  UNION ALL

  SELECT
    'Part targets' AS project,
    part.part,
    part.target_quantity AS target_quantity
  FROM part
  WHERE part.target_quantity > 0
) AS project_parts
  LEFT JOIN supply ON supply.part = project_parts.part AND cost = (
    SELECT MIN(cost)
	FROM supply
	WHERE supply.part = project_parts.part
	  AND supply.vendor = 'mouser'
  )
  LEFT JOIN part ON part.part = project_parts.part
GROUP BY project_parts.part
HAVING MAX(SUM(project_parts.target_quantity * (project_parts.project = 'Part targets')), SUM(project_parts.target_quantity * (project_parts.project <> 'Part targets'))) - part.amount > 0
) AS shopping_list