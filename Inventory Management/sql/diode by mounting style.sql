SELECT *
FROM diode
  LEFT JOIN part ON part.part = diode.part
  --LEFT JOIN parttype ON parttype.parttype = part.parttype
  --LEFT JOIN partgroup ON partgroup.partgroup = parttype.parttype
  --LEFT JOIN partcategory ON partcategory.partcategory = partgroup.partcategory
  LEFT JOIN footprint ON footprint.footprint = part.footprint
--WHERE footprint.mounting_style = 'th'