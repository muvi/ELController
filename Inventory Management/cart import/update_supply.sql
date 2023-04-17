UPDATE import_orderitem
SET
  supply = supply.supply
FROM supply
  WHERE supply.vendor_part = import_orderitem.vendor_part