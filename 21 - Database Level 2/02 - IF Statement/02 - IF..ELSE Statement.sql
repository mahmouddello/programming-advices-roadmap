Declare @year int;
set @year =2001;

IF @year >= 2000
    BEGIN
        PRINT '21st century'
    END
ELSE
    BEGIN
        PRINT '20th century or earlier'
    END