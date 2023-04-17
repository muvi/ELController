SELECT *
FROM capacitor
  LEFT JOIN supply ON supply.part = capacitor.part
  LEFT JOIN part ON part.part = capacitor.part
WHERE capacitor.value || capacitor.value_prefix = '1u'