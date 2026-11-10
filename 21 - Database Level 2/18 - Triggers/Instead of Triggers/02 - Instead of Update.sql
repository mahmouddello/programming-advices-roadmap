USE C21_DB1;

-- Step 1: Creating the Tables

-- PersonalInfo Table
CREATE TABLE PersonalInfo (
    StudentID INT PRIMARY KEY,
    Name NVARCHAR(100),
    Address NVARCHAR(255)
);

-- AcademicInfo Table
CREATE TABLE AcademicInfo (
    StudentID INT PRIMARY KEY,
    Course NVARCHAR(100),
    Grade INT,
    FOREIGN KEY (StudentID) REFERENCES PersonalInfo(StudentID)
);

-- Step 2: Inserting Sample Data

INSERT INTO PersonalInfo (StudentID, Name, Address) VALUES
(1, 'John Doe', '123 Main St'),
(2, 'Jane Smith', '456 Oak Ave');

INSERT INTO AcademicInfo (StudentID, Course, Grade) VALUES
(1, 'Computer Science', 90),
(2, 'Mathematics', 85);


-- Step 3: Creating the View
GO
CREATE VIEW StudentView AS
SELECT p.StudentID, p.Name, p.Address, a.Course, a.Grade
FROM PersonalInfo AS p
INNER JOIN AcademicInfo as a ON p.StudentID = a.StudentID;

SELECT * FROM StudentView;

-- Before step 4, let's try to update on view directly
UPDATE StudentView
SET Address = 'Qatar, Lusail', Grade = 100
WHERE StudentID = 1;

/*
	Error: Msg 4405, Level 16, State 1, Line 41
	View or function 'StudentView' is not updatable because the modification affects multiple base tables.
*/ 

-- Delete
DELETE FROM StudentView
WHERE StudentID = 1

/*
	Error: Msg 4405, Level 16, State 1, Line 41
	View or function 'StudentView' is not updatable because the modification affects multiple base tables.
*/

/*
	Notice that we cannot perform DML queries that affects multiple tables on views,
	but can perform them when only one table gets affected.
	To solve this, we can "override" DML statements with INSTEAD OF triggers as we can see in M18L3F3
*/

-- Creating the trigger
GO
CREATE TRIGGER trg_UpdateStudentView ON StudentView
INSTEAD OF UPDATE
AS
BEGIN
    -- Update PersonalInfo
    UPDATE PersonalInfo
    SET Name = I.Name, Address = I.Address
    FROM PersonalInfo
    INNER JOIN inserted I ON PersonalInfo.StudentID = I.StudentID;


    -- Update AcademicInfo
    UPDATE AcademicInfo
    SET Course = I.Course, Grade = I.Grade
    FROM AcademicInfo
    INNER JOIN inserted I ON AcademicInfo.StudentID = I.StudentID;
END;

-- Testing
UPDATE StudentView
SET Name = 'Johnathan Doe', Course = 'Biology', Grade = 92
WHERE StudentID = 1;

SELECT * FROM PersonalInfo WHERE StudentID = 1;
SELECT * FROM AcademicInfo WHERE StudentID = 1;