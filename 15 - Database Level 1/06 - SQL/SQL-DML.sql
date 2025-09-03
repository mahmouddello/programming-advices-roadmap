USE DB2;

--this will show all data in the table
SELECT * FROM Employees;


--Insert one record at a time
INSERT INTO Employees 
VALUES
(10,'Emp10','079939',1000);

--Insert one record at a time with some null values
INSERT INTO Employees 
VALUES
(11,'Emp11',null,null);


--insert multiple records at a time.
INSERT INTO Employees 
VALUES
(2,'Emp2','552221',700),
(3,'Emp3','55554',300),
(4,'Emp4','322344',400);


--insert only selected fields
INSERT INTO Employees (ID, Name)
values
(5,'Emp5');


--if you forget to insert not null filed an error will occure.
INSERT INTO Employees (ID)
values (5);


SELECT * FROM Employees;

--this will delete all records in table.
--DELETE FROM Employees;

-- this will update one filed at a time
Update Employees 
SET NAME ='Mohammed Abu-Hadhoud' 
WHERE ID=2;

-- this will update multiple fields at a time.
Update Employees 
SET NAME ='Mohammed Abu-Hadhoud' ,  Salary=5000
WHERE ID=2;

-- this will increase the salary by 200 for all employees that their salaries are less than 500
update Employees 
SET Salary = Salary + 200
WHERE  Salary < 500 ;

-- this will increase the salary by 10% for all employees that their salaries are less than or equal 1000
update Employees 
SET Salary = Salary *1.1 
WHERE  Salary <= 1000;

-- deletes employee(s) record(s) WHERE the salary is null
DELETE FROM Employees
WHERE Salary is null;

DELETE FROM Employees
WHERE ID = 4; -- deletes the employee with id 4 (if exist, otherwise SQL will say '0 rows affected')

DELETE FROM Employees
WHERE ID = 40 -- no error but no changes performed

SELECT *
INTO EmployeesCopy
FROM Employees;

SELECT * FROM EmployeesCopy;

SELECT  ID, Name
INTO EmployeesCopy2
FROM Employees;

SELECT * From EmployeesCopy2;

INSERT INTO OldPersons
SELECT * FROM Persons
WHERE Age >= 30;

SELECT * FROM OldPersons;