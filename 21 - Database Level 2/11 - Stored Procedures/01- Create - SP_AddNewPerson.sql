USE C21_DB1;

CREATE PROCEDURE SP_AddNewPerson
	@FirstName NVARCHAR(100),
	@LastName NVARCHAR(100),
	@Email NVARCHAR(255),
	@NewPersonID INT OUTPUT
AS
BEGIN
	INSERT INTO People (FirstName, LastName, Email)
	VALUES (@FirstName, @LastName, @Email);

	SET @NewPersonID = SCOPE_IDENTITY();
END