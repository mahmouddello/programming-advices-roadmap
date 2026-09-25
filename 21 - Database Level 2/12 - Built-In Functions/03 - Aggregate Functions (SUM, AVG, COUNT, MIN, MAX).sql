USE C21_DB1;

-- Example: Count the number of employees in each department
SELECT Department, COUNT(*) AS EmployeeCount
FROM Employees2
GROUP BY Department;

-- Example: Calculate the total salary for each department
SELECT Department, SUM(Salary) AS TotalSalary
FROM Employees2
GROUP BY Department;

-- Example: Calculate the average performance rating for each department
SELECT Department, AVG(PerformanceRating) AS AvgPerformanceRating
FROM Employees2
GROUP BY Department;

-- Example: Find the lowest salary in the company
SELECT MIN(Salary) AS LowestSalary
FROM Employees2;

-- Example: Find the highest salary in the company
SELECT MAX(Salary) AS HighestSalary
FROM Employees2;

/*
	These are just a few examples of how you can use aggregate functions in 
	T-SQL to summarize and analyze data in your tables. 
	Aggregate functions are powerful tools for data analysis and reporting in SQL.
*/