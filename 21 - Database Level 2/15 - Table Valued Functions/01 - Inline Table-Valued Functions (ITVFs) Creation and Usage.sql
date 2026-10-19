USE C21_DB1;

-- 1) Create Students table
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    Name NVARCHAR(50),
    Subject NVARCHAR(50),
    Grade INT
);

GO
-- 2) Create ITVF
CREATE FUNCTION dbo.GetStudentsBySubject
(
    @Subject NVARCHAR(50)
)
RETURNS TABLE
AS
RETURN
(
    SELECT *
    FROM Students
    WHERE Subject = @Subject
)

GO
-- 3) Usage of ITVF
SELECT * FROM dbo.GetStudentsBySubject('Math');