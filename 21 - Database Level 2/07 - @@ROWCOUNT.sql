USE C21_DB1;

UPDATE Employees SET DepartmentID = 3 WHERE DepartmentID = 4;

SELECT @@ROWCOUNT AS RowsAffected