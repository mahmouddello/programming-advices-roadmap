
use C21_DB1;
-- Create the Students table
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    Name NVARCHAR(50),
    Subject NVARCHAR(50),
    Grade INT
);


Go

-- Insert sample data into the Students table
INSERT INTO Students (StudentID, Name, Subject, Grade)
VALUES
    (1, 'Alice', 'Math', 90),
    (2, 'Bob', 'Math', 85),
    (3, 'Charlie', 'Math', 78),
    (4, 'Dave', 'Science', 88),
    (5, 'Emma', 'Science', 92),
    (6, 'Fiona', 'Science', 84),
    (7, 'Grace', 'English', 75),
    (8, 'Henry', 'English', 80),
    (9, 'Isabella', 'English', 88);



