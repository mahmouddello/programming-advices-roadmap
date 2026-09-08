DECLARE @Age INT = 25;
DECLARE @Salary DECIMAL(10,2) = 50000;

IF (@Age > 18 AND @Salary >= 50000)
	BEGIN
		PRINT 'Eligible for the loan';
	END
ELSE
	BEGIN
		PRINT 'Not eligible for the loan';
	END

------------------------------

DECLARE @Grade CHAR(1) = 'B';
DECLARE @AttendancePercentage INT = 75;

IF @Grade = 'A' OR @AttendancePercentage > 70
	BEGIN
		PRINT 'Qualified for extra-curricular activities';
	END
ELSE
	BEGIN
		PRINT 'Not qualified for extra-curricular activities';
	END

--------------------------

DECLARE @CustomerStatus NVARCHAR(10) = 'Inactive';

IF NOT (@CustomerStatus = 'Active')
	BEGIN
		PRINT 'Send re-engagement email';
	END
ELSE
	BEGIN
		PRINT 'Customer is active';
	END
