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
  
WHERE (partgroup.detail_table IS NOT 'resistor' AND resistor.part IS NOT NULL)
  OR (partgroup.detail_table IS NOT 'capacitor' AND capacitor.part IS NOT NULL)
  OR (partgroup.detail_table IS NOT 'transformer' AND transformer.part IS NOT NULL)
  OR (partgroup.detail_table IS NOT 'mosfet' AND mosfet.part IS NOT NULL)
  OR (partgroup.detail_table IS NOT 'fuse' AND fuse.part IS NOT NULL)
  OR (partgroup.detail_table IS NOT 'diode' AND diode.part IS NOT NULL)
  OR (partgroup.detail_table IS NOT 'led' AND led.part IS NOT NULL)
  OR (partgroup.detail_table IS NOT 'inductor' AND inductor.part IS NOT NULL)
  OR (partgroup.detail_table IS NOT 'ferrite' AND ferrite.part IS NOT NULL)