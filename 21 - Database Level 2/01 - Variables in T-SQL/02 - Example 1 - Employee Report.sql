
use C21_DB1;

-- Example: Employee Report Generation in T-SQL
-- This script demonstrates the declaration, initialization, and use of variables in T-SQL.
-- It generates a report for a specific department, including the department name, reporting period, and total employees hired within that period.
-- This comprehensive script gives a practical insight into how variables can be effectively used in T-SQL to create dynamic and flexible SQL scripts.


-- Step 1: Declare variables
DECLARE @DepartmentID INT; -- Variable for department ID
DECLARE @StartDate DATE; -- Variable for start date
DECLARE @EndDate DATE; -- Variable for end date
DECLARE @TotalEmployees INT; -- Variable to hold the total number of employees
DECLARE @DepartmentName VARCHAR(50); -- Variable for department name

-- Step 2: Initialize variables
SET @DepartmentID = 3; -- Assign a specific department ID
SET @StartDate = '2023-01-01'; -- Set start date for the report
SET @EndDate = '2023-12-31'; -- Set end date for the report

-- Step 3: Retrieve department name based on department ID
SELECT @DepartmentName = Name FROM Departments WHERE DepartmentID = @DepartmentID;

-- Step 4: Calculate the total number of employees in the specified department
SELECT @TotalEmployees = COUNT(*) 
FROM Employees 
WHERE DepartmentID = @DepartmentID 
AND HireDate BETWEEN @StartDate AND @EndDate;

-- Step 5: Print the report
PRINT 'Department Report';
PRINT 'Department Name: ' + @DepartmentName;
PRINT 'Reporting Period: ' + CAST(@StartDate AS VARCHAR) + ' to ' + CAST(@EndDate AS VARCHAR);
PRINT 'Total Employees Hired in ' + CAST(YEAR(@StartDate) AS VARCHAR) + ': ' + CAST(@TotalEmployees AS VARCHAR);
