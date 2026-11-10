USE C21_DB1;

-- Creating the after delete trigger
GO
CREATE TRIGGER trg_AfterDeleteStudent ON Students
AFTER DELETE
AS
BEGIN
    INSERT INTO StudentDeleteLog(StudentID, Name, Subject, Grade)
    SELECT StudentID, Name, Subject, Grade FROM deleted;
END;

-- Assuming there is a student with StudentID = 110 in the Students table

-- Deleting a student
DELETE FROM Students WHERE StudentID = 110;


-- Checking the delete log table
SELECT * FROM StudentDeleteLog;