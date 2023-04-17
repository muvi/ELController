SELECT
  partgroup.name,
  partgroup.detail_table,
  part.part,
  part.value
FROM part
  LEFT JOIN parttype ON parttype.parttype = part.parttype
  LEFT JOIN partgroup ON partgroup.partgroup = parttype.partgroup

  LEFT JOIN resistor ON resistor.part = part.part
  LEFT JOIN capacitor ON capacitor.part = part.part
  LEFT JOIN transformer ON transformer.part = part.part
  LEFT JOIN mosfet ON mosfet.part = part.part
  LEFT JOIN fuse ON fuse.part = part.part
  LEFT JOIN diode ON diode.part = part.part
  LEFT JOIN led ON led.part = part.part
  LEFT JOIN inductor ON inductor.part = part.part
  LEFT JOIN ferrite ON ferrite.part = part.part
  
WHERE (partgroup.detail_table = 'resistor' AND resistor.part IS NULL)
  OR (partgroup.detail_table = 'capacitor' AND capacitor.part IS NULL)
  OR (partgroup.detail_table = 'transformer' AND transformer.part IS NULL)
  OR (partgroup.detail_table = 'mosfet' AND mosfet.part IS NULL)
  OR (partgroup.detail_table = 'fuse' AND fuse.part IS NULL)
  OR (partgroup.detail_table = 'diode' AND diode.part IS NULL)
  OR (partgroup.detail_table = 'led' AND led.part IS NULL)
  OR (partgroup.detail_table = 'inductor' AND inductor.part IS NULL)
  OR (partgroup.detail_table = 'ferrite' AND ferrite.part IS NULL)
