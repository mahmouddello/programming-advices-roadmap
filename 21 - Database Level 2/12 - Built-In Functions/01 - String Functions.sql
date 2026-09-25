USE C21_DB1;

-- ASCII: Returns the ASCII code value of the leftmost character of a character expression.
SELECT ASCII('A') AS A_ASCII_VALUE, ASCII('B') AS B_ASCII_VALUE;

/*
	CHAR: Returns the single-byte character with the specified integer code,
	as defined by the character set and encoding of the default collation of the current database.
*/
SELECT CHAR(65) AS A_CHAR

/*
	CONCAT: This function returns a string resulting from the concatenation, 
	or joining, of two or more string values in an end-to-end manner.	
*/
SELECT CONCAT('Happy ', 'Birthday ', 11, '/', '25') AS Result;

/*
	CONCAT_WS: This function returns a string resulting from the concatenation, 
	or joining, of two or more string values in an end-to-end manner. 
	It separates those concatenated string values with the delimiter specified in the first function argument. 
	(CONCAT_WS indicates concatenate with separator.)
*/
SELECT CONCAT_WS(' - ', [Name], [Position]) AS Result FROM dbo.Employees3;

/*
	FORMAT: Returns a value formatted with the specified format and optional culture. 
	Use the FORMAT function for locale-aware formatting of date/time and number values as strings. 
	For general data type conversions, use CAST or CONVERT.
*/
DECLARE @d AS DATE = GETDATE();

SELECT FORMAT(@d, 'd', 'en-US') AS 'US English',
	   FORMAT(@d, 'd', 'ar-QA') AS 'QA Arabic',
       FORMAT(@d, 'd', 'en-gb') AS 'British English',
       FORMAT(@d, 'd', 'de-de') AS 'German',
       FORMAT(@d, 'd', 'zh-cn') AS 'Chinese Simplified (PRC)';

SELECT FORMAT(@d, 'D', 'en-US') AS 'US English',
	   FORMAT(@d, 'D', 'ar-QA') AS 'QA Arabic',
       FORMAT(@d, 'D', 'en-gb') AS 'British English',
       FORMAT(@d, 'D', 'de-de') AS 'German',
       FORMAT(@d, 'D', 'zh-cn') AS 'Chinese Simplified (PRC)';

GO
DECLARE @d AS DATE = GETDATE();

SELECT FORMAT(@d, 'dd/MM/yyyy', 'ar-QA') AS 'Date',
       FORMAT(55447719, '+974 #### ####') AS 'Qatari Number Format';

-- RIGHT: Returns the right part of a character string with the specified number of characters.
SELECT RIGHT(Name, 3)   
FROM dbo.Employees3;

-- LEFT: Returns the left part of a character string with the specified number of characters.
SELECT LEFT(Name, 4)   
FROM dbo.Employees3;

SELECT LEFT('abcdefg',2);  

/*
	LEN: Returns the number of characters of the specified string expression, excluding trailing spaces.
	LEN excludes trailing spaces. If that is a problem, consider using the DATALENGTH function, which doesn't trim the string.
*/
SELECT LEN('Qatar')
SELECT LEN('Test of 22 characters ') -- 21 

-- LOWER: returns a character expression after converting uppercase character data to lowercase.
SELECT LOWER([Name]) FROM Employees2;

-- UPPER: returns a character expression after converting lowercase character data to uppercase.
SELECT UPPER([Name]) FROM Employees2;

-- RTRIM: Removes space character char(32) or other specified characters from the end of a string.
SELECT RTRIM('Five spaces are at the end of this string.    ');

-- LTRIM: Removes space character char(32) or other specified characters from the start of a string.
SELECT LTRIM('     Five spaces are at the beginning of this string.');

-- TRIM: Removes space character char(32) or other specified characters from the start and end of a string.
SELECT TRIM('     Five spaces are at the beginning and end of this string.     ');

-- NCHAR: Returns the Unicode character with the specified integer code, as defined by the Unicode standard.
DECLARE @nstring NCHAR(8);  
SET @nstring = N'København';  
SELECT UNICODE(SUBSTRING(@nstring, 2, 1)),   
   NCHAR(UNICODE(SUBSTRING(@nstring, 2, 1)));  
GO

/*
	PATINDEX: Returns the starting position of the first occurrence of a pattern in a specified expression, 
	or zero if the pattern isn't found, on all valid text and character data types.
*/
SELECT PATINDEX('%ter%', 'interesting data') AS position;

-- REPLACE: Replaces all occurrences of a specified string value with another string value.
SELECT REPLACE('abcdefghicde','cde','xxx');  

-- REPLICATE: Repeats a string value a specified number of times.
SELECT REPLICATE('Mahmoud ', 5);

-- REVERSE: Returns the reverse order of a string value.
SELECT REVERSE('Mahmoud');
SELECT REVERSE('racecar') -- palindrome

/*
	SOUNDEX: The SOUNDEX function in SQL Server converts a character string into a 
	4-character code based on how the word sounds in English, rather than how it is spelled.
	Review the docs for full picture.
*/
SELECT SOUNDEX('Smith') AS Code1, SOUNDEX('Smyth') AS Code2;

-- SPACE: Returns a string of repeated spaces.
SELECT (('Hello') + SPACE(2) + 'World');

/*
	STR: Returns character data converted from numeric data. 
		The character data is right-justified, with a specified length and decimal precision.
*/
SELECT STR(123.45, 6, 1); 
SELECT STR(123.45, 2, 2);  

/*
	STRING_AGG: Concatenates the values of string expressions and places separator values between them.
	The separator isn't added at the end of string.
*/

SELECT STRING_AGG([Name] + ' - ' + CAST([HireDate] AS VARCHAR), ',') FROM Employees;

/*
	STRING_ESCAPE: Escapes special characters in texts and returns text with escaped characters. 
	STRING_ESCAPE is a deterministic function first introduced in SQL Server 2016.
*/
SELECT STRING_ESCAPE('\   /  \\    "     ', 'json') AS escapedText;


/*
	STUFF: The STUFF function inserts a string into another string. 
	It deletes a specified length of characters in the first string
	at the start position and then inserts the second string into the first string at the start position.
*/

SELECT STUFF('abcdef', 2, 3, 'ijklmn');