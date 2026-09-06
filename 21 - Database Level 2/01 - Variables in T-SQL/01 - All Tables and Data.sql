Create Database C21_DB1;
Go

Use C21_DB1;


-- Create the Departments Table
CREATE TABLE Departments (
    DepartmentID INT PRIMARY KEY,
    Name VARCHAR(50)
);

-- Insert sample data into Departments
INSERT INTO Departments (DepartmentID, Name) VALUES (1, 'Human Resources');
INSERT INTO Departments (DepartmentID, Name) VALUES (2, 'Marketing');
INSERT INTO Departments (DepartmentID, Name) VALUES (3, 'Sales');
INSERT INTO Departments (DepartmentID, Name) VALUES (4, 'IT');

Go

--Create the Employees Table
CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(50),
    DepartmentID INT,
    HireDate DATE,
    FOREIGN KEY (DepartmentID) REFERENCES Departments(DepartmentID)
);

-- Insert sample data into Employees
INSERT INTO Employees (EmployeeID, Name, DepartmentID, HireDate) VALUES (1, 'John Smith', 3, '2023-01-10');
INSERT INTO Employees (EmployeeID, Name, DepartmentID, HireDate) VALUES (2, 'Jane Doe', 3, '2023-02-15');
INSERT INTO Employees (EmployeeID, Name, DepartmentID, HireDate) VALUES (3, 'Emily Davis', 2, '2023-03-20');
INSERT INTO Employees (EmployeeID, Name, DepartmentID, HireDate) VALUES (4, 'Michael Brown', 1, '2022-11-05');
INSERT INTO Employees (EmployeeID, Name, DepartmentID, HireDate) VALUES (5, 'Sarah Miller', 4, '2023-01-05');

-- Insert sample data into Sales
CREATE TABLE Sales (
    SaleID INT PRIMARY KEY,
    SaleDate DATE,
    SaleAmount DECIMAL(10, 2)
);

-- Inserting sample data into Sales
INSERT INTO Sales (SaleID, SaleDate, SaleAmount) VALUES (1, '2023-06-01', 150.00);
INSERT INTO Sales (SaleID, SaleDate, SaleAmount) VALUES (2, '2023-06-03', 200.00);
INSERT INTO Sales (SaleID, SaleDate, SaleAmount) VALUES (3, '2023-06-05', 50.00);
INSERT INTO Sales (SaleID, SaleDate, SaleAmount) VALUES (4, '2023-07-10', 300.00);
INSERT INTO Sales (SaleID, SaleDate, SaleAmount) VALUES (5, '2023-07-11', 250.00);

-- Inserting sample data into EmployeeAttendance
CREATE TABLE EmployeeAttendance (
    RecordID INT PRIMARY KEY,
    EmployeeID INT,
    AttendanceDate DATE,
    Status VARCHAR(10) -- Values could be 'Present', 'Absent', 'Leave'
);

-- Inserting sample data into EmployeeAttendance
INSERT INTO EmployeeAttendance (RecordID, EmployeeID, AttendanceDate, Status) VALUES (1, 101, '2023-07-01', 'Present');
INSERT INTO EmployeeAttendance (RecordID, EmployeeID, AttendanceDate, Status) VALUES (2, 102, '2023-07-01', 'Absent');
INSERT INTO EmployeeAttendance (RecordID, EmployeeID, AttendanceDate, Status) VALUES (3, 103, '2023-07-01', 'Leave');
INSERT INTO EmployeeAttendance (RecordID, EmployeeID, AttendanceDate, Status) VALUES (4, 101, '2023-07-02', 'Present');
INSERT INTO EmployeeAttendance (RecordID, EmployeeID, AttendanceDate, Status) VALUES (5, 102, '2023-07-02', 'Present');
-- Add more data as needed

-- Creating Customers table
CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY,
    Name VARCHAR(50),
    LoyaltyPoints INT
);

-- Inserting sample data into Customers
INSERT INTO Customers (CustomerID, Name, LoyaltyPoints) VALUES (1, 'John Doe', 0);
INSERT INTO Customers (CustomerID, Name, LoyaltyPoints) VALUES (2, 'Jane Smith', 0);
INSERT INTO Customers (CustomerID, Name, LoyaltyPoints) VALUES (3, 'Emily White', 0);

-- Creating Purchases table
CREATE TABLE Purchases (
    PurchaseID INT PRIMARY KEY,
    CustomerID INT,
    PurchaseDate DATE,
    Amount DECIMAL(10, 2),
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
);

-- Inserting sample data into Purchases
INSERT INTO Purchases (PurchaseID, CustomerID, PurchaseDate, Amount) VALUES (1, 1, '2023-07-01', 120.00);
INSERT INTO Purchases (PurchaseID, CustomerID, PurchaseDate, Amount) VALUES (2, 2, '2023-07-02', 60.00);
INSERT INTO Purchases (PurchaseID, CustomerID, PurchaseDate, Amount) VALUES (3, 1, '2023-07-03', 30.00);
-- Add more data as needed