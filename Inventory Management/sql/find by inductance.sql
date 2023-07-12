SELECT *
FROM inductor
  LEFT JOIN supply ON supply.part = inductor.part
  LEFT JOIN part ON part.part = inductor.part
--WHERE --resistor.value || resistor.value_prefix = '50'
  --resistor.value BETWEEN 100 AND 100
  --AND resistor.value_prefix = ''
ORDER BY part