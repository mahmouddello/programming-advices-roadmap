	DECLARE @Counter INT = 1;

	--This loop prints numbers from 1 to 5.
	WHILE @Counter <= 5
	BEGIN
		PRINT 'Count: ' + CAST(@Counter AS VARCHAR);
		SET @Counter = @Counter + 1;
	END

	Print '';
	Print 'Reversed Counter';

	--This loop prints numbers from 5 to 1.
	set @Counter= 5;

	WHILE @Counter > 0
	BEGIN
		PRINT 'Count: ' + CAST(@Counter AS VARCHAR);
		SET @Counter = @Counter - 1;
	END