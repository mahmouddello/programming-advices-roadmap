USE C21_DB1;

-- 1) Declare a variable to hold the number of employees in the "Sales" department (DepartmentID = 3). 
-- If the count is greater than 1, print "Sales team has multiple employees.", 
-- otherwise print "Sales team has one or no employees."

-- Declare variables
DECLARE @DepartmentId INT;
DECLARE @DepartmentEmployeeCount INT;

-- Set Initial value
SET @DepartmentId = 3; -- Sales department id

-- Query Data
SELECT @DepartmentEmployeeCount = COUNT(*)
FROM Employees
WHERE DepartmentID = @DepartmentId;

IF @DepartmentEmployeeCount > 1
	PRINT 'Sales team has multiple employees.'
ELSE
	PRINT 'Sales team has one or no employees.'

-----------------------------------------
-- 2) Declare a variable and store the HireDate of employee with EmployeeID = 1. 
--If the hire date is before '2023-01-15', print "Early hire", otherwise print "Later hire".

DECLARE @EmployeeHireDate DATE;

SELECT @EmployeeHireDate = HireDate FROM Employees WHERE EmployeeID = 1;

IF @EmployeeHireDate < '2023-01-15'
	PRINT 'Early Hire'
ELSE
	PRINT 'Late Hire'
-----------------------------------------
-- 3) Declare a variable to store the department name for EmployeeID = 3 (using a subquery to populate it).
--Use an IF statement to check if the department is 'Marketing' and print an appropriate message; 
--otherwise print the actual department name.

DECLARE @DepartmentName VARCHAR(50);
DECLARE @EmployeeID INT;

SET @EmployeeID = 3;
SELECT @DepartmentName = D.Name FROM Employees AS E
INNER JOIN Departments AS D 
ON E.DepartmentID = D.DepartmentID
WHERE E.EmployeeID = @EmployeeID;

IF @DepartmentName = 'Marketing'
    PRINT 'Employee ' + CAST(@EmployeeID AS VARCHAR(10)) 
        + ' works in the Marketing department.'
ELSE
    PRINT 'Employee ' + CAST(@EmployeeID AS VARCHAR(10)) 
        + ' does not work in the Marketing department. Department: ' 
        + @DepartmentName + '.'
-----------------------------------------
-- 4) Declare a variable to store the sum of SaleAmount from the Sales table. 
--If the total exceeds 700, print "Sales target achieved!",
--otherwise print "Sales target not yet met. Remaining amount needed: [difference]" (calculate and display the difference).

DECLARE @TotalSales DECIMAL(10, 2);
DECLARE @SalesTarget DECIMAL(10, 2);

SELECT @TotalSales = SUM(SaleAmount) FROM Sales;
SET @SalesTarget = 700;

IF @TotalSales > @SalesTarget
    PRINT 'Sales target achieved!'
ELSE
    PRINT 'Sales target not yet met. Remaining amount needed: '  + CAST((@TotalSales - @SalesTarget) AS VARCHAR(10));
-----------------------------------------
-- 5) Declare a variable holding the `SaleAmount` for `SaleID = 3`. Use nested IF statements (or IF/ELSE IF) to classify it as:
--- "Small sale" if less than 100
--- "Medium sale" if between 100 and 250
--- "Large sale" if greater than 250

DECLARE @SaleID INT;
DECLARE @SaleAmount DECIMAL(10, 2);

SET @SaleID = 3;
SELECT @SaleAmount = SaleAmount FROM Sales WHERE SaleID = @SaleID;

IF @SaleAmount < 100
    PRINT 'Small sale'
ELSE IF @SaleAmount > 100 AND @SaleAmount < 250
    PRINT 'Medium sale'
ELSE
    PRINT 'Large sale'
-----------------------------------------
-- 6) Declare a variable to store the Status of the attendance record for EmployeeID = 102 on '2023-07-01'. 
--If the status is 'Absent', print "Follow-up required", otherwise print "No action needed".

DECLARE @Status VARCHAR(20)

SET @EmployeeID = 102;
SELECT 
    @Status = Status FROM EmployeeAttendance 
WHERE 
    EmployeeID = @EmployeeID AND AttendanceDate = '2023-07-01';

IF @Status = 'Absent'
    PRINT 'Follow-up required'
ELSE
    PRINT 'No action needed'

-----------------------------------------
-- 7) Declare two variables: one to count 'Present' records and one to count total records in EmployeeAttendance.
--Calculate the percentage present.
--If it's above 50%, print "Good attendance overall", otherwise print "Attendance needs improvement".

DECLARE @PresentRecordsCount DECIMAL(10, 2);
DECLARE @TotalAttendanceCount DECIMAL(10, 2);
DECLARE @Percentage DECIMAL(10, 2);

SELECT @PresentRecordsCount = COUNT(*) FROM EmployeeAttendance WHERE Status = 'Present';
SELECT @TotalAttendanceCount = COUNT(*) FROM EmployeeAttendance;

SET @Percentage = (@PresentRecordsCount  * 100) / @TotalAttendanceCount;

IF @Percentage > 50
    PRINT 'Good attendance overall'
ELSE
    PRINT 'Attendance needs improvment'

-----------------------------------------
-- 8) Declare a variable to store the total Amount spent by CustomerID = 1 from the Purchases table. 
--If the total spent is greater than 100, print "Eligible for loyalty points bonus", 
--otherwise print "Not yet eligible for bonus".

DECLARE @TotalSpentByCustomer DECIMAL(10, 2);
DECLARE @CustomerID INT;

SET @CustomerID = 1;
SELECT @TotalSpentByCustomer = SUM(Amount) FROM Purchases WHERE CustomerID = @CustomerID;

IF @TotalSpentByCustomer > 100.0
    PRINT 'Eligible for loyalty points bonus'
ELSE
    PRINT 'Not yet eligible for bonus'

-----------------------------------------
-- 9) Declare a variable using DATEDIFF to calculate how many days ago EmployeeID = 4 was hired (compared to GETDATE()).
--If more than 300 days, print "Experienced employee",
--otherwise print "Relatively new employee".

DECLARE @DaysSinceHired INT;

SET @EmployeeID = 4;
SELECT @EmployeeHireDate = HireDate FROM Employees WHERE EmployeeID = @EmployeeID
SET @DaysSinceHired = DATEDIFF(DAY, @EmployeeHireDate, GETDATE());

IF @DaysSinceHired > 300
    PRINT 'Experienced employee'
ELSE
    PRINT 'Relatively new employee'

-----------------------------------------
-- 10) Declare variables for the number of purchases and total amount spent by `CustomerID = 1`. Using nested IF statements:

--- If number of purchases is greater than 1 AND total amount is greater than 100, print "Frequent big spender"
--- Else if number of purchases is greater than 1, print "Frequent small spender"
--- Else print "Infrequent customer"

DECLARE @TotalPurchaseRecords INT;

SET @CustomerID = 1;
SELECT @TotalPurchaseRecords = COUNT(*), @TotalSpentByCustomer = SUM(Amount) FROM Purchases WHERE CustomerID = @CustomerID;

IF @TotalPurchaseRecords > 1 AND @TotalSpentByCustomer > 100
    PRINT 'Frequent big spender'
ELSE IF @TotalPurchaseRecords > 1
    PRINT 'Frequent small spender'
ELSE
    PRINT 'Infrequent customer'

-----------------------------------------
-- 11) Declare two variables to store the HireDate values for EmployeeID = 1 and EmployeeID = 4. 
--Use an IF statement to determine and print which employee was hired first (or if they were hired on the same date).

DECLARE @HireDate1 DATE, @HireDate2 DATE;

SELECT @HireDate1 = HireDate FROM Employees WHERE EmployeeID = 1;
SELECT @HireDate2 = HireDate FROM Employees WHERE EmployeeID = 4;

IF @HireDate1 < @HireDate2
    PRINT 'Employee 1 got hired first'
ELSE IF @HireDate1 = @HireDate2
    PRINT 'Both employeed got hired at the same date'
ELSE
    PRINT 'Employee 4 got hired first'

-----------------------------------------
-- 12) Declare a variable to store the SaleDate for SaleID = 4. Use MONTH() in an IF statement to check if the sale occurred in July. 
-- If so, print "July sale", otherwise print the actual month name/number.

DECLARE @SaleDate DATE;

SET @SaleID = 5;
SELECT @SaleDate = SaleDate FROM Sales WHERE SaleID = @SaleID;

IF MONTH(@SaleDate) = 7
    PRINT 'July sale'
ELSE
    PRINT 'Sale occurd on ' + CAST(MONTH(@SaleDate) AS VARCHAR) + '. month of the year'