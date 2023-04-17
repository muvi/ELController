UPDATE import_orderitem
SET
  cost_per_item = REPLACE(REPLACE(REPLACE(cost_per_item, '€', ''), ' ', ''), ',', '.') + 0