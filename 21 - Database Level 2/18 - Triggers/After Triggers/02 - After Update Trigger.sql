USE C21_DB1;

-- Creating the trigger
GO
CREATE TRIGGER trg_AfterUpdateStudent ON Students
AFTER UPDATE
AS
BEGIN
	IF UPDATE(Grade)
	BEGIN
		INSERT INTO StudentUpdateLog (StudentID, OldGrade, NewGrade)
		SELECT i.StudentID, d.Grade AS OldGrade, i.Grade AS NewGrade
		FROM inserted AS i
		INNER JOIN deleted AS d ON i.StudentID = d.StudentID;
	END
END

-- Testing the trigger
UPDATE Students
SET Grade = 90
WHERE StudentID = 1;

-- Checking the log table
SELECT * FROM StudentUpdateLog;
