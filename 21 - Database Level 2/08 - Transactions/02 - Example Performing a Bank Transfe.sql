USE C21_DB1;

BEGIN TRANSACTION
    BEGIN TRY
        -- Subtract $100 from Account 1
        UPDATE Accounts SET Balance = Balance - 100 WHERE AccountID = 1;


        -- Add $100 to Account 2
        UPDATE Accounts SET Balance = Balance + 100 WHERE AccountID = 2;


        -- Log the transaction
        INSERT INTO Transactions (FromAccount, ToAccount, Amount, Date) VALUES (1, 2, 100, GETDATE());

        -- Produce an error - transaction will roll
        IF (SELECT Balance FROM Accounts WHERE AccountID = 1) < 400
            THROW 50001, 'Insufficent Funds', 1

    -- Commit the transaction
    COMMIT;
    END TRY
BEGIN CATCH
        -- Rollback in case of error
        SELECT ERROR_MESSAGE() AS ErrorMessage;
        ROLLBACK;
        -- Error handling code here
END CATCH;
