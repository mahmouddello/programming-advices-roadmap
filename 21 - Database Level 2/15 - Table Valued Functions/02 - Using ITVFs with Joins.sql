USE C21_DB1;

SELECT
	S.Name AS StudentName,
	T.Name AS TeacherName,
	S.Subject
FROM dbo.GetStudentsBySubject('Math') AS S
INNER JOIN Teachers AS T
	ON T.Subject = S.Subject;