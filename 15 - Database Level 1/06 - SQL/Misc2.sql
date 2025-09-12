USE Shop_Database

select X='yes'
where  exists 
   ( 
	select * from Orders
	where customerID= 3 and Amount < 600
	)

select X='yes'
where  exists 
   ( 
	select * from Orders
	where customerID= 3 and Amount < 300
	)

select * from Customers T1
where 
  exists 
   ( 
	select * from Orders
	where customerID= T1.CustomerID and Amount < 600
	)

--More optimized and faster
select * from Customers T1
where 
  exists 
   ( 
	select top 1 * from Orders
	where customerID= T1.CustomerID and Amount < 600
	)


--More optimized and faster
select * from Customers T1
where 
  exists 
   ( 
	select top 1 R='Y'  from Orders
	where customerID= T1.CustomerID and Amount < 600
	)

use HR_Database;

select * from ActiveEmployees

select * from ResignedEmployees


select * from ActiveEmployees
Union
select * from ResignedEmployees

--this will remove the redundancy from the resultset (distinct results only)
select * from Departments
union 
select * from Departments;

--this will append data regardeless of any redundancy
select * from Departments
union ALL
select * from Departments;

-- CASE

select ID, FirstName, LastName, GenderTitle =
CASE
    WHEN Gender='M' THEN 'Male'
    WHEN Gender='F' THEN 'Female'
    ELSE 'Unknown'
END

from Employees

select ID, FirstName, LastName,  GenderTitle =
CASE
    WHEN Gender='M' THEN 'Male'
    WHEN Gender='F' THEN 'Female'
    ELSE 'Unknown'
END,
Status =
CASE
    WHEN ExitDate is null THEN 'Active'
    WHEN Gender is Not null THEN 'Resigned'
END
from Employees

select ID, FirstName, LastName,MonthlySalary,

NewSalaryToBe =
CASE
    WHEN Gender='M' THEN MonthlySalary * 1.1
    WHEN Gender='F' THEN MonthlySalary * 1.15
   
END
from Employees

