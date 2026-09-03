CREATE PROCEDURE SP_AddNewPerson2
    @NationalNo NVARCHAR(20),
    @FirstName NVARCHAR(100),
    @SecondName NVARCHAR(100),
    @LastName NVARCHAR(100),
    @DateOfBirth DATETIME,
    @Gender INT,
    @Address NVARCHAR(500),
    @Phone NVARCHAR(20),
    @NationalityCountryID INT,
    @NewPersonID INT OUTPUT
AS
BEGIN
    INSERT INTO People (NationalNo, FirstName, SecondName, LastName, DateOfBirth, Gender, Address, Phone, NationalityCountryID)
    VALUES (@NationalNo, @FirstName, @SecondName, @LastName, @DateOfBirth, @Gender, @Address, @Phone, @NationalityCountryID);

    SET @NewPersonID = SCOPE_IDENTITY();
END