USE VehicleMakesDB;

-- Problem #11: Get total number of makes that run on GAS
SELECT 
    COUNT(*) AS TotalMakesRunOnGas
FROM (
    SELECT DISTINCT 
        m.Make, 
        ft.FuelTypeName
    FROM 
        VehicleDetails vd
    INNER JOIN 
        Makes m 
        ON vd.MakeID = m.MakeID
    INNER JOIN 
        FuelTypes ft 
        ON vd.FuelTypeID = ft.FuelTypeID
    WHERE 
        ft.FuelTypeName = N'GAS'
) AS R1;

-- Problem #11: Without subquery
SELECT 
    COUNT(DISTINCT m.Make) AS TotalMakesRunOnGas
FROM 
    VehicleDetails vd
INNER JOIN 
    Makes m 
    ON vd.MakeID = m.MakeID
INNER JOIN 
    FuelTypes ft 
    ON vd.FuelTypeID = ft.FuelTypeID
WHERE 
    ft.FuelTypeName = N'GAS';

-- Problem #12: Count Vehicles by make and order them by NumberOfVehicles from high to low
SELECT 
    m.Make, 
    COUNT(*) AS NumberOfVehicles
FROM 
    VehicleDetails vd
INNER JOIN 
    Makes m ON vd.MakeID = m.MakeID
GROUP BY 
    m.Make
ORDER BY 
    NumberOfVehicles DESC;

-- Problem #13: Get all Makes/Count Of Vehicles that manufactures more than 20K Vehicles 
SELECT 
    m.Make, 
    COUNT(*) AS NumberOfVehicles
FROM 
    VehicleDetails vd
INNER JOIN 
    Makes m ON vd.MakeID = m.MakeID
GROUP BY 
    m.Make
HAVING
    COUNT(*) > 20000
ORDER BY 
    NumberOfVehicles DESC;

--  Problem #14: Get all Makes with make starts with 'B'
SELECT 
    Makes.Make 
FROM 
    Makes
WHERE 
    Make LIKE 'B%';

--  Problem #15: Get all Makes with make ends with 'W'
SELECT 
    Makes.Make 
FROM 
    Makes
WHERE 
    Make LIKE '%W';

-- Problem #16: Get all Makes that manufactures DriveTypeName = FWD
SELECT DISTINCT
    m.Make,
    dt.DriveTypeName
FROM
    VehicleDetails vd
INNER JOIN
    Makes m ON vd.MakeID = m.MakeID
INNER JOIN
    DriveTypes dt ON vd.DriveTypeID = dt.DriveTypeID
WHERE 
    dt.DriveTypeName = 'FWD';

-- Problem #17: Get total Makes that Mantufactures DriveTypeName = FWD
SELECT 
    COUNT(*) AS TotalMakesFWD
FROM
(
SELECT DISTINCT
    m.Make,
    dt.DriveTypeName
FROM
    VehicleDetails vd
INNER JOIN
    Makes m ON vd.MakeID = m.MakeID
INNER JOIN
    DriveTypes dt ON vd.DriveTypeID = dt.DriveTypeID
WHERE 
    dt.DriveTypeName = 'FWD'
) R3;

-- without subquery
SELECT 
    COUNT(DISTINCT m.Make) AS TotalMakesFWD
FROM
    VehicleDetails vd
INNER JOIN
    Makes m ON vd.MakeID = m.MakeID
INNER JOIN
    DriveTypes dt ON vd.DriveTypeID = dt.DriveTypeID
WHERE 
    dt.DriveTypeName = 'FWD'

-- Problem #18: Get total vehicles per DriveTypeName Per Make and order them per make asc then per total Desc
SELECT
    m.Make,
    dt.DriveTypeName,
    COUNT(*) AS Total
FROM
    VehicleDetails vd
INNER JOIN
    Makes m ON vd.MakeID = m.MakeID
INNER JOIN
    DriveTypes dt ON vd.DriveTypeID = dt.DriveTypeID
GROUP BY 
    m.Make,
    dt.DriveTypeName
ORDER BY 
    m.Make ASC,
    Total DESC;

--  Problem #19: Get total vehicles per DriveTypeName Per Make then filter only results with total > 10,000
SELECT
    m.Make,
    dt.DriveTypeName,
    COUNT(*) AS Total
FROM
    VehicleDetails vd
INNER JOIN
    Makes m ON vd.MakeID = m.MakeID
INNER JOIN
    DriveTypes dt ON vd.DriveTypeID = dt.DriveTypeID
GROUP BY 
    m.Make, 
    dt.DriveTypeName
HAVING 
    COUNT(*) > 10000
ORDER BY 
    m.Make ASC, 
    Total DESC;

-- Problem #20: Get all Vehicles that number of doors is not specified 
SELECT 
    *
FROM 
    VehicleDetails AS vd
WHERE
    vd.NumDoors IS NULL;