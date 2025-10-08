USE VehicleMakesDB;

-- Investigate each table content
SELECT * FROM Makes; -- Represents car manufacturers (e.g., Toyota, BMW, Ford).
SELECT * FROM MakeModels; -- Represents the models belonging to each manufacturer (e.g., Corolla, X5, Focus).
SELECT * FROM SubModels; -- Represents the sub-versions or trims of a model (e.g., Corolla Hybrid, X5 Sport).
SELECT * FROM FuelTypes; -- Represents fuel types (e.g., Gasoline, Diesel, Electric, Hybrid).
SELECT * FROM Bodies;-- Represents car body types or shapes (e.g., Sedan, SUV, Hatchback).
SELECT * FROM DriveTypes; -- Represents the car’s drive systems (e.g., Front-Wheel Drive FWD, Rear-Wheel Drive RWD, All-Wheel Drive AWD).
SELECT * FROM VehicleDetails; -- Represents the complete details of each vehicle, linking the manufacturer, model, submodel, 
-- body type, fuel type, and drive system — along with specifications such as manufacturing year, engine size, 
-- number of cylinders, number of doors, etc.

--------------------------------------------------
-- LEVEL 1 — Basic SELECT & Filtering
--------------------------------------------------

-- 1. List all car makes in the database.
SELECT Make FROM Makes;

-- 2. Show all available models and their associated make IDs.
SELECT MakeId, ModelName FROM MakeModels;

-- 3. Display all vehicle body types.
SELECT * FROM Bodies;

-- 4. List all available fuel types.
SELECT * FROM FuelTypes;

-- 5. Find all vehicles produced in the year 2020.
SELECT * FROM VehicleDetails WHERE [Year] = 2020;

-- 6. Show all distinct years available in the vehicle details.
SELECT DISTINCT [Year]
FROM VehicleDetails 
ORDER BY [Year];

-- 7. Find all vehicles that have an engine capacity greater than 2000 CC.
SELECT * FROM VehicleDetails WHERE Engine_CC > 2000;

-- 8. Display all vehicles that have exactly 4 doors.
SELECT * FROM VehicleDetails WHERE NumDoors = 4;

-- 9. List all vehicles with missing or NULL submodel information.
SELECT * FROM VehicleDetails WHERE SubModelID IS NULL;

-- 10. Show all vehicles ordered by year in descending order.
SELECT * FROM VehicleDetails
ORDER BY [Year] DESC;

--------------------------------------------------
-- LEVEL 2 — Simple Joins, Filtering, and Sorting
--------------------------------------------------

-- 11. Show all models along with their make names.
SELECT Makes.Make, MakeModels.ModelName FROM MakeModels
INNER JOIN Makes ON Makes.MakeID = MakeModels.MakeID;

-- 12. List all submodels together with their model names.
SELECT MakeModels.ModelName, SubModels.SubModelName FROM SubModels
INNER JOIN MakeModels ON MakeModels.ModelID = SubModels.ModelID;

-- 13. Display all vehicles along with their corresponding body type names.
SELECT Vehicle_Display_Name, [Year], Bodies.BodyName FROM VehicleDetails
INNER JOIN Bodies ON VehicleDetails.BodyID = Bodies.BodyID;

-- 14. Show all vehicles and their drive type names.
SELECT Vehicle_Display_Name, [Year], Bodies.BodyName, DriveTypes.DriveTypeName
FROM VehicleDetails
INNER JOIN Bodies ON VehicleDetails.BodyID = Bodies.BodyID
INNER JOIN DriveTypes ON VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID;

-- 15. Find all vehicles that use the “Diesel” fuel type.
SELECT Vehicle_Display_Name, [Year], ft.FuelTypeName
FROM VehicleDetails vd
INNER JOIN FuelTypes ft ON vd.FuelTypeID = ft.FuelTypeID WHERE FuelTypeName = 'Diesel';

-- 16. Display all vehicles of a specific make (e.g., Toyota).
SELECT Makes.Make, Vehicle_Display_Name, [Year] From VehicleDetails
INNER JOIN Makes ON Makes.MakeID = VehicleDetails.MakeID
WHERE Makes.Make = 'Toyota';

-- 17. List all vehicles with engine sizes between 1500 and 3000 CC.
SELECT Vehicle_Display_Name, [Year], Engine_CC
FROM VehicleDetails
WHERE Engine_CC BETWEEN 1500 AND 3000;

-- 18. Show all vehicles that have 6 or more cylinders.
SELECT Vehicle_Display_Name, [Year], Engine_Cylinders
FROM VehicleDetails
WHERE Engine_Cylinders >= 6;

-- 19. Display all vehicles of a specific drive type (e.g., AWD).
SELECT Vehicle_Display_Name, [Year], dt.DriveTypeName
FROM VehicleDetails vd
INNER JOIN DriveTypes dt ON vd.DriveTypeID = dt.DriveTypeID WHERE dt.DriveTypeName = 'AWD';

-- 20. Show all vehicles with model names containing the word “Sport”.
SELECT Vehicle_Display_Name, [Year]
FROM VehicleDetails
WHERE Vehicle_Display_Name LIKE '%Sport%';