use C21_DB1;

--Normal way
SELECT Name,subject, (SELECT  AVG(Grade) FROM Students WHERE Subject = T.Subject ) AS AverageGrade
FROM Teachers T;

-- Using scalar function
SELECT Name,subject, dbo.GetAverageGrade(Subject)  AS AverageGrade
FROM Teachers;


