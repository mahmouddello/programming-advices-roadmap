USE C21_DB1;

SELECT
    StudentID,
    Name,
    LAG(Grade, 1) OVER (ORDER BY Grade DESC) AS PreviousGrade,
    Grade,
    LEAD(Grade, 1) OVER (ORDER BY Grade DESC) AS NextGrade
FROM
    Students
ORDER BY Grade DESC;