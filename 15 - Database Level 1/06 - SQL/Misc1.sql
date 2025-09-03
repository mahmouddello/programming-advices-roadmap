USE DB2;

IF NOT EXISTS (SELECT * FROM sys.databases WHERE name = 'Departments')
	BEGIN
	CREATE TABLE Departments (
		id INT IDENTITY(1,1) PRIMARY KEY,
		name NVARCHAR(200) NOT NULL
	);
	END

SELECT * FROM Departments;

-- Not Allowed IDENTITY_INSERT is ON.
INSERT INTO Departments
VALUES
(5, 'HR');

INSERT INTO Departments
VALUES
('HR');

print @@identity; --last id (T-SQL)

DELETE FROM Departments;

TRUNCATE TABLE Departments;

INSERT INTO Departments
VALUES
('HR');

-- Foreign Keys
IF NOT EXISTS (SELECT * FROM sys.databases WHERE name = 'Customers')
	BEGIN
	CREATE TABLE Customers (
		id INT IDENTITY(1,1) PRIMARY KEY,
		first_name NVARCHAR(100) NOT NULL,
		last_name NVARCHAR(100) NOT NULL,
		age TINYINT NOT NULL,
		country NVARCHAR(20) NOT NULL,
	);
	END

IF NOT EXISTS (SELECT * FROM sys.databases WHERE name = 'Orders')
	BEGIN
	CREATE TABLE Orders (
		id INT IDENTITY(1,1) PRIMARY KEY,
		item NVARCHAR(200) NOT NULL,
		amount INT NOT NULL,
		customer_id INT NOT NULL REFERENCES Customers(id)
	);
	END

--<Adding a foreign key constraint to a field after creating it>--
--ALTER TABLE Orders
--ADD FOREIGN KEY (customer_id) REFERENCES Customers(id);
