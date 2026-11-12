USE C21_DB1;

/*
	1. Create a static cursor with name "static_cursor".
	2. Specify what's the data that cursor should snapshot.
*/
DECLARE static_cursor CURSOR STATIC FOR
SELECT StudentID, Name, Grade FROM Students;


-- Open the cursor. This initializes the cursor and makes it ready to use.
OPEN static_cursor;

-- Declare variables to hold the data from the cursor on each iteration.
DECLARE @StudentID int, @Name nvarchar(50), @Grade int;

-- Fetch the first row of data from the cursor and store it in the declared variables.
FETCH NEXT FROM static_cursor INTO @StudentID, @Name, @Grade;


-- Add a record to original table to prove that cursor doesn't got affected.
INSERT INTO Students VALUES (12, 'Mahmoud', 'Science', 90, 1);

-- Enter a loop that will continue as long as the previous fetch was successful.
/*
	FETCH STATUSES:
	0: The fetch was successful (a row was found and retrieved).
	-1: The fetch failed or the row was beyond the result set (you reached the end).					   
	-2: The row being fetched is missing (e.g., deleted by another process in certain cursor types).
	-9: Cursor doesn't do FETCH
*/
WHILE @@FETCH_STATUS = 0
BEGIN
	 -- Print the current row's student name and grade.
    PRINT 'Student Name: ' + @Name + ', Grade: ' + CAST(@Grade AS NVARCHAR(10));

	-- Fetch the next row of data from the cursor.
    -- The loop will continue until there are no more rows to fetch.
    FETCH NEXT FROM static_cursor INTO @StudentID, @Name, @Grade;
END

-- Once the loop is finished (no more rows to fetch), close the cursor.
-- Closing the cursor releases the current result set.
CLOSE static_cursor;

-- Deallocate the cursor.
-- This step is important to free up resources used by the cursor.
DEALLOCATE static_cursor;

-- COMPARE CURSOR WITH SELECT (To see if table's update affected the cursor)
SELECT StudentID, Name, Grade FROM Students;