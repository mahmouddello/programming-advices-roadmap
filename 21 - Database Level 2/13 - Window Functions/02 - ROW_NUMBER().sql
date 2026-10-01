USE C21_DB1;

/*
    This query assigns a unique row number to each student, 
    ordered by their grade in descending order.
    The RowNum column will show this unique number.
*/
SELECT 
    StudentID, 
    Name, 
    Subject, 
    Grade,
    ROW_NUMBER() OVER (ORDER BY Grade DESC) AS RowNum
FROM 
    Students;
