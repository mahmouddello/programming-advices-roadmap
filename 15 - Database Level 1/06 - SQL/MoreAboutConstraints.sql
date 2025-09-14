CREATE DATABASE MoreAboutConstraints;

USE MoreAboutConstraints;

-- Create table with primary key defined
CREATE TABLE Persons
(
	id INT NOT NULL PRIMARY KEY,
	first_name NVARCHAR(50) NOT NULL,
	last_name NVARCHAR(50) NOT NULL,
	age int
);

ALTER TABLE Persons
ADD PRIMARY KEY (id);

-- Create a table where the primary key consists of multiple columns.
CREATE TABLE Accountants
(
	id INT NOT NULL,
	card_no INT NOT NULL,
	first_name NVARCHAR(50) NOT NULL,
	last_name NVARCHAR(50) NOT NULL,
	age int
	CONSTRAINT PK_Person PRIMARY KEY (id, card_no)
);


-- Create table, and add primary key later on
CREATE TABLE Managers
(
	id INT NOT NULL,
	first_name NVARCHAR(50) NOT NULL,
	last_name NVARCHAR(50) NOT NULL,
	position NVARCHAR(50) NOT NULL
)

ALTER TABLE Managers
ADD PRIMARY KEY (id);

-- FETCH name of the constraint then drop it
SELECT * FROM INFORMATION_SCHEMA.CONSTRAINT_COLUMN_USAGE;

ALTER TABLE Persons
DROP CONSTRAINT PK__Persons__3213E83F2401ADF3;

-- FOREIGN KEY

-- Create table with pre-defined foreign key
CREATE TABLE Orders (
	OrderID int NOT NULL PRIMARY KEY,
	OrderNumber int NOT NULL,
	PersonID int FOREIGN KEY REFERENCES Persons(id)
);

--CREATE TABLE Orders (
--	OrderID int NOT NULL,
--	OrderNumber int NOT NULL
--	PersonID int,
--	PRIMARY KEY (OrderID),
--	CONSTRAINT FK_PersonOrder FOREIGN KEY (PersonID)
--	REFERENCES Persons(id)
--);

-- Add foreign key constraint after creating the table
ALTER TABLE Orders
ADD FOREIGN KEY (PersonID) REFERENCES Persons(PersonID);

-- Add a constraint and name it
ALTER TABLE Orders
ADD CONSTRAINT FK_PersonOrder
FOREIGN KEY (PersonID) REFERENCES Persons(PersonID);

-- Drop a constraint
ALTER TABLE Orders
DROP CONSTRAINT FK_PersonOrder;


-- NOT NULL Constraint : Doesn't accept null values in a specifed feilds
CREATE TABLE Teachers (
   ID int NOT NULL,
   LastName varchar(255) NOT NULL,
   FirstName varchar(255) NOT NULL,
   Age int
);

-- ADD NOT NULL VIA ALTER COLUMN
ALTER TABLE Teachers
ALTER COLUMN Age int NOT NULL;

-- DEFAULT Constraint

CREATE DATABASE DB3;

USE DB3;

CREATE TABLE Persons (
   ID int NOT NULL,
   LastName varchar(255) NOT NULL,
   FirstName varchar(255),
   Age int,
   City varchar(255) DEFAULT 'Amman'
);

INSERT INTO Persons
VALUES
(1, 'Dello', 'Mahmoud', 22, 'Istanbul'),
(2, 'Dello', 'Anas', 53, 'Idlib'),
(3, 'Abu-Hadhoud', 'Mohammed', 45, DEFAULT);

SELECT * FROM Persons;

CREATE TABLE Orders (
   ID int NOT NULL,
   OrderNumber int NOT NULL,
   OrderDate date DEFAULT GETDATE()
);

INSERT INTO Orders
VALUES
(1, 125, DEFAULT);

SELECT * FROM Orders;

-- CHECK Constraint

CREATE TABLE Engineers (
   ID int NOT NULL,
   LastName varchar(255) NOT NULL,
   FirstName varchar(255),
   Age int CHECK (Age>=18)
);

-- Named Constraint
CREATE TABLE Engineers (
   ID int NOT NULL,
   LastName varchar(255) NOT NULL,
   FirstName varchar(255),
   Age int,
   City varchar(255),
   CONSTRAINT CHK_Person CHECK (Age>=18 AND City='Amman')
);

DROP TABLE IF EXISTS Lawyers;
GO

SELECT name 
FROM sys.key_constraints 
WHERE parent_object_id = OBJECT_ID('Lawyers');

-- Then drop it
ALTER TABLE Lawyers DROP CONSTRAINT UQ__Lawyers__A9D10534A9403EB6;  -- use the real name

CREATE TABLE Lawyers (
   ID INT PRIMARY KEY IDENTITY(1,1),    -- Always unique
   LastName VARCHAR(255) NOT NULL,
   FirstName VARCHAR(255),
   Age INT,
   Email VARCHAR(255)             -- Allows multiple NULLs
);

CREATE UNIQUE NONCLUSTERED INDEX idx_col1
ON dbo.Lawyers(Email)
WHERE Email IS NOT NULL;

-- Multiple NULL emails → works fine
INSERT INTO Lawyers (LastName, FirstName, Age, Email) VALUES ('Smith', 'John', 30, NULL);
INSERT INTO Lawyers (LastName, FirstName, Age, Email) VALUES ('Doe', 'Jane', 25, NULL);
INSERT INTO Lawyers (LastName, FirstName, Age, Email) VALUES ('Ali', 'Omar', 40, 'ali@example.com');


ALTER TABLE Lawyers
ALTER COLUMN ID INT NULL;