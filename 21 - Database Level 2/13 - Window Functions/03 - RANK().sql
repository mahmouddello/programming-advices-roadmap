USE C21_DB1;

SELECT 
    StudentID, 
    Name, 
    Subject, 
    Grade,
    RANK() OVER (ORDER BY Grade DESC) AS GradeRank
FROM 
    Students;

SELECT *, RANK() OVER (ORDER BY [Subject] ASC) AS SubjectRank FROM Students;