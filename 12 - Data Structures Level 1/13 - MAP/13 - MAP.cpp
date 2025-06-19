#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
	map<string, int> studentsGrades;

	//by default the map sort the elements of this associative array as ascending order in alphabetical sense.
	//Abdu before Mohammed and so on as you will see in the result of console out screen.
	studentsGrades["Mohammed Almislaty"] = 100;
	studentsGrades["Abdu"] = 96;
	studentsGrades["Aziz"] = 78;
	studentsGrades["Mohammed Jamil"] = 87;

	//we should use auto because in maps we will more than data type at once 
	//so it's key and value data structure which use auto data type will the best for sure.
	for (const auto& pair : studentsGrades)
	{
		cout << "Student Name :  " << left << setw(25) << pair.first << "\t  Mark :  " << pair.second << endl;
	}

	string name = "Fadi";

	cout << "\n\nFadi Grade Is ? :  \n";

	if (studentsGrades.find(name) != studentsGrades.end())
	{
		cout << studentsGrades.at(name) << endl;
	}

	else
	{
		cout << name << " Grade Is Not Found :-(\n";
	}

	name = ("Mohammed Almislaty");

	cout << "\n\nMohammed Almislaty Grade Is ? : \n";

	(studentsGrades.find(name) != studentsGrades.end()) ? cout << studentsGrades.at(name) << endl :
		cout << name << " Grade Is Not Found :-(\n";


	studentsGrades["Mohammed Almislaty"] = 100;
	studentsGrades["Abdu"] = 96;
	studentsGrades["Aziz"] = 78;
	studentsGrades["Mohammed Jamil"] = 87;


	cout << endl << endl;
	//read only foreach loop to forbid the teacher from acting the wrong action against his/her students.
	for (const auto& student : studentsGrades)
	{
		//now we prevent any edit could happens on students data from any one and let the data showed only as read only property.
		//student.second -= 10;

		cout << "Student Name : " << left << setw(25) << student.first << " \t  Mark  : " << student.second << endl << endl;
	}

	cout << endl << endl;

	//The proper of explicitily dealing with complex data structures like maps without using auto
	for (pair<const string, int>& grade : studentsGrades)
	{
		grade.second -= 5;

		cout << "Student Name : " << left << setw(25) << grade.first << " \t  Mark  : " << grade.second << endl;
	}

	for (pair<const string, int>& gradeOf : studentsGrades)
	{
		gradeOf.second += 5;
	}

	cout << endl << endl;

	//read only
	for (const pair<const string, int>& gradeOfStudent : studentsGrades)
	{
		//prevent modification.
		//gradeOfStudent.second += 5;

		cout << "Student Name : " << left << setw(25) << gradeOfStudent.first << " \t  Mark  : " << gradeOfStudent.second << endl << endl;
	}

	system("pause > 0");
	return 0;
}