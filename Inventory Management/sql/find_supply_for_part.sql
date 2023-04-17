SELECT
  part.part,
  part.value,
  supply.vendor_part,
  supply.supply
FROM part
LEFT JOIN supply ON supply.part = part.part
WHERE part.part = 108
  AND supply.vendor = 'mouser'