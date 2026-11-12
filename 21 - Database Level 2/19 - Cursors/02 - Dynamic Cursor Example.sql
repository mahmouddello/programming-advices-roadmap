USE C21_DB1;

/*
	1. Create a dynamic cursor with name "dynamic_cursor".
	2. It does NOT copy the data to tempdb. Every FETCH reads from the original table.
*/
DECLARE dynamic_cursor CURSOR DYNAMIC FOR
SELECT StudentID, Name, Grade FROM Students;

OPEN dynamic_cursor;

DECLARE @StudentID int, @Name nvarchar(50), @Grade int;

FETCH NEXT FROM dynamic_cursor INTO @StudentID, @Name, @Grade;

-- Add a record to the original table.
-- Unlike the static cursor, the dynamic cursor WILL see this new row.
INSERT INTO Students VALUES (13, 'Anas', 'Audio & Visual', 82, 1);

WHILE @@FETCH_STATUS = 0
BEGIN
    PRINT 'Student Name: ' + @Name + ', Grade: ' + CAST(@Grade AS NVARCHAR(10));

    FETCH NEXT FROM dynamic_cursor INTO @StudentID, @Name, @Grade;
END

CLOSE dynamic_cursor;
DEALLOCATE dynamic_cursor;

-- Compare with the table (the new row exists in both the table and the cursor output)
SELECT StudentID, Name, Grade FROM Students;