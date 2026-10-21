USE C21_DB1;

DECLARE @input NVARCHAR(50) = '1 or 1=1';


DECLARE @SQL NVARCHAR(MAX);


SET @SQL =  ' SELECT * FROM Students WHERE studentID = ' +  @input;
EXECUTE(@SQL);
