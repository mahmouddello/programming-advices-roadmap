USE C21_DB1;

-- Assume We have this table with a primary key unique constraint (EmployeeID) 
--CREATE TABLE Employees3
--(
--	EmployeeID INT PRIMARY KEY,
--	Name NVARCHAR(100),
--	Position NVARCHAR(100)
--)

BEGIN TRY
	-- Insert a record into the employees table
	INSERT INTO Employees3(EmployeeID, Name, Position) VALUES (1, 'Jane Doe', 'Sales Manager');

	-- Attempt to insert another record with the same id (primary key rule violation)
	INSERT INTO Employees3(EmployeeID, Name, Position) VALUES (1, 'John Smith', 'Marketing Manager')
END TRY
BEGIN CATCH
	-- Handle the error
	PRINT 'An error occurred:'
	SELECT
		ERROR_NUMBER() AS ErrorNumber,
		ERROR_SEVERITY() AS ErrorSeverity,
		ERROR_STATE() AS ErrorState,
		ERROR_PROCEDURE() AS ErrorProcedure,
		ERROR_LINE() AS ErrorLine,
		ERROR_MESSAGE() AS ErrorMesag;
	-- Rollback the transaction if any
END CATCH