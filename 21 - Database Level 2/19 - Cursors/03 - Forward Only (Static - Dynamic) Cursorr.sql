USE C21_DB1;

DECLARE fwd_cursor CURSOR FORWARD_ONLY FOR
SELECT StudentID, Name, Grade FROM Students;

-- Source - https://stackoverflow.com/a/27568744
-- Posted by Jeroen Mostert
-- Retrieved 2026-11-12, License - CC BY-SA 3.0

-- Default type: Dynamic and Forward Only, Global Scope
SELECT name, properties FROM sys.dm_exec_cursors(@@SPID);

OPEN fwd_cursor;

DECLARE @StudentID int, @Name nvarchar(50), @Grade int;

FETCH NEXT FROM fwd_cursor INTO @StudentID, @Name, @Grade;

WHILE @@FETCH_STATUS = 0
BEGIN
	PRINT 'Student Name: ' + @Name + ', Grade: ' + CAST(@Grade AS NVARCHAR(10));

    FETCH NEXT FROM fwd_cursor INTO @StudentID, @Name, @Grade;
END

CLOSE fwd_cursor;
DEALLOCATE fwd_cursor;