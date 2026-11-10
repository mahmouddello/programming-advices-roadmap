USE C21_DB1;

ALTER TABLE Students
ADD IsActive BIT DEFAULT 1;

-- Setting all old records to active
UPDATE Students
SET IsActive = 1;


DROP TRIGGER IF EXISTS TR_InsteadOfDeleteStudent;
GO

GO
CREATE TRIGGER TR_InsteadOfDeleteStudent ON Students
INSTEAD OF DELETE
AS
BEGIN
	-- Marking the record as inactive instead of deleting
	UPDATE S
	SET IsActive = 0
	FROM Students AS S
	INNER JOIN deleted AS d ON S.StudentID = d.StudentID;
END

-- Before
SELECT * FROM Students;

-- Delete one student (sets as inactive)
DELETE FROM Students WHERE StudentID = 4;

-- After
SELECT * FROM Students;