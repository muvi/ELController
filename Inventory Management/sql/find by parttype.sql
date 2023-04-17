SELECT *
FROM part
  LEFT JOIN supply ON supply.part = part.part
  LEFT JOIN inductor ON inductor.part = part.part
WHERE part.parttype = 'common_mode'