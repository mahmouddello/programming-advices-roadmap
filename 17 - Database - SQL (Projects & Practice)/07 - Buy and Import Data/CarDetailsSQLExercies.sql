USE CarData;

-- Display all cars that were manufactured after the year 2018.
SELECT * FROM CarDetails
WHERE [Year] > 2018;

-- Find all cars of type Ford or Chevrolet that have 6 cylinders.
SELECT * FROM CarDetails
WHERE Make IN ('Chevrolet', 'Ford') AND Engine_Cylinders = 6;

-- Calculate the average number of cylinders for all cars in the table.
SELECT AVG(Engine_Cylinders) AS AverageCylinders FROM CarDetails;

-- Show all car models that have an engine capacity greater than 3.0 liters.
SELECT * FROM CarDetails
WHERE Engine_Liter_Display > 3.0;

-- What is the highest number of doors in any car?
SELECT MAX(NumDoors) AS HighestDoorCount
FROM CarDetails;

-- Count the number of cars for each manufacturing year and sort the results from newest to oldest.
SELECT [Year], COUNT(*) AS NumberOfManufacturedCars
FROM CarDetails
GROUP BY [Year]
ORDER BY [Year] DESC;

-- Display all cars whose engine type is “V” and sort the results by model.
SELECT * FROM CarDetails
WHERE Engine_Block_Type = 'V'
ORDER BY Model;

-- Display the top 5 most common car models in the table, along with the count of each model.
SELECT TOP 5 Make, Model, COUNT(Model) AS ModelCount
FROM CarDetails
GROUP BY Make, Model
ORDER BY ModelCount DESC;
