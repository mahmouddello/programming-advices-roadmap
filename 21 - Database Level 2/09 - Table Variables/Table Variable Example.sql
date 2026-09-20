
-- Declare a table variable named @EmployeesTable
-- This table variable is stored in memory 
--  and is scoped to the batch, stored procedure, or function
DECLARE @EmployeesTable TABLE (
	EmployeeId INT,
	Name VARCHAR(100),
	Department VARCHAR(50)
);

-- Insert records into the @EmployeesTable table variable
INSERT INTO @EmployeesTable (EmployeeId, Name, Department)
VALUES (10, 'Mohammed', 'Marketing');

INSERT INTO @EmployeesTable (EmployeeId, Name, Department)
VALUES (11, 'Ali', 'Sales');

-- Query the table variable

SELECT * FROM @EmployeesTable WHERE Department = 'Sales';

-- No need to drop the table variable
-- The table variable @EmployeesTable automatically goes out of scope and is deallocated
-- at the end of the execution of the batch, stored procedure, or function
