DECLARE @RowString VARCHAR(255), @HeaderRow VARCHAR(255);
DECLARE @Row INT = 1, @Column INT = 1;
DECLARE @Result INT;

SET @HeaderRow = CHAR(9); -- Start with a tab

WHILE @Column <= 10
	BEGIN
		SET @HeaderRow += CAST(@Column AS VARCHAR(2)) + CHAR(9);
		SET @Column += 1;
	END

PRINT @HeaderRow

WHILE @Row <= 10
BEGIN
	SET @Column = 1;
	SET @RowString = CAST(@Row AS varchar(2)) + CHAR(9);
	WHILE @Column <= 10
	BEGIN
		SET @Result = @Row * @Column;
		SET @RowString += CAST(@Result AS VARCHAR(3)) + CHAR(9);

		-- Increment column
		SET @Column += 1;
	END

	-- Print the row string
	PRINT @RowString;

	-- Increment row and reset row string
	SET @Row += 1;
	SET @RowString = '';
END
