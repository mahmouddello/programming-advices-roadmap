USE VehicleMakesDB;

-- Problem #1 - Create Master View
GO  -- separates batches

CREATE VIEW VehicleMasterDetails
AS
SELECT vd.ID, vd.MakeID, m.Make,
       vd.ModelID, mm.ModelName,
       vd.SubModelID, sm.SubModelName,
       vd.BodyID, b.BodyName,
       vd.Vehicle_Display_Name, [Year],
       vd.DriveTypeID, dt.DriveTypeName,
       vd.Engine, vd.Engine_CC, vd.Engine_Cylinders, vd.Engine_Liter_Display,
       vd.FuelTypeID, ft.FuelTypeName,
       vd.NumDoors
FROM VehicleDetails vd
INNER JOIN Makes m ON vd.MakeID = m.MakeID
INNER JOIN MakeModels mm ON vd.ModelID = mm.ModelID
INNER JOIN SubModels sm ON vd.SubModelID = sm.SubModelID
INNER JOIN Bodies b ON vd.BodyID = b.BodyID
INNER JOIN DriveTypes dt ON vd.DriveTypeID = dt.DriveTypeID
INNER JOIN FuelTypes ft ON vd.FuelTypeID = ft.FuelTypeID;
GO  -- separate again

SELECT * FROM VehicleMasterDetails;

-- Problem #2 - Get All Vehicle Between 1950 and 2000
SELECT * FROM VehicleMasterDetails
WHERE [Year] BETWEEN 1950 AND 2000;

-- Problem #3 - Get number vehicles made between 1950 and 2000
SELECT COUNT(*) AS NumberOfVehicles FROM VehicleDetails
WHERE [Year] BETWEEN 1950 AND 2000;

-- Problem #4 - Get number vehicles made between 1950 and 2000 per make and order them by Number Of Vehicles Descending
SELECT m.Make, COUNT(*) AS NumberOfVehicles FROM VehicleDetails vd
INNER JOIN Makes m ON vd.MakeID = m.MakeID
WHERE [Year] BETWEEN 1950 AND 2000
GROUP BY m.Make
ORDER BY NumberOfVehicles DESC;

-- Problem #5 - Get All Makes that have manufactured more than 12000 Vehicles in years 1950 to 2000
SELECT m.Make, COUNT(*) AS NumberOfVehicles FROM VehicleDetails vd
INNER JOIN Makes m ON vd.MakeID = m.MakeID
WHERE ([Year] BETWEEN 1950 AND 2000)
GROUP BY m.Make
HAVING COUNT(*) > 12000
ORDER BY NumberOfVehicles DESC;

-- Without having (Order by can't be placed in views or result tables (Subquery)
SELECT * FROM (
    SELECT m.Make, COUNT(*) AS NumberOfVehicles FROM VehicleDetails vd
    INNER JOIN Makes m ON vd.MakeID = m.MakeID
    WHERE ([Year] BETWEEN 1950 AND 2000)
    GROUP BY m.Make
) R1 -- We can treat R1 as a standalone table, apply joins, and ...etc.
WHERE R1.NumberOfVehicles > 12000
ORDER BY R1.NumberOfVehicles DESC;

-- Problem #6 - Get number of vehicles made between 1950 and 2000 per make and add total vehicles column beside
SELECT * FROM (
    SELECT m.Make, COUNT(*) AS NumberOfVehicles, (SELECT COUNT(*) FROM VehicleDetails) AS TotalVehicles FROM VehicleDetails vd
    INNER JOIN Makes m ON vd.MakeID = m.MakeID
    WHERE [Year] BETWEEN 1950 AND 2000
    GROUP BY m.Make
) R2 
ORDER BY R2.NumberOfVehicles DESC;
-- Lesson learned from this problem, we can treat entire query as a column

-- Problem #7 - Get number of vehicles made between 1950 and 2000 per make and add total vehicles column beside it,
-- then calculate it's percentage
SELECT * FROM (
    SELECT m.Make, COUNT(*) AS NumberOfVehicles, (SELECT COUNT(*) FROM VehicleDetails) AS TotalVehicles FROM VehicleDetails vd
    INNER JOIN Makes m ON vd.MakeID = m.MakeID
    WHERE [Year] BETWEEN 1950 AND 2000
    GROUP BY m.Make
) R2 
ORDER BY R2.NumberOfVehicles DESC;