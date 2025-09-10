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

-- ORDER BY Statement
SELECT * FROM Employees
WHERE DepartmentID = 1;

SELECT ID, FirstName, LastName FROM Employees
WHERE DepartmentID = 1
ORDER BY FirstName; -- ASC by default

SELECT ID, FirstName, LastName FROM Employees
WHERE DepartmentID = 1
ORDER BY FirstName DESC;

SELECT ID, FirstName, LastName, MonthlySalary FROM Employees
WHERE DepartmentID = 1
ORDER BY MonthlySalary ASC;

SELECT ID, FirstName, LastName, MonthlySalary FROM Employees
WHERE DepartmentID = 1
ORDER BY MonthlySalary DESC;

SELECT ID, FirstName, LastName, MonthlySalary FROM Employees
WHERE DepartmentID = 1
ORDER BY FirstName, MonthlySalary;

SELECT ID, FirstName, LastName, MonthlySalary FROM Employees
WHERE DepartmentID = 1
ORDER BY FirstName ASC, MonthlySalary DESC;

-- SELECT TOP Statement

SELECT TOP 5 * FROM Employees;

SELECT TOP 10 PERCENT * FROM Employees;

SELECT MonthlySalary FROM Employees
ORDER BY MonthlySalary DESC;

SELECT DISTINCT MonthlySalary FROM Employees
ORDER BY MonthlySalary DESC;

SELECT DISTINCT TOP 3 MonthlySalary FROM Employees
ORDER BY MonthlySalary DESC;

-- Persons with 3 heighest salaries
SELECT ID, FirstName, LastName, MonthlySalary FROM Employees
WHERE MonthlySalary IN
(
	SELECT DISTINCT TOP 3 MonthlySalary FROM Employees
	ORDER BY MonthlySalary DESC
)
ORDER BY MonthlySalary DESC;

-- Persons with 3 lowest salaries
SELECT ID, FirstName, LastName, MonthlySalary FROM Employees
WHERE MonthlySalary IN
(
	SELECT DISTINCT TOP 3 MonthlySalary FROM Employees
	ORDER BY MonthlySalary ASC
)
ORDER BY MonthlySalary ASC;

-- SELECT AS STATEMENT

Select A= 5 * 4 , B= 6/2;

Select A= 5 * 4 , B= 6/2 FROM Employees;

Select ID, FirstName,  A = MonthlySalary/2 from employees;

Select ID, FirstName, MonthlySalary/2 AS A from employees;

Select ID, FirstName + ' ' + LastName as FullName From Employees;

Select ID, FullName = FirstName + ' ' + LastName  From Employees;

SELECT ID, FirstName , MonthlySalary , YealySalary = MonthlySalary * 12  from employees;

SELECT ID, FirstName , MonthlySalary , MonthlySalary * 12 AS YearlySalary  from employees;

SELECT ID, FirstName , MonthlySalary , YealySalary = MonthlySalary* 12 , BonusAmount= MonthlySalary * BonusPerc  from employees;

select Today = getDate();
select GETDATE() As Today;

select ID, FullName= FirstName + ' ' + LastName, Age = DATEDIFF(Year , DateOfBirth ,getDate()) from Employees; -- Age in years

Select YearOfWorks = DATEDIFF(YEAR ,Employees.HireDate ,getDate()) ,*From Employees
Where ExitDate Is Null And DATEDIFF(YEAR ,HireDate ,getDate())in
(
Select Distinct Top 3 YearOfWorks = DATEDIFF(YEAR ,HireDate ,getDate()) From Employees
Where ExitDate Is Null
Order By YearOfWorks Desc
)
Order By YearOfWorks Desc;

SELECT ID, FirstName + ' ' + LastName AS FullName, DATEDIFF(YEAR, HireDate, ISNULL(ExitDate, GETDATE())) AS YearsOfWork
From Employees
ORDER BY YearsOfWork DESC;

SELECT * FROM Employees WHERE ID = 1201;

-- BETWEEN Operator

SELECT * FROM Employees
WHERE MonthlySalary >= 500 AND MonthlySalary <= 1000;

SELECT * FROM Employees
WHERE MonthlySalary BETWEEN 500 AND 1000;

SELECT
* FROM (
	SELECT FirstName, LastName, DATEDIFF(YEAR, DateOfBirth, GETDATE()) AS Age
	FROM Employees
) AS EmployeesWithAge
WHERE Age BETWEEN 30 AND 40;

-- SQL Aggregate Functions

SELECT TotalCount=Count(MonthlySalary), 
	   TotalSum=Sum(MonthlySalary),
	   Average=Avg(MonthlySalary),
	   MinSalary=Min(MonthlySalary),
	   MaxSalary=Max(MonthlySalary) 
	   
	   FROM Employees;



