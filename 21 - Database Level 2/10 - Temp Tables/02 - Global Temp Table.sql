CREATE TABLE ##EmployeesTemp2(
	EmployeeId INT,
	Name VARCHAR(100),
	Department VARCHAR(50)
);

-- Insert a records into the #EmployeesTemp table
INSERT INTO ##EmployeesTemp2 (EmployeeId, Name, Department)
VALUES (10, 'Mohammed', 'Marketing');

INSERT INTO ##EmployeesTemp2 (EmployeeId, Name, Department)
VALUES (11, 'Ali', 'Sales');

-- Query the table
SELECT * FROM ##EmployeesTemp2 WHERE Department = 'Sales';

-- Drop (delete) the temporary table #EmployeesTemp
-- This is a good practice to clean up, although the table would automatically be deleted
-- when the session ends
DROP TABLE ##EmployeesTemp2;