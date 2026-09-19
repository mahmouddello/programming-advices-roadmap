USE C21_DB1;

GO

CREATE TABLE Accounts
(
	AccountID INT PRIMARY KEY,
	Balance DECIMAL(10, 2)
);

GO

CREATE TABLE Transactions
(
	TransactionID INT PRIMARY KEY IDENTITY(1,1),
	FromAccount INT,
	ToAccount INT,
	Amount DECIMAL(10, 2),
	Date DATETIME
)

GO

-- Insert Sample data into account

INSERT INTO Accounts (AccountID, Balance) VALUES (1, 500.00);
INSERT INTO Accounts (AccountID, Balance) VALUES (2, 300.00);