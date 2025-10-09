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

--------------------------------------------------
-- LEVEL 3 — Multi-table Joins & Aggregation
--------------------------------------------------

-- 21. List each vehicle with its make, model, and submodel names.
SELECT vd.Vehicle_Display_Name, m.Make, mm.ModelName, sm.SubmodelName
FROM VehicleDetails vd
INNER JOIN Makes m ON vd.MakeID = m.MakeID
INNER JOIN MakeModels mm ON vd.ModelID = mm.ModelID
INNER JOIN SubModels sm ON vd.SubModelID = sm.SubModelID;

-- 22. Find all models that belong to a given make.
SELECT m.Make, mm.ModelName FROM Makes m
INNER JOIN MakeModels mm ON m.MakeID = mm.MakeID WHERE m.Make = 'Toyota';

-- 23. Show all body types used by a specific make.
SELECT DISTINCT m.Make, bt.BodyName FROM VehicleDetails vd
INNER JOIN Makes m on vd.MakeID = m.MakeID
INNER JOIN Bodies bt ON vd.BodyID = bt.BodyID
WHERE m.Make = 'Toyota';

-- 24. Count how many vehicles exist for each make.
SELECT m.Make, COUNT(*) AS MakeCount FROM VehicleDetails vd
INNER JOIN Makes m on vd.MakeID = m.MakeID
GROUP BY m.Make
ORDER BY MakeCount DESC;

-- 25. Display the number of vehicles for each fuel type.
SELECT ft.FuelTypeName, COUNT(*) AS FuelTypeCount FROM VehicleDetails vd
INNER JOIN FuelTypes ft on vd.FuelTypeID = ft.FuelTypeID
GROUP BY ft.FuelTypeName;

-- 26. Find all makes that have more than 10 vehicles in the database. (Replace subquery with HAVING)
SELECT * FROM
	(SELECT m.Make, COUNT(*) AS MakeCount FROM VehicleDetails vd
	INNER JOIN Makes m on vd.MakeID = m.MakeID
	GROUP BY m.Make) AS DataTable
WHERE DataTable.MakeCount > 10
ORDER BY DataTable.MakeCount ASC;

-- 27. Show the total number of submodels available for each model.
SELECT mm.ModelName, COUNT(sm.SubModelId) As TotalSubmodels FROM MakeModels mm
INNER JOIN SubModels sm ON sm.ModelID = mm.ModelID
GROUP BY mm.ModelName;

-- 28. Find the average engine capacity per make.
SELECT m.Make, AVG(vd.Engine_Liter_Display) As AverageEngineCapacityPerMake FROM VehicleDetails vd
INNER JOIN Makes m on vd.MakeID = m.MakeID
GROUP BY m.Make;

-- 29. List all makes that use more than three different body types. (Replace subquery with HAVING)
SELECT * FROM (SELECT m.Make, COUNT(DISTINCT(vd.BodyID)) As DifferentBodyCount FROM VehicleDetails vd
INNER JOIN Makes m on vd.MakeID = m.MakeID
GROUP BY m.Make) as dt
WHERE dt.DifferentBodyCount > 3;

-- 30. Show which makes have vehicles from more than five different years. (Replace subquery with HAVING)
SELECT * FROM (SELECT m.Make, COUNT(DISTINCT(vd.Year)) As differentYears FROM VehicleDetails vd
INNER JOIN Makes m on vd.MakeID = m.MakeID
GROUP BY m.Make) AS dt
WHERE dt.differentYears > 5;