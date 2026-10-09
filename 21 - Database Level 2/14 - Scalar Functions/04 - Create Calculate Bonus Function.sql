USE C21_DB1;

go
CREATE FUNCTION CalculateBonus (@PerformanceRating INT, @Salary INT)
RETURNS INT
AS
BEGIN
    DECLARE @Bonus INT;

    IF @PerformanceRating >= 5
        SET @Bonus = @Salary * 0.1 -- 10% bonus for high performance
    ELSE
        SET @Bonus = @Salary * 0.05 -- 5% bonus otherwise

    RETURN @Bonus;
END;