SELECT  TotalCount=Count(MonthlySalary), 
	   TotalSum=Sum(MonthlySalary),
	   Average=Avg(MonthlySalary),
	   MinSalary=Min(MonthlySalary),
	   MaxSalary=Max(MonthlySalary) 
	   
	   FROM Employees WHERE DepartmentID=1
	   
	   
select * from employees;

select TotalEmployees = count (ID) from Employees;

--count function only counts the not null values.
select ResignedEmployees= count(ExitDate)  from employees;

-- GROUP BY
select  TotalCount=Count(MonthlySalary), 
	   TotalSum=Sum(MonthlySalary),
	   Average=Avg(MonthlySalary),
	   MinSalary=Min(MonthlySalary),
	   MaxSalary=Max(MonthlySalary) 
	   
	   from Employees where DepartmentID=3
	   

select DepartmentID, TotalCount=Count(MonthlySalary), 
	   TotalSum=Sum(MonthlySalary),
	   Average=Avg(MonthlySalary),
	   MinSalary=Min(MonthlySalary),
	   MaxSalary=Max(MonthlySalary) 
	   
	   from Employees
       Group By DepartmentID
	   order by DepartmentID;

-- HAVING Statment
--Having is the where satement for group by
select DepartmentID, TotalCount=Count(MonthlySalary), 
	   TotalSum=Sum(MonthlySalary),
	   Average=Avg(MonthlySalary),
	   MinSalary=Min(MonthlySalary),
	   MaxSalary=Max(MonthlySalary) 

	   from Employees
       Group By DepartmentID
	  having Count(MonthlySalary) > 100

-- Same solution without having :-)
select * from 
(

   select DepartmentID, TotalCount=Count(MonthlySalary), 
	   TotalSum=Sum(MonthlySalary),
	   Average=Avg(MonthlySalary),
	   MinSalary=Min(MonthlySalary),
	   MaxSalary=Max(MonthlySalary) 
	   
	   from Employees
	
       Group By DepartmentID
	  
) R1

where R1.TotalCount> 100;

-- LIKE Statement

--Finds any values that start with "a"
select ID, FirstName from Employees
where FirstName like 'a%';

--Finds any values that end with "a"
select ID, FirstName from Employees
where FirstName like '%a';

--Finds any values that have "tell" in any position
select ID, FirstName from Employees
where FirstName like '%tell%';

--	Finds any values that start with "a" and ends with "a"
select ID, FirstName from Employees
where FirstName like 'a%a';

--Finds any values that have "a" in the second position
select ID, FirstName from Employees
where FirstName like '_a%';

--Finds any values that have "a" in the third position
select ID, FirstName from Employees
where FirstName like '__a%';


--Finds any values that start with "a" and are at least 3 characters in length
select ID, FirstName from Employees
where FirstName like 'a__%';

--Finds any values that start with "a" and are at least 4 characters in length
select ID, FirstName from Employees
where FirstName like 'a___%';


--Finds any values that start with "a" or "b"
select ID, FirstName from Employees
where FirstName like 'a%' or FirstName like 'b%' ;

-- WILDCARDS

--Execute these satatements to update data
Update Employees 
set FirstName ='Mohammed' , LastName='Abu-Hadhoud'
where ID= 285;


Update Employees 
set FirstName ='Mohammad' , LastName='Maher'
where ID= 286;

select ID, FirstName, LastName from Employees
Where firstName = 'Mohammed' or FirstName ='Mohammad'; 


-- will search form Mohammed or Mohammad
select ID, FirstName, LastName from Employees
Where firstName like 'Mohamm[ae]d';

--You can use Not 
select ID, FirstName, LastName from Employees
Where firstName Not like 'Mohamm[ae]d';

--------------------

select ID, FirstName, LastName from Employees
Where firstName like 'a%' or firstName like 'b%' or firstName like 'c%';


-- search for all employees that their first name start with a or b or c
select ID, FirstName, LastName from Employees
Where firstName like '[abc]%';


---------------------------------
-- search for all employees that their first name start with any letter from a to l
select ID, FirstName, LastName from Employees
Where firstName like '[a-l]%';

---------------------------------
-- search for all employees that their first name start with any letter from a to l
select ID, FirstName, LastName from Employees
Where firstName like '[a-l]%'
ORDER BY FirstName ASC;
---------------------------------


--1- first name Is exactly 5 characters long, ends with a vowel
Select E.FirstName
From Employees E
Where FirstName Like '____[aeiou]';

--2- First names that Begin with S or T, and have 6 total letters

Select E.FirstName
From Employees E
Where FirstName Like '[ST]_____';

--3- Last names where the second letter is a, and it ends with n

Select ID, FirstName, LastName
From Employees
Where LastName like '_a%n'

--4- Last names that Start with 'M', and the second letter is a vowel

Select ID, FirstName, LastName
From Employees
Where LastName like 'M[aeiou]%'