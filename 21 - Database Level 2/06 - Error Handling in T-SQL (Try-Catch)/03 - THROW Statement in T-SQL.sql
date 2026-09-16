  
use C21_DB1;

CREATE TABLE Products (
    ProductID INT PRIMARY KEY,
    StockQuantity INT
);

Go

INSERT INTO Products (ProductID, StockQuantity) VALUES (1, 100);
INSERT INTO Products (ProductID, StockQuantity) VALUES (2, 50);
INSERT INTO Products (ProductID, StockQuantity) VALUES (3, 75);

  
declare @NewStockQty INT;


set @NewStockQty=-5;

-- Start a TRY block
BEGIN TRY
    -- Check if NewStockQty is negative
    IF @NewStockQty < 0
        THROW 51000, 'Stock quantity cannot be negative.', 1;


    -- Proceed with updating stock (example code)
    UPDATE Products SET StockQuantity = @NewStockQty WHERE ProductID = 1;
END TRY


-- Start a CATCH block to handle the error
BEGIN CATCH
    SELECT
        ERROR_NUMBER() AS ErrorNumber,
        ERROR_MESSAGE() AS ErrorMessage,
        ERROR_SEVERITY() AS ErrorSeverity,
        ERROR_STATE() AS ErrorState,
        ERROR_LINE() AS ErrorLine,
        ERROR_PROCEDURE() AS ErrorProcedure;
END CATCH