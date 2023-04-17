SELECT *
FROM resistor
  LEFT JOIN supply ON supply.part = resistor.part
  LEFT JOIN part ON part.part = resistor.part
WHERE --resistor.value || resistor.value_prefix = '50'
  resistor.value BETWEEN 1 AND 3
  AND resistor.value_prefix = 'k'
ORDER BY part