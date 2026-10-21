USE C21_DB1;

-- Using Dynamic SQL (EXEC)

DECLARE @TableName VARCHAR(128) = 'Students';
EXEC GenerateDynamicSQL1 @TableName;

-- Using Dynamic SQL (without variable)
EXEC GenerateDynamicSQL2 'Employees';