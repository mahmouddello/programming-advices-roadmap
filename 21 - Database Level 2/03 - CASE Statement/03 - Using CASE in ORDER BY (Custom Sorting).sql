USE C21_DB1;

-- Using CASE in ORDER BY (Custom Sorting)

SELECT * 
FROM Sales
ORDER BY
	CASE 
		WHEN SaleAmount > 150 THEN 1
		ELSE 2
	END, SaleAmount DESC;

-- How SQL Server conceptualizes it internally:
SELECT *, (CASE WHEN SaleAmount > 150 THEN 1 ELSE 2 END) AS _TempSortColumn
FROM Sales
ORDER BY _TempSortColumn;