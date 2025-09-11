USE Shop_Database;


-- Join and Inner Join are the same

SELECT * FROM Customers;

SELECT * FROM Orders;


SELECT Customers.CustomerID, Customers.Name, Orders.Amount
FROM Customers 
JOIN Orders 
ON Customers.CustomerID = Orders.CustomerID;


SELECT Customers.CustomerID, Customers.Name, Orders.Amount
FROM Customers 
Inner JOIN Orders 
ON Customers.CustomerID = Orders.CustomerID;

-- Inner join with WHERE Clause
SELECT Customers.CustomerID, Customers.Name, Orders.amount
FROM Customers
INNER JOIN Orders
ON Customers.CustomerID = Orders.CustomerID
WHERE Orders.amount >= 500;


--This code for HR_Database
USE HR_Database;

--Inner Join two Tables
SELECT Employees.ID, Employees.FirstName, Employees.LastName, Departments.Name as DeptName
FROM Employees INNER JOIN
Departments ON Employees.DepartmentID = Departments.ID

--Inner Join Three Tables with where
SELECT Employees.ID, Employees.FirstName, Employees.LastName, Departments.Name as DeptName, Countries.Name AS CountryName
FROM Employees INNER JOIN
Departments ON Employees.DepartmentID = Departments.ID INNER JOIN
Countries ON Employees.CountryID = Countries.ID
WHERE Countries.Name = 'USA';

-- EX1
SELECT CountryID, Countries.Name ,TotalPaidSalary = SUM(MonthlySalary) 
FROM Employees
INNER JOIN Countries ON CountryID = Countries.ID
GROUP BY CountryID, Countries.Name;

SELECT Countries.Name as CName, SUM(Employees.MonthlySalary) AS TotalPaidSalary
FROM Employees
INNER JOIN Countries
    ON Countries.ID = Employees.CountryID
GROUP BY Countries.Name;

-- EX2
SELECT Departments.Name as DeptName, COUNT(Employees.ID) AS TotalEmployees
FROM Employees
INNER JOIN Departments ON Employees.DepartmentID = Departments.ID
GROUP BY Departments.Name;

-- EX3
SELECT Departments.Name as DeptName, AVG(Employees.MonthlySalary) AS AvergeSalaryPerDepartment
FROM Employees
INNER JOIN Departments ON Employees.DepartmentID = Departments.ID
GROUP BY Departments.Name;

-- EX4
SELECT Countries.Name AS Country, COUNT(Employees.ID) AS HighSalary
FROM Employees
INNER JOIN Countries ON Countries.ID = Employees.CountryID
WHERE Employees.MonthlySalary >= 1000
GROUP BY Countries.Name;

-- Write a SQL query to list the first name, last name, country name, and salary of employees from the same country as the employee with ID 5
SELECT Employees.FirstName, Employees.LastName, Countries.Name, Employees.MonthlySalary
FROM Employees INNER JOIN
Countries ON Employees.CountryID = Countries.ID
Where Countries.Name = 'USA'; 

SELECT E.FirstName, E.LastName, E.MonthlySalary, D.Name
FROM Employees E
INNER JOIN Departments D ON E.DepartmentID = D.ID AND E.MonthlySalary >= 2000;

-- Write a SQL query to retrieve the first name, last name, and department name of employees who are in the "HR" department.
SELECT E.FirstName, E.LastName, D.Name
FROM Employees E
INNER JOIN Departments D ON E.DepartmentID = D.ID AND D.Name = 'HR';

-- Write a SQL query to list the first name, last name, birth date, and country name of employees who were born after January 1, 1990.
SELECT E.FirstName, E.LastName, E.DateOfBirth, C.Name as Country
FROM Employees E
INNER JOIN Countries C ON E.CountryID = C.ID AND DateOfBirth > '1-1-1990';

-- Write a SQL query to find the first name, last name, country name, and department name of employees who have an exit date within the year 2023.
SELECT E.FirstName, E.LastName, E.DateOfBirth, E.ExitDate ,C.Name as Country, D.Name as DeptName
FROM Employees E
INNER JOIN Countries C ON E.CountryID = C.ID
INNER JOIN Departments D ON E.DepartmentID = D.ID
WHERE YEAR(E.ExitDate) = 2023;

USE Shop_Database;

--Left Join and Left Outer Join are the same.

--Left Join: gets all data from table customers and only matched data from table orders
SELECT Customers.CustomerID, Customers.Name, Orders.Amount
FROM Customers 
Left JOIN Orders 
ON Customers.CustomerID = Orders.CustomerID;


SELECT Customers.CustomerID, Customers.Name, Orders.Amount
FROM Customers 
Left Outer JOIN Orders 
ON Customers.CustomerID = Orders.CustomerID;

-- RIGHT JOIN AND FULL OUTER JOIN
--Inner Join
SELECT        Customers.CustomerID, Customers.Name, Orders.Amount
FROM            Customers INNER JOIN
                         Orders ON Customers.CustomerID = Orders.CustomerID
--Left Join
SELECT        Customers.CustomerID, Customers.Name, Orders.Amount
FROM            Customers LEFT OUTER JOIN
                         Orders ON Customers.CustomerID = Orders.CustomerID
--Right Join
SELECT        Customers.CustomerID, Customers.Name, Orders.Amount
FROM            Customers RIGHT OUTER JOIN
                         Orders ON Customers.CustomerID = Orders.CustomerID
--Full Join
SELECT        Customers.CustomerID, Customers.Name, Orders.Amount
FROM            Customers FULL OUTER JOIN
                         Orders ON Customers.CustomerID = Orders.CustomerID

