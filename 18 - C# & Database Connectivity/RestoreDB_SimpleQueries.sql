RESTORE DATABASE ContactsDB
FROM DISK = 'D:\ProgrammingAdvices\roadmap\18 - C# & Database Connectivity\ContactsDB.bak'
WITH RECOVERY;

USE ContactsDB;

EXEC sp_changedbowner 'sa'; -- fix diagram issue

SELECT * FROM Contacts;

SELECT 
	* 
FROM
	Contacts
WHERE
	FirstName = 'Jane'
	AND
	CountryID = 1;