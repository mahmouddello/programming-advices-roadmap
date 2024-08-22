#include <iostream>
using namespace std;

void IntroCode()
{

	int day = 4; // Initialize day variable
	switch (day) {
	case 1:
		cout << "Monday";
		break;
	case 2:
		cout << "Tuesday";
		break;
	case 3:
		cout << "Wednesday";
		break;
	case 4:
		cout << "Thursday";
		break;
	case 5:
		cout << "Friday";
		break;
	case 6:
		cout << "Saturday";
		break;
	case 7:
		cout << "Sunday";
		break;
	default:
		cout << "Not a valid day of the week!";
		break;
	}

}

// ------------ HOMEWORK ------------

void Problem36()
{
	// Problem 36 - Simple Calculator


	// Problem #36 - Simple Calculator
	float  num1, num2;
	char operation;

	cout << "Enter First Number: ";
	cin >> num1;

	cout << "Enter Second Number: ";
	cin >> num2;

	cout << "Enter operation (+, -, *, /): ";
	cin >> operation;

	switch (operation)
	{

	case '+':
		cout << num1 + num2 << endl;
		break;

	case '-':
		cout << num1 - num2 << endl;
		break;

	case '*':
		cout << num1 * num2 << endl;
		break;

	case '/':
		cout << num1 / num2 << endl;
		break;

	default:
		cout << "Wrong Operation" << endl;
	}
}

void Problem44()
{

	// Problem #44 - Day Of Week
	cout << "Input day number: ";

	short day;
	cin >> day;

	switch (day)
	{

	case 1:
		cout << "Sunday" << endl;
		break;


	case 2:
		cout << "Monday" << endl;
		break;

	case 3:
		cout << "Tuesday" << endl;
		break;

	case 4:
		cout << "Wednesday" << endl;
		break;

	case 5:
		cout << "Thursday" << endl;
		break;

	case 6:
		cout << "Friday" << endl;
		break;

	case 7:
		cout << "Saturday" << endl;
		break;

	default:
		cout << "Wrong day number!" << endl;

	}

}

int main()
{
	Problem44();
	return 0;
}
