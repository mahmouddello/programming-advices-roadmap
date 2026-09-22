USE C21_DB1;

-- Create the stored procedure
GO
CREATE PROCEDURE dbo.GetAllPeople
AS
BEGIN
	SELECT * FROM People;
END


GO
-- Execute the procedure
EXEC dbo.GetAllPeople;