USE CarData;

SELECT DISTINCT Make
FROM CarDetails
ORDER BY Make ASC;

CREATE TABLE Makes (
	MakeId INT IDENTITY (1,1) PRIMARY KEY,
	MakeName NVARCHAR(100) NOT NULL
);

-- Inserts the Makes data to the single MakeName Column automatically
INSERT INTO Makes
SELECT DISTINCT Make
FROM CarDetails
ORDER BY Make;

-- Create MakeId Column in the main table (Create the MakeId column from designer)
UPDATE CarDetails
SET MakeId = ( SELECT MakeId FROM Makes WHERE Makes.MakeName = CarDetails.Make);

SELECT * FROM CarDetails;

ALTER TABLE CarDetails
DROP COLUMN Make;

SELECT Makes.MakeName, CarDetails.* FROM CarDetails
INNER JOIN Makes ON Makes.MakeId = CarDetails.MakeId;