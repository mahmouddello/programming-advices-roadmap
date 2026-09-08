-- Using IF with Variables
-- Variables can be used within an IF statement for dynamic conditions.

DECLARE @age INT;
SET @age = 25;

IF @age >= 18
BEGIN
    PRINT 'Adult'
END
ELSE
BEGIN
    PRINT 'Minor'
END

-- Conditional Assignment
-- IF statements are often used for conditional assignment to variables.
DECLARE @max INT;
Declare @a int, @b int;
set @a = 20;
set @b=10;

IF @a > @b
    SET @max = @a
ELSE
    SET @max = @b

Print @max;