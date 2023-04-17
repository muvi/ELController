SELECT
  part.value AS part_value,
  part.footprint,
  capacitor.value,
  capacitor.value_prefix,
  capacitor.voltage
FROM capacitor
  LEFT JOIN prefix ON prefix.prefix = capacitor.value_prefix
  LEFT JOIN part ON part.part = capacitor.part
ORDER BY prefix.exponent, capacitor.value