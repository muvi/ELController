SELECT *
FROM resistor
  LEFT JOIN supply ON supply.part = resistor.part
  LEFT JOIN part ON part.part = resistor.part
  LEFT JOIN footprint ON footprint.footprint = part.footprint
WHERE resistor.value || resistor.value_prefix = '1k'
  --resistor.value BETWEEN 100 AND 900
  --AND resistor.value_prefix = ''
  AND footprint.mounting_style = 'th'
ORDER BY part