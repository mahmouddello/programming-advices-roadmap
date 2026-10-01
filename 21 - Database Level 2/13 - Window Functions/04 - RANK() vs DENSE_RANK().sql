USE C21_DB1;

-- Using Ranks
SELECT 
    StudentID, 
    Name, 
    Grade,
    RANK() OVER (ORDER BY Grade DESC) AS GradeRank
FROM 
    Students;

-- Using Dense_Rank
SELECT 
    StudentID, 
    Name, 
    Grade,
    DENSE_RANK() OVER (ORDER BY Grade DESC) AS GradeRank
FROM 
    Students;