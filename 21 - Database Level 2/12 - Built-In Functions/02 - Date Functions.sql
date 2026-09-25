-- ============================================================
-- 1. GETDATE()
-- Purpose: Returns the current system date and time.
-- Syntax:

-- Usage:
SELECT GETDATE() AS [Today's Date];

GO
-- ============================================================
-- 2. DATEADD()
-- Purpose: Adds a specified number of units to a date.
-- Syntax:

-- Usage:
SELECT DATEADD(DAY, 7, GETDATE()) AS [Date after 7 days];
SELECT DATEADD(MONTH, 2, GETDATE()) AS [Date after 2 month];
SELECT DATEADD(YEAR, 1, GETDATE()) AS [Date after 1 year];


-- ============================================================
-- 3. DATEDIFF()
-- Purpose: Calculates the difference between two dates
--          in a specified unit.
-- Syntax:

-- Usage:
SELECT DATEDIFF(DAY, '2026-01-01', GETDATE()) AS [Date difference in days];
SELECT DATEDIFF(MONTH, '2025-01-01', GETDATE()) AS [Date difference in months];
SELECT DATEDIFF(YEAR, '2020-01-01', GETDATE()) AS [Date difference in years];


-- ============================================================
-- 4. DATEPART()
-- Purpose: Returns a specific numeric part of a date,
--          such as year, month, day, hour, etc.

-- Usage:
SELECT DATEPART(YEAR, GETDATE()) AS [Current year];
SELECT DATEPART(MONTH, GETDATE()) AS [Current month];
SELECT DATEPART(DAY, GETDATE()) [Current day];
SELECT DATEPART(HOUR, GETDATE()) [Current hour];


-- ============================================================
-- 5. DATENAME()
-- Purpose: Returns the name/string representation of a
--          specified part of a date.

-- Usage:
SELECT DATENAME(MONTH, GETDATE()) AS [Current month's name];
SELECT DATENAME(WEEKDAY, GETDATE()) AS [Current day's name];


-- ============================================================
-- 6. DAY()
-- Purpose: Extracts the day of the month from a date.

-- Usage:
SELECT DAY(GETDATE());


-- ============================================================
-- 7. MONTH()
-- Purpose: Extracts the month from a date.

-- Usage:
SELECT MONTH(GETDATE())


-- ============================================================
-- 8. YEAR()
-- Purpose: Extracts the year from a date.

-- Usage:
SELECT YEAR(GETDATE());


-- ============================================================
-- 9. CONVERT()
-- Purpose: Converts an expression from one data type
--          to another. Commonly used for date formatting.

-- Usage:
SELECT CONVERT(DATE, GETDATE());

-- Convert date to YYYY-MM-DD:
SELECT CONVERT(VARCHAR(10), GETDATE(), 23);

-- Convert date to DD/MM/YYYY:
SELECT CONVERT(VARCHAR(10), GETDATE(), 103);


-- ============================================================
-- 10. CAST()
-- Purpose: Converts an expression from one data type
--          to another.

-- Usage:
SELECT CAST(GETDATE() AS DATE);

-- Convert date/time to VARCHAR:
SELECT CAST(GETDATE() AS VARCHAR(30));


-- ============================================================
-- 11. EOMONTH()
-- Purpose: Returns the last day of the month for a
--          specified date.

-- Usage:
SELECT EOMONTH(GETDATE());

-- Last day of next month:
SELECT EOMONTH(GETDATE(), 1);

-- Last day of previous month:
SELECT EOMONTH(GETDATE(), -1);


-- ============================================================
-- 12. SYSDATETIME()
-- Purpose: Returns the current system date and time
--          with higher fractional-second precision than
--          GETDATE().

-- Usage:
SELECT SYSDATETIME();