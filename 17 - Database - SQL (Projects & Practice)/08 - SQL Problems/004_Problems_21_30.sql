USE VehicleMakesDB;

--  Problem #21: Get Total Vehicles that number of doors is not specified
SELECT 
    COUNT(*) AS TotalVehiclesWithNoDoorsSpecified
FROM 
    VehicleDetails AS vd
WHERE
    vd.NumDoors IS NULL;

--  Problem 22: Get percentage of vehicles that hAS no doors specified
SELECT 
    R1.*, CAST(R1.NoDoorsSpecified AS float) / CAST(TotalVehicles AS float) AS [Percentage]
FROM
(
    SELECT 
        COUNT(*) AS NoDoorsSpecified,
        (SELECT COUNT(*) FROM VehicleDetails) AS TotalVehicles
    FROM 
        VehicleDetails AS vd
    WHERE
        vd.NumDoors IS NULL
) R1;

-- Problem #23: Get MakeID , Make, SubModelName for all vehicles that have SubModelName 'Elite' 
SELECT DISTINCT
    vd.MakeID,
    m.Make,
    sm.SubModelName
FROM
    VehicleDetails vd
INNER JOIN
    Makes m ON vd.MakeID = m.MakeID
INNER JOIN
    SubModels sm ON vd.SubModelID = sm.SubModelID
WHERE
    sm.SubModelName LIKE '%Elite%';

-- Problem #24: Get all vehicles that have engines > 3 liters and only 2 doors
SELECT
    *
FROM
    VehicleDetails AS vd
WHERE
    vd.Engine_Liter_Display > 3
    AND 
    vd.NumDoors = 2;

-- Problem #25: Get make and vehicles that the engine contains 'OHV' and have Cylinders = 4
SELECT
    m.Make,
    vd.*
FROM
    VehicleDetails AS vd
INNER JOIN
    Makes m ON vd.MakeID = m.MakeID
WHERE
    vd.Engine LIKE '%OHV%'
    AND
    vd.Engine_Cylinders = 4;

-- Problem #26: Get all vehicles that their body is 'Sport Utility' and Year > 2020
SELECT
    b.BodyName,
    vd.*
FROM
    VehicleDetails AS vd
INNER JOIN
    Bodies AS b ON vd.BodyID = b.BodyID
WHERE
    b.BodyName = 'Sport Utility'
    AND
    vd.Year > 2020;

-- Problem #27: Get all vehicles that their Body is 'Coupe' or 'Hatchback' or 'Sedan' 
SELECT
    b.BodyName,
    vd.*
FROM
    VehicleDetails AS vd
INNER JOIN
    Bodies AS b ON vd.BodyID = b.BodyID
WHERE
    b.BodyName IN ('Coupe', 'Hatchback', 'Sedan')

-- Problem 28: Get all vehicles that their body is 'Coupe' or 'Hatchback' or 'Sedan' and manufactured in year 2008 or 2020 or 2021 
SELECT
    b.BodyName,
    vd.*
FROM
    VehicleDetails AS vd
INNER JOIN
    Bodies AS b ON vd.BodyID = b.BodyID
WHERE
    b.BodyName IN ('Coupe', 'Hatchback', 'Sedan')
    AND
    vd.Year IN (2008, 2020, 2021);

-- Problem 29: Return found = 1 if there is any vehicle made in year 1950 
SELECT 
    found = 1
WHERE 
    EXISTS (
        SELECT 
            1
        FROM 
            VehicleDetails 
        WHERE 
            Year = 1950
   );

-- Problem #30: Get all Vehicle_Display_Name, NumDoors and, add extra column to describe number of doors by words, and if door is null display 'Not Set' 

-- Step 1: get all unique numdoors values
SELECT DISTINCT 
    vd.NumDoors
FROM 
    VehicleDetails AS vd;

-- NumDoors : 0, 1, 2, 3, 4, 5, 6, 8, NULL
SELECT 
    vd.Vehicle_Display_Name,
    vd.NumDoors,
    DoorDescription =
        CASE 
            WHEN vd.NumDoors = 0 THEN 'Zero Doors'
            WHEN vd.NumDoors = 1 THEN 'One Doors'
            WHEN vd.NumDoors = 2 THEN 'Two Doors'
            WHEN vd.NumDoors = 3 THEN 'Three Doors'
            WHEN vd.NumDoors = 4 THEN 'Four Doors'
            WHEN vd.NumDoors = 5 THEN 'Five Doors'
            WHEN vd.NumDoors = 6 THEN 'Six Doors'
            WHEN vd.NumDoors = 8 THEN 'Eight Doors'
            WHEN vd.NumDoors IS NULL THEN 'Not Set'
            ELSE 'Unknown'
        END
FROM 
    VehicleDetails AS vd;