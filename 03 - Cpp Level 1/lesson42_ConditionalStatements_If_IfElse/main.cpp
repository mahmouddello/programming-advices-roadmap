#include <iostream>

using namespace std;

void IfStatementExplanation()
{
	int x = 10;

	cout << "x = " << x << endl;

	if (x > 5)
	{
		cout << "First if statement body (x > 5) has been executed" << endl;

	}

	// usage of logical operations in if statement

	if (x >= 5 && x <= 20)
	{
		cout << "Second if statement body (x >= 5 && x <= 20) has been executed" << endl;

	}

	if (x >= 5 || x <= 8)
	{
		cout << "Third if statement body (x >= 5 || x <= 8) has been executed" << endl;

	}

	cout << "This code will be executed anyway" << endl;

}

void IfElseStatementsExplanation()
{
	int y;

	cout << "Please enter y's value: ";
	cin >> y;

	if (y > 5)
	{
		cout << "Yes, y is greater than 5" << endl;
	}

	else
	{
		cout << "No, y is smaller than 5" << endl;

	}

	cout << "The code after if-else will got executed anyway" << endl;

}

// ------------- HOMEWORK -------------

void Problem4()
{
	// Problem #4 - Hire a Driver (Case 1)

	unsigned short age;
	bool hasDriverLicesne;

	cout << "Please enter your age: ";
	cin >> age;

	cout << "Please enter your driver license status ([0 or false], [true or 1]): ";
	cin >> hasDriverLicesne;

	if (age > 21 && hasDriverLicesne == true)
	{
		cout << "Accepted" << endl;
	}

	else {
		cout << "Rejected" << endl;
	}

}

void Problem8()
{
	// Problem #8 - Pass/Fail 

	float mark;

	cout << "Enter your mark: ";
	cin >> mark;

	if (mark >= 50)
		cout << "PASS" << endl;
	else
		cout << "FAIL" << endl;


}

void Problem11()
{

	// Problem #11 - Average Pass/Fail

	float mark1, mark2, mark3, avg;

	cout << "Enter your mark1 : ";
	cin >> mark1;

	cout << "Enter your mark2 : ";
	cin >> mark2;

	cout << "Enter your mark3 : ";
	cin >> mark3;

	avg = (mark1 + mark2 + mark3) / 3;

	if (avg >= 50)
		cout << "PASS" << endl;

	else
		cout << "FAIL" << endl;


}

void Problem24()
{
	// Problem #24 Validate Age Between 18 and 45

	unsigned short age;

	cout << "Enter your age: ";
	cin >> age;

	if (age >= 18 && age <= 45)
		cout << "Valid Age" << endl;
	else
		cout << "Invalid Age" << endl;

}

void Problem49()
{
	string password;

	cout << "Enter password: " << endl;
	cin >> password;

	if (password == "1234")
		cout << "Your Balance is 7500" << endl;

	else
		cout << "Wrong Password" << endl;
}

int main()
{
	Problem49();
}
