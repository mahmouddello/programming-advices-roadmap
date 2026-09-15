DECLARE @Balance DECIMAL(10,2) = 950.0;
DECLARE @Withdrawal DECIMAL(10,2) = 100.0;

WHILE @Balance > 0
	BEGIN
		SET @Balance = @Balance - @Withdrawal;

		-- Conditional Exit
		IF @Balance < 0
			BEGIN
				PRINT 'Insufficent funds for withdrawal'
				BREAK
			END

		PRINT 'New balance: ' + CAST(@Balance AS VARCHAR);
	END