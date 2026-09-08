Declare  @score int;
set @score = 92;

IF @score >= 90
		PRINT 'Grade A'
ELSE
	BEGIN
		IF @score >= 80
				PRINT 'Grade B'
		ELSE
				PRINT 'Grade C or lower'
	END