#include "homework17.h"
#include <iostream>

using namespace std;

void QuestionOne()
{

	string name = "Mahmoud Dello";
	int age = 21; // int is waste of memory here, we will discuss another types later on
	string city = "Mersin";
	string country = "Turkey";
	float monthlySalary = 5000;
	float yearlySalary = monthlySalary * 12; // 60000
	char gender = 'M';
	bool isMarried = true;

	cout << "Name: " << name << "\n";
	cout << "Age: " << age << "\n";
	cout << "City: " << city << "\n";
	cout << "Country: " << country << "\n";
	cout << "Monthly Salary: " << monthlySalary << "\n";
	cout << "Yearly Salary: " << yearlySalary << "\n";
	cout << "Gender: " << gender << "\n";
	cout << "Married: " << isMarried << endl;

}

void QuestionTwo()
{

	int x = 20, y = 30, z = 10;
	int sum = x + y + z;
	cout << x << " +\n" << y << " +\n" << z << "\n";
	cout << "--------------------------\n" << sum << endl;

}

void QuestionThree()
{
	
	int age = 25;
	cout << "After 5 years you will be " << age + 5 << " years old." << endl;

}