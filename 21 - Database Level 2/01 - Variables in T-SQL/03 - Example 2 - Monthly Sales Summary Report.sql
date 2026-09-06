USE C21_DB1;
/*
In this scenario, we'll use T-SQL variables to generate a monthly sales summary report for a given year and month. 
This report will include total sales, number of transactions, and average sale value. 
We'll need a Sales table that contains details of each sale.
*/

-- This script generates a monthly sales summary report.
-- It includes total sales, total number of transactions, and the average sale value for a specified month and year.

-- Declare variables
DECLARE @Year INT;
DECLARE @Month INT;
DECLARE @TotalSales DECIMAL(10, 2);
DECLARE @TotalTransactions INT;
DECLARE @AverageSale DECIMAL(10, 2);

-- Initialize variables
SET @Year = 2023; -- Set the year for the report
SET @Month = 6; -- Set the month for the report

-- Calculate total sales for the specified month and year
SELECT @TotalSales = SUM(SaleAmount)
FROM Sales
WHERE YEAR(SaleDate) = @Year AND MONTH(SaleDate) = @Month;

-- Calculate the total number of transactions
SELECT @TotalTransactions = COUNT(*)
FROM Sales
WHERE YEAR(SaleDate) = @Year AND MONTH(SaleDate) = @Month;

-- Calculate the average sale value
SET @AverageSale = @TotalSales / @TotalTransactions;

-- Print the report
PRINT 'Monthly Sales Summary Report';
PRINT 'Year: ' + CAST(@Year AS VARCHAR) + ', Month: ' + CAST(@Month AS VARCHAR);
PRINT 'Total Sales: ' + CAST(@TotalSales AS VARCHAR);
PRINT 'Total Transactions: ' + CAST(@TotalTransactions AS VARCHAR);
PRINT 'Average Sale Value: ' + CAST(@AverageSale AS VARCHAR);
