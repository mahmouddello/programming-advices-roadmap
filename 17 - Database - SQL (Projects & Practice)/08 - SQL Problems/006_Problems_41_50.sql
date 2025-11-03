USE VehicleMakesDB;

-- Problem #41: Get all Makes that manufactures one of the Max 3 Engine CC
SELECT DISTINCT
	m.Make
FROM
	VehicleDetails vd
INNER JOIN 
	Makes m ON vd.MakeID = m.MakeID
WHERE
	vd.Engine_CC IN
(
	SELECT DISTINCT TOP 3
			Engine_CC
		FROM
			VehicleDetails
		ORDER BY 
			Engine_CC DESC
)
ORDER BY 
	m.Make;

-- Problem #42: Get a table of unique Engine_CC and calculate tax per Engine CC as follows:
	-- 0 to 1000    Tax = 100
	-- 1001 to 2000 Tax = 200
	-- 2001 to 4000 Tax = 300
	-- 4001 to 6000 Tax = 400
	-- 6001 to 8000 Tax = 500
	-- Above 8000   Tax = 600
	-- Otherwise    Tax = 0
SELECT DISTINCT
	vd.Engine_CC,
	CASE
		WHEN vd.Engine_CC BETWEEN 0 AND 1000 THEN 100
		WHEN vd.Engine_CC BETWEEN 1001 AND 2000 THEN 200
		WHEN vd.Engine_CC BETWEEN 2001 AND 4000 THEN 300
		WHEN vd.Engine_CC BETWEEN 4001 AND 1000 THEN 400
		WHEN vd.Engine_CC BETWEEN 6001 AND 8000 THEN 500
		WHEN vd.Engine_CC > 8000 THEN 600
		ELSE 0
	END AS TaxPerEngine
FROM
	VehicleDetails AS vd
ORDER BY 
	vd.Engine_CC;

--  Problem #43: Get Make and Total Number Of Doors Manufactured Per Make
SELECT 
	m.Make,
	SUM(vd.NumDoors) AS TotalNumberOfDoors
FROM 
	VehicleDetails AS vd
INNER JOIN
	Makes AS m ON vd.MakeID = m.MakeID
GROUP BY
	m.Make
ORDER BY 
	TotalNumberOfDoors DESC;

--  Problem #44: Get Total Number Of Doors Manufactured by 'Ford' 
SELECT 
	m.Make,
	SUM(vd.NumDoors) AS TotalNumberOfDoors
FROM 
	VehicleDetails AS vd
INNER JOIN
	Makes AS m ON vd.MakeID = m.MakeID
WHERE
	m.Make = 'Ford'
GROUP BY
	m.Make
ORDER BY 
	TotalNumberOfDoors DESC;

--  Problem #45: Get Number of Models Per Make
SELECT
	m.Make,
	COUNT(mm.ModelID) AS ModelsPerMake
FROM
	Makes AS m
INNER JOIN 
	MakeModels AS mm ON m.MakeID = mm.MakeID
GROUP BY
	m.Make
ORDER BY
	m.Make ASC,
	ModelsPerMake DESC;

-- Problem #46: Get the highest 3 manufacturers that make the highest number of models
SELECT TOP 3
	m.Make,
	COUNT(mm.ModelID) AS ModelsPerMake
FROM
	Makes AS m
INNER JOIN 
	MakeModels AS mm ON m.MakeID = mm.MakeID
GROUP BY
	m.Make
ORDER BY
	ModelsPerMake DESC;

-- Problem #47: Get the highest number of models manufactured 
SELECT TOP 1
	m.Make,
	COUNT(mm.ModelID) AS ModelsPerMake
FROM
	Makes AS m
INNER JOIN 
	MakeModels AS mm ON m.MakeID = mm.MakeID
GROUP BY
	m.Make
ORDER BY
	ModelsPerMake DESC;

-- Problem 48: Get the highest Manufacturers manufactured the highest number of models,
-- remember that they could be more than one manufacturer have the same high number of models 
SELECT 
	Makes.Make,
	COUNT(*) AS NumberOfModels
FROM
	Makes
INNER JOIN
	MakeModels ON Makes.MakeID = MakeModels.MakeID
GROUP BY 
	Makes.Make
HAVING 
	COUNT(*) =
(
	SELECT 
		MAX(R3.ModelsPerMake) AS MaxOfModels
	FROM
	(
		SELECT
			mm.MakeID,
			COUNT(*) AS ModelsPerMake
		FROM
			MakeModels AS mm
		GROUP BY 
			mm.MakeID
	) R3
)

--  Problem 49: Get the Lowest Manufacturers manufactured the lowest number of models 
SELECT 
	Makes.Make,
	COUNT(*) AS NumberOfModels
FROM
	Makes
INNER JOIN
	MakeModels ON Makes.MakeID = MakeModels.MakeID
GROUP BY 
	Makes.Make
HAVING 
	COUNT(*) =
(
	SELECT 
		MIN(R3.ModelsPerMake) AS MaxOfModels
	FROM
	(
		SELECT
			mm.MakeID,
			COUNT(*) AS ModelsPerMake
		FROM
			MakeModels AS mm
		GROUP BY 
			mm.MakeID
	) R3
)

--  Problem 50: Get all Fuel Types , each time the result should be showed in random order
SELECT
	*
FROM
	FuelTypes
ORDER BY NEWID();