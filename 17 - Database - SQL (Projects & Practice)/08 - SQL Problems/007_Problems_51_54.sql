USE EmployeesDB;

-- Fixes diagram issue
EXEC sp_changedbowner 'sa';

SELECT * FROM Employees;

SELECT Name FROM Employees
WHERE EmployeeID = 1;

-- Problem #51: Get all employees that have manager along with Manager's name
SELECT
	R1.*,
	(SELECT
		Employees.Name 
		FROM 
			Employees 
		WHERE 
			R1.ManagerID = Employees.EmployeeID
	) AS ManagerName
FROM
(
	SELECT 
		emp.Name,
		emp.ManagerID,
		emp.Salary
	FROM
		Employees AS emp
	WHERE 
		emp.ManagerID IS NOT NULL
) R1;

-- Programming Advices #51 (Best)
SELECT 
	Employees.Name, 
	Employees.ManagerID, 
	Employees.Salary, 
	Managers.Name AS ManagerName
FROM 
	Employees 
INNER JOIN
	Employees AS Managers ON Employees.ManagerID = Managers.EmployeeID

-- Problem #52: Get all employees that have manager or does not have manager along with Manager's name, incase no manager name show null
SELECT 
	Employees.Name, 
	Employees.ManagerID, 
	Employees.Salary, 
	Managers.Name AS ManagerName
FROM 
	Employees 
LEFT JOIN
	Employees AS Managers ON Employees.ManagerID = Managers.EmployeeID

-- Problem 53: Get all employees that have manager or does not have manager along with Manager's name,
-- incase no manager name the same employee name as manager to himself 
SELECT 
	Employees.Name, 
	Employees.ManagerID, 
	Employees.Salary, 
	ISNULL(Managers.Name, Employees.Name) AS ManagerName
FROM 
	Employees 
LEFT JOIN
	Employees AS Managers ON Employees.ManagerID = Managers.EmployeeID

-- Programming Advices #53
SELECT 
	Employees.Name, 
	Employees.ManagerID, 
	Employees.Salary, 
CASE
    WHEN Managers.Name is Null  THEN Employees.Name
    ELSE Managers.Name
END AS ManagerName
FROM
	Employees 
LEFT JOIN
	 Employees AS Managers ON Employees.ManagerID = Managers.EmployeeID

-- Problem #54: Get All Employees managed by 'Mohammed'
SELECT 
	Employees.Name, 
	Employees.ManagerID, 
	Employees.Salary, 
CASE
	WHEN Managers.Name is Null  THEN Employees.Name
	ELSE Managers.Name
END AS ManagerName
FROM
	Employees 
INNER JOIN
	 Employees AS Managers ON Employees.ManagerID = Managers.EmployeeID
WHERE
	Managers.Name = 'Mohammed'