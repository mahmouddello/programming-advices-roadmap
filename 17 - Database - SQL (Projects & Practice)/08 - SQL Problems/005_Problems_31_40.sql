USE VehicleMakesDB;

-- Problem #31: Get all Vehicle_Display_Name, year and add extra column to calculate the age of the car then sort the results by age desc.
SELECT
	vd.Vehicle_Display_Name,
	vd.Year,
	Age = YEAR(GETDATE()) - vd.Year
FROM
	VehicleDetails AS vd
ORDER BY
	Age DESC;

--  Problem 32: Get all Vehicle_Display_Name, year, Age for vehicles that their age between 15 and 25 years old 
SELECT
	vd.Vehicle_Display_Name,
	vd.Year,
	Age = YEAR(GETDATE()) - vd.Year
FROM
	VehicleDetails AS vd
WHERE 
	YEAR(GETDATE()) - vd.Year BETWEEN 15 AND 25;

--  Problem #33: Get Minimum Engine CC , Maximum Engine CC , and Average Engine CC of all Vehicles 
SELECT
	MIN(vd.Engine_CC) AS MinEnginceCC,
	AVG(vd.Engine_CC) AS AvgEngineCC,
	MAX(vd.Engine_CC) AS MaxEngineCC
FROM
	VehicleDetails AS vd

-- Problem #34: Get all vehicles that have the minimum Engine_CC
SELECT 
	*
FROM
	VehicleDetails
WHERE
	Engine_CC = (SELECT MIN(Engine_CC) FROM VehicleDetails);

-- Problem #35: Get all vehicles that have the Maximum Engine_CC 
SELECT 
	*
FROM
	VehicleDetails
WHERE
	Engine_CC = (SELECT MAX(Engine_CC) FROM VehicleDetails);

-- Problem #36: Get all vehicles that have Engin_CC below average
SELECT 
	*
FROM
	VehicleDetails
WHERE
	Engine_CC < (SELECT AVG(Engine_CC) FROM VehicleDetails);

-- Problem #37: Get total vehicles that have Engin_CC above average
SELECT 
	COUNT(*) AS TotalAboveAvgEngineCC
FROM
	VehicleDetails
WHERE
	Engine_CC > (SELECT AVG(Engine_CC) FROM VehicleDetails);

-- Problem #38: Get all unique Engin_CC and sort them Desc
SELECT DISTINCT
	vd.Engine_CC
FROM
	VehicleDetails AS vd
ORDER BY 
	vd.Engine_CC DESC;

--  Problem #39: Get the maximum 3 Engine CC 
SELECT DISTINCT TOP 3
	Engine_CC
FROM
	VehicleDetails
ORDER BY 
	Engine_CC DESC;

-- Problem #40: Get all vehicles that has one of the Max 3 Engine CC 
SELECT 
	*
FROM 
	VehicleDetails
WHERE 
	Engine_CC IN 
(
		SELECT DISTINCT TOP 3
			Engine_CC
		FROM
			VehicleDetails
		ORDER BY 
			Engine_CC DESC
);