CREATE OR REPLACE TEMPORARY TABLE import_orderitem (
	"orderitem"	INTEGER NOT NULL UNIQUE,
	"order"	INTEGER NOT NULL,
	"supply"	INTEGER NOT NULL,
	"amount"	INTEGER NOT NULL,
	"cost_per_item"	NUMERIC NOT NULL,
	PRIMARY KEY("orderitem"),
	FOREIGN KEY("order") REFERENCES "order"("order"),
	FOREIGN KEY("supply") REFERENCES "supply"("supply")
);