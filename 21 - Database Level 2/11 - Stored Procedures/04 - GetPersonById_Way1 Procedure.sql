USE C21_DB1;

GO
CREATE PROCEDURE dbo.GetPersonById_Way1
	@PersonID INT
AS
BEGIN
	SELECT * FROM People WHERE PersonID = @PersonID
END

GO
EXEC dbo.GetPersonById_Way1
	@PersonID = 1;