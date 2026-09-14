USE C21_DB1;

-- Searched CASE: Evaluates a set of Boolean expressions.
SELECT 
	SaleID, SaleAmount,
	CASE
		WHEN SaleAmount <= 100 THEN 'Weak'
		WHEN SaleAmount BETWEEN 101 AND 200 THEN 'Good'
		WHEN SaleAmount BETWEEN 201 AND 300 THEN 'Very Good'
		WHEN SaleAmount > 300 THEN 'Excellent'
		ELSE 'Not Specified'
	END AS SaleLevel
FROM Sales;

-- This uses searched CASE for more complex conditions, categorizing employees by salary.