#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;


void DoubleToIntegerExample()
{

	int num1;
	int num2 = 18.99;

	num1 = num2; // implicit conversion from double to int

	//num1 = (int)num2; // explicit conversion

	//num1 = int(num2); // another way of explicit conversion

	cout << num1 << endl;

}

void StringToIntDoubleFloatExample()
{
	string str = "123.456";

	// Convert string to integer
	int num_int = stoi(str);

	// Convert string to float
	float num_float = stof(str);

	// Convert string to double
	double num_double = stod(str);

	// Output the results
	cout << "Original String = \"" << str << "\"" << endl;
	cout << "num int = " << num_int << endl;
	cout << "num float = " << num_float << endl;
	cout << "num double = " << num_double << endl;

}

void NumberToString()
{

	int num1 = 123;
	double num2 = 18.99;

	string num1_string, num2_string;

	num1_string = to_string(num1);
	num2_string = to_string(num2);

	cout << num1_string << endl;
	cout << num2_string << endl;

}

// ------------- HOMEWORK -------------

void Homework()
{
	// Q1

	string st1 = "43.22";

	int st1_int = stoi(st1);
	float st1_float = stof(st1);
	double st1_double = stod(st1);

	cout << "st1 int = " << st1_int << endl;
	cout << "st1 float = " << st1_float << endl;
	cout << "st1 double = " << st1_double << endl;

	cout << "-----------------------------" << endl;

	// Q2
	int n1 = 20;
	string n1_str = to_string(n1);

	cout << n1_str << endl;
	cout << "-----------------------------" << endl;

	// Q3

	double n2 = 33.5;
	string n2_str = to_string(n2);

	cout << n2_str << endl;
	cout << "-----------------------------" << endl;

	// Q4
	float n3 = 55.23;

	string n3_string = to_string(n3);
	cout << "n3_string = " << n3_string << endl;

	int n3Int = n3;
	int n3IntExplicitCtype = (int)n3;
	int n3IntExplicitFunc = int(n3);

	cout << n3Int << endl;
	cout << n3IntExplicitCtype << endl;
	cout << n3IntExplicitFunc << endl;

}


int main()
{
	Homework();
	return 0;
}
