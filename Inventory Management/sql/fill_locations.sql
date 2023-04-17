WITH RECURSIVE
  cnt(x) AS (
     SELECT 1
     UNION ALL
     SELECT x+4 FROM cnt
      LIMIT 16
  )
INSERT INTO location
SELECT
  'I' || cnt.x AS location,
  cnt.x,
  1 AS y,
  1 AS z
FROM cnt;