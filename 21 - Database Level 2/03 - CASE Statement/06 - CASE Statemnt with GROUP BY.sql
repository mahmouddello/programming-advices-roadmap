USE C21_DB1;

SELECT 
	PerformanceCategory,
	COUNT(*) AS NumberOfEmployees,
	AVG(Salary) AS AverageSalary
FROM
	(SELECT 
		Name,
		Salary,
		CASE 
			WHEN PerformanceRating >= 80 THEN 'High'
			WHEN PerformanceRating >= 60 THEN 'Medium'
			ELSE 'Low'
		END AS PerformanceCategory
	FROM
		Employees2) AS PerfomanceTable

GROUP BY
	PerformanceCategory;