USE C21_DB1;

GO
CREATE TRIGGER trg_AfterInsertStudent ON Students
AFTER INSERT
AS
BEGIN
    INSERT INTO StudentInsertLog(StudentID, Name, Subject, Grade)
    SELECT StudentID, Name, Subject, Grade FROM inserted;
END;

-- Testing the trigger
-- Inserting a new student
INSERT INTO Students (StudentID, Name, Subject, Grade)
VALUES (111, 'Ahmad Abdo', 'Mathematics', 90);


-- Checking the log table
SELECT * FROM StudentInsertLog;
