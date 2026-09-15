DECLARE @Start INT = 1;
DECLARE @End INT = 10;
DECLARE @Counter INT = 1;

DECLARE @Result INT = 0;

WHILE @Start <= @END
	BEGIN
		WHILE @Counter <= @END
		BEGIN
			SET @Result = @Start * @Counter;
			PRINT CAST(@Start AS VARCHAR(2)) + ' * ' + CAST(@Counter AS VARCHAR(2)) + ' = ' + CAST(@Result AS VARCHAR(3));

			-- Increment Counter
			SET @Counter += 1;
		END
		
		-- Draw a horizontal line
		PRINT '-----------';

		-- Increment start and Reset counter
		SET @Start += 1;
		SET @Counter = 1;
	END