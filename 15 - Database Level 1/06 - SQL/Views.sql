USE HR_Database;

CREATE VIEW ActiveEmployees AS
SELECT * FROM Employees 
WHERE ExitDate IS NULL;

SELECT * FROM ActiveEmployees;

CREATE VIEW ResignedEmployees AS
SELECT * FROM Employees 
WHERE ExitDate IS NOT NULL;

SELECT * FROM ResignedEmployees;

exec sp_rename 'employees.Gendor', 'Gender', 'COLUMN';

CREATE VIEW EmployeeShortDetails AS
SELECT ID, FirstName, LastName, Gender
FROM Employees;

SELECT * FROM EmployeeShortDetails;