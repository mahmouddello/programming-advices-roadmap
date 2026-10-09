USE C21_DB1;

-- 01 - Tables and Data
CREATE TABLE Teachers (
    TeacherID INT PRIMARY KEY,
    Name NVARCHAR(50),
    Subject NVARCHAR(50)
);


INSERT INTO Teachers (TeacherID, Name, Subject) VALUES
(1, 'John Smith', 'Math'),
(2, 'Jane Doe', 'Science'),
(3, 'Emily Johnson', 'English'),
(4, 'Mark Brown', 'History'),
(5, 'Sarah Davis', 'Music');

