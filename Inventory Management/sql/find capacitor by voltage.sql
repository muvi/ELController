SELECT *
FROM capacitor
  LEFT JOIN part ON part.part = capacitor.part
  LEFT JOIN prefix ON prefix.prefix = capacitor.value_prefix
WHERE capacitor.voltage >= 200
ORDER BY prefix.exponent, capacitor.value