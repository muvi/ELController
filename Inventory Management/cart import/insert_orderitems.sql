INSERT INTO orderitem("order", supply, amount, cost_per_item)
SELECT
  ? AS "order",
  supply,
  amount,
  cost_per_item
FROM import_orderitem