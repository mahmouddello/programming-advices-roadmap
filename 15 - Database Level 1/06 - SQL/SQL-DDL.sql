-- USE <DatabaseName> is used to switch the database in SQL Scripts
USE DB2;

-- Creates a database <Name>
CREATE DATABASE Koko;

-- Creates a database with <Name> If it doesn't exists
 IF NOT EXISTS(SELECT * FROM sys.databases WHERE name = 'DB2')
  BEGIN
    CREATE DATABASE DB2;
  END

-- Deletes (Drops) a database with it's data
DROP DATABASE DB2;

-- Drops Database with <Name> if it exists
IF EXISTS(SELECT * FROM sys.databases WHERE name = 'DB2')
  BEGIN
    Drop DATABASE DB2;
  END

-- Create table through SQL Script
--CREATE TABLE Employees (
--    ID int NOT NULL,
--	  Name nvarchar(50) NOT NULL,
--		Phone nvarchar(10) NULL,
--		Salary smallmoney NULL,
--    PRIMARY KEY (ID)
--);

-- Deletes a table from currently used database
DROP TABLE Employees;

-- ALTER TABLE STATEMENT--

-- (This syntax doesn't work in SQL Server)
--ALTER TABLE Employees
--RENAME COLUMN Gendor TO Gender;

ALTER TABLE Employees
ADD Gendor char(1);

-- stored procedure (rename column)
exec sp_rename 'employees.Gendor', 'Gender', 'COLUMN';

-- stored procedure (rename table)
 exec sp_rename 'Employees', 'EMPLOYEES';

-- Modify Column
ALTER TABLE Employees
ALTER COLUMN Name VARCHAR(100);

-- Drop Column from Table
ALTER TABLE Employees
DROP COLUMN Gender;

-- Full Database backup
BACKUP DATABASE DB2
TO DISK = 'D:\DB2.Bak';

-- Differential Datbase backup
BACKUP DATABASE DB2
TO DISK = 'D:\DB2.Bak'
WITH DIFFERENTIAL;


-- Restore Database (Always make sure to name the full and differntial backups differnt to identify them later)

-- Step 1: Restore the full backup
RESTORE DATABASE DB2
FROM DISK = 'C:\DB2.Bak'
WITH NORECOVERY;

-- Step 2: Restore the differntial backup to apply the latest changes
RESTORE DATABASE DB2
FROM DISK = 'D:\DB2.Bak'
WITH RECOVERY;