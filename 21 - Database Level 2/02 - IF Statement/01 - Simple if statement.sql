
-- Step 1: Declare and Initalize variables
DECLARE @a INT, @b INT;

SET @a = 20; 
SET @b = 10;

-- you can use >, <, =, !=

-- Step 2: Compare values and print output message
IF @a > @b
	BEGIN 
		PRINT 'A is greater than B';
	END
	