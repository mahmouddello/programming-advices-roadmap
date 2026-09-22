USE C21_DB1;

SELECT * FROM People;

GO
CREATE PROCEDURE dbo.DeletePersonByID
	@PersonID INT
AS
BEGIN
	DELETE FROM People WHERE PersonID = @PersonID;
END

GO

EXEC dbo.DeletePersonByID
	@PersonID = 6;

SELECT * FROM People;