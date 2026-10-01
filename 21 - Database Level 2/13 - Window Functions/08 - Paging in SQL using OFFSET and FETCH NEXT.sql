USE C21_DB1;

-- Declare Variables
DECLARE @PageNumber AS INT, @RowsPerPage INT;

-- Initalizing Variables
SET @PageNumber = 2; -- Set to the second page
SET @RowsPerPage = 3; -- Display 3 rows per page

SELECT 
	StudentID, 
	Name, 
	Subject, 
	Grade
FROM 
Students
ORDER BY StudentID
OFFSET (@PageNumber - 1) * @RowsPerPage ROWS
FETCH NEXT @RowsPerPage ROWS ONLY;