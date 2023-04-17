UPDATE part
  SET
    location = char(unicode(substr(location.location, 1, 1))+9) || substr(location.location, 2, LENGTH(location.location))
  FROM location
WHERE location.storage IS NULL
  AND part.location IS NOT NULL
  AND location.location = part.location