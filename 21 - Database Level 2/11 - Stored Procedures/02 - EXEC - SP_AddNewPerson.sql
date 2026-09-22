USE C21_DB1;

DECLARE @PersonID INT;

EXEC SP_AddNewPerson 
    @FirstName = 'John', 
    @LastName = 'Doe', 
    @Email = 'john.doe@example.com',
    @NewPersonID = @PersonID OUTPUT;

SELECT @PersonID AS NewPersonID;