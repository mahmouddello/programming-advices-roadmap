USE C21_DB1;

SELECT * FROM StudentView;

INSERT INTO 
StudentView 
VALUES
(3, 'Mahmoud Dello', 'Turkey', 'C#', 75);

/*
Msg 4405, Level 16, State 1, Line 5
View or function 'StudentView' is not updatable because the modification affects multiple base tables.
*/

-- Creating Instead of Insert Trigger
GO
CREATE TRIGGER trg_InsertStudentView ON StudentView
INSTEAD OF INSERT
AS
BEGIN
	 -- Insert into PersonalInfo
    INSERT INTO PersonalInfo (StudentID, Name, Address)
    SELECT StudentID, Name, Address FROM inserted;


    -- Insert into AcademicInfo
    INSERT INTO AcademicInfo (StudentID, Course, Grade)
    SELECT StudentID, Course, Grade FROM inserted;
END

INSERT INTO StudentView VALUES
(3, 'Mahmoud Dello', 'Turkey', 'C#', 75);

SELECT * FROM PersonalInfo WHERE StudentID = 3;
SELECT * FROM AcademicInfo WHERE StudentID = 3;
