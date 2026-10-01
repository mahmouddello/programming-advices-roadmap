USE C21_DB1;

SELECT
	StudentID,
	Name,
	Subject,
	Grade,
	AVG(Grade) OVER (PARTITION BY Subject) AS SubjectAvgGrade,
	SUM(Grade) OVER (PARTITION BY Subject) AS SubjectTotalGrade
FROM 
Students