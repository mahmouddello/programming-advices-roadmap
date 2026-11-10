USE C21_DB1;

-- Assuming the Students table is already created
-- Table for logging new student entries
CREATE TABLE StudentInsertLog (
    LogID INT IDENTITY PRIMARY KEY,
    StudentID INT,
    Name NVARCHAR(50),
    Subject NVARCHAR(50),
    Grade INT,
    InsertedDateTime DATETIME DEFAULT GETDATE()
);


-- Table for logging grade updates
CREATE TABLE StudentUpdateLog (
    LogID INT IDENTITY PRIMARY KEY,
    StudentID INT,
    OldGrade INT,
    NewGrade INT,
    UpdatedDateTime DATETIME DEFAULT GETDATE()
);

-- Table for logging student deletion records
CREATE TABLE StudentDeleteLog (
    LogID INT IDENTITY PRIMARY KEY,
    StudentID INT,
    Name NVARCHAR(50),
    Subject NVARCHAR(50),
    Grade INT,
    DeletedDateTime DATETIME DEFAULT GETDATE()
);
