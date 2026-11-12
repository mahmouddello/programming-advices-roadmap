USE C21_DB1;

BEGIN TRAN;
UPDATE dbo.Products SET StockQuantity = 200 WHERE ProductID = 1;

-- No Commit