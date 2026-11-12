USE C21_DB1;

DECLARE scroll_cursor CURSOR LOCAL SCROLL STATIC FOR
SELECT StudentID, Name, Grade FROM Students;

OPEN scroll_cursor;

DECLARE @StudentID int, @Name nvarchar(50), @Grade int;

-- Fetch last record into the variables
FETCH LAST FROM scroll_cursor INTO @StudentID, @Name, @Grade;

WHILE @@FETCH_STATUS = 0
BEGIN
    PRINT @Name;

    -- starting from the last record, fetch the prevoius
    FETCH PRIOR FROM scroll_cursor INTO @StudentID, @Name, @Grade;
END

CLOSE scroll_cursor;

DEALLOCATE scroll_cursor;