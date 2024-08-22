#include <iostream>
#include <string>

using namespace std;

void Problem33()
{
	// Problem #33 Grade A, B, C, D, E, F

	float grade;

	cout << "Enter your grade: ";
	cin >> grade;

	if (grade >= 90)
		cout << "A" << endl;

	else if (grade >= 80)
		cout << "B" << endl;

	else if (grade >= 70)
		cout << "C" << endl;

	else if (grade >= 60)
		cout << "D" << endl;

	else if (grade >= 50)
		cout << "E" << endl;

	else
		cout << "F" << endl;

}

void Problem34()
{
	// Problem #34 - Commission Percentage
	float totalSales;

	cout << "Input Total Sales: ";
	cin >> totalSales;

	if (totalSales > 1'000'000) // 1 million
		cout << totalSales * 0.01 << endl;

	else if (totalSales >= 500000)
		cout << totalSales * 0.02 << endl;

	else if (totalSales >= 100000)
		cout << totalSales * 0.03 << endl;

	else if (totalSales >= 50000)
		cout << totalSales * 0.05 << endl;

	else
		cout << totalSales << endl;

}

float Problem36()
{
	// Problem #36 - Simple Calculator
	float  num1, num2;
	char operation, operations[] = { '+', '-', '*', '/' };

	cout << "Enter First Number: ";
	cin >> num1;

	cout << "Enter Second Number: ";
	cin >> num2;

	cout << "Enter operations (+, -, *, /): ";
	cin >> operation;

	if (operation == '+')
		return num1 + num2;

	else if (operation == '-')
		return num1 - num2;

	else if (operation == '*')
		return num1 * num2;

	else if (operation == '/')
		return num1 / num2;


	cout << "Wrong Operation!\n";
	return 0;

}

void Problem44()
{
	// Problem #44 - Day Of Week
	int choice;

	cout << "Enter day number: ";
	cin >> choice;

	if (choice == 1)
		cout << "Sunday" << endl;

	else if (choice == 2)
		cout << "Monday" << endl;

	else if (choice == 3)
		cout << "Tuesday" << endl;

	else if (choice == 4)
		cout << "Wednesday" << endl;

	else if (choice == 5)
		cout << "Thursday" << endl;

	else if (choice == 6)
		cout << "Friday" << endl;

	else if (choice == 7)
		cout << "Saturday" << endl;

	else
		cout << "Wrong Input!\n";

}

int main()
{
	Problem44();
	return 0;
}