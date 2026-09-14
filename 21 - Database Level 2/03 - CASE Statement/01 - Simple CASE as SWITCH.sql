USE C21_DB1;

-- Simple Case: Compare an expression to as set of specific values

SELECT 
	EmployeeID,
	CASE DepartmentID
		WHEN 1 THEN 'Engineering'
		WHEN 2 THEN 'Human Resources'
		WHEN 3 THEN 'Sales'
		ELSE 'Other'
	END AS DepartmentName
FROM Employees;

-- This mimics a SWITCH statement by assigning department names based on department IDs.		