USE C21_DB1;

DECLARE @EmployeeID INT;
DECLARE @Name VARCHAR(50);
DECLARE @MaxID INT;

-- Initialize the starting point
SELECT @EmployeeID = MIN(EmployeeID) FROM Employees;

-- Find the maximum Employee ID (Base condition to breakout from the loop)
SELECT @MaxID = MAX(EmployeeID) FROM Employees;

-- Loop through employee
WHILE @EmployeeID IS NOT NULL AND @EmployeeID <= @MaxID
	BEGIN
		-- Perform an operation, e.g. print employeee's name
		SELECT @Name = [Name] FROM Employees WHERE EmployeeID = @EmployeeID;
		PRINT @Name;

		-- Get the next Employee ID (Selects the next minimum)
		SELECT @EmployeeID = MIN(EmployeeID) FROM Employees WHERE EmployeeID > @EmployeeID;
	END