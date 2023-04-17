SELECT *
FROM supply
WHERE LENGTH(manufacturer_part) >= LENGTH(vendor_part)
  AND part NOT IN (37, 8, 30, 60, 42, 71, 106, 220, 219)