#include <iostream>

// Procedures VS Functions

using namespace std;

void ExampleProcedure()
{
	cout << "This is an example procedure, it doesn't return any value." << endl;
}

void PrintDivider()
{
	// Another example of a procedure ;)

	cout << "----------------------" << endl;
}

string  MyFunction()
{
	return "This is my function number 1, and it returns string, it's this value.";
}

int MyFunction2()
{
	int x = 10, y = 20;

	return x * y;
}

// ------------------- HOMEWORK -------------------

void MySumProcedure()
{
	int num1, num2;

	cout << "Please enter number 1: ";
	cin >> num1;

	cout << "Please enter number 2: ";
	cin >> num2;

	cout << "**********************" << endl;
	cout << num1 + num2 << endl;

}

int MySumFunction()
{
	int num1, num2;

	cout << "Please enter number 1: ";
	cin >> num1;

	cout << "Please enter number 2: ";
	cin >> num2;
	
	cout << "**********************" << endl;

	return num1 + num2;

}

int main()
{
	//// Procedures
	//ExampleProcedure();
	//PrintDivider();

	//// Functions
	//cout << MyFunction() << endl;
	//cout << MyFunction2() << endl;
	//PrintDivider();

	//// We can manipulate the returned value from any function
	//cout << MyFunction2() + 50 << endl;
	//cout << MyFunction2() / 50 << endl;
	//cout << MyFunction2() + 45.5 << endl; // implicit type conversion
	//cout << MyFunction2() + true << endl; // implicit type conversion

	MySumProcedure();
	PrintDivider();

	cout << MySumFunction() << endl;

	return 0;
}