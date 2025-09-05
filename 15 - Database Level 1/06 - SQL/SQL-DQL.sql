RESTORE DATABASE HR_Database
FROM DISK = 'C:\HR_Database.bak';

use HR_Database;

-- Fix Diagrams
EXEC sp_changedbowner 'sa';

-- SELECT STATEMENT

SELECT * FROM Employees;

SELECT Employees.* FROM Employees; --  = SELECT * FROM Employee, this will be used at joins

SELECT ID, FirstName, LastName, MonthlySalary FROM Employees;

SELECT ID, FirstName, DateOfBirth FROM Employees;

SELECT * FROM Departments;

SELECT * FROM Countries;

-- SELECT STATEMENT

-- SELECT DISTINCT

SELECT DepartmentID FROM Employees;

SELECT Distinct  DepartmentID FROM Employees;


SELECT FirstName FROM Employees;

SELECT Distinct  FirstName FROM Employees;


SELECT FirstName, DepartmentID FROM Employees;

SELECT distinct FirstName, DepartmentID FROM Employees;

-- SELECT DISTINCT

-- FILTERS (WHERE, AND, NOT, OR)
SELECT * FROM Employees
WHERE Gendor = 'f';

SELECT * FROM Employees
WHERE MonthlySalary <= 500;

SELECT * FROM Employees
WHERE NOT MonthlySalary <= 500;

SELECT * FROM Employees
WHERE MonthlySalary <= 500 AND Gendor = 'f';

SELECT * FROM Employees
WHERE CountryID = 1;

SELECT * FROM Employees
WHERE NOT CountryID = 1;

SELECT * FROM Employees
WHERE CountryID <> 1;

SELECT * FROM Employees
WHERE DepartmentID = 1 OR DepartmentID = 2;

SELECT * FROM Employees
WHERE DepartmentID = 1 AND DepartmentID = 2;

SELECT * FROM Employees
WHERE ExitDate is Null;

SELECT * FROM Employees
WHERE ExitDate is NOT Null;

-- IN STATEMENT (Shorthand OR)

SELECT * FROM Employees
WHERE DepartmentID=1 Or DepartmentID=2;


SELECT * FROM Employees
WHERE DepartmentID=1 Or DepartmentID=2 or DepartmentID=7;


SELECT * FROM Employees
WHERE DepartmentID=1 Or DepartmentID=2 or DepartmentID=5 or DepartmentID=7;

SELECT * FROM Employees
WHERE DepartmentID IN (1,2,5,7);

SELECT * FROM Employees
WHERE FirstName IN ('Jacob','Brooks','Harper');

SELECT Departments.Name FROM Departments 
WHERE 
Departments.ID IN ( SELECT DepartmentID FROM Employees WHERE MonthlySalary <=210 );

SELECT Departments.Name FROM Departments 
WHERE 
Departments.ID not IN ( SELECT DepartmentID FROM Employees WHERE MonthlySalary <=210 );
