
DECLARE @Counter INT = 1;

PRINT 'Break Example:'

WHILE @Counter <= 10
BEGIN
		PRINT 'Counter: ' + CAST(@Counter AS VARCHAR(2));
		IF @Counter = 5
			BREAK;
		SET @Counter += 1;
END

PRINT ''; -- new line
PRINT 'Continue Example: ';

SET @Counter = 0;

WHILE @Counter <= 10
BEGIN
    -- Print only odd numbers
    IF @Counter % 2 = 0
    BEGIN
        SET @Counter += 1;
        CONTINUE;
    END

    PRINT 'Counter: ' + CAST(@Counter AS VARCHAR);

    SET @Counter += 1;
END
