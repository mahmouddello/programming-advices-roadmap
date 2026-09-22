USE C21_DB1;

GO
CREATE PROCEDURE dbo.CheckPersonExists
	@PersonID INT
AS
BEGIN
	IF EXISTS(SELECT 1 FROM People WHERE PersonID = @PersonID)
		RETURN 1
	ELSE
		RETURN 0
END

GO
DECLARE @Result INT;
EXEC @Result = dbo.CheckPersonExists @PersonID = 1;

IF @Result = 1
	PRINT 'Person Exists';
ELSE
	PRINT 'Person do NOT Exists';