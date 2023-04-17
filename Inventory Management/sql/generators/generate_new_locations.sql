INSERT INTO location
  SELECT
    char(unicode(substr(location.location, 1, 1))+9) || substr(location.location, 2, LENGTH(location.location)) AS location,
    x,
    y,
    z,
    'small_parts' AS storage
  FROM location
  WHERE storage IS NULL