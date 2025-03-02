#include<iostream>
#include "D:\MyCPP_Libs\InputsLib.h"


using namespace std;

int main()
{
	int Mark = 90;
	string result;

	//Using normal if
	if (Mark >= 50)
	{
		result = "PASS";
	}

	else
	{
		result = "FAIL";
	}

	cout << result << endl;

	//Using Short Hand IF
	result = (Mark >= 50) ? "PASS" : "FAIL";
	cout << result << endl;
	cout << "---------------" << endl;

	// --------- HOMEWORK ---------

	// 1 - Check if negative or positive

	int number1 = InputsLib::ReadNumber("Enter a number?");
	string result1;
	
	result1 = (number1 > 0) ? "Positive" : "Negative";
	cout << "The number1 " << number1 << " is " << result1 << endl;

	// 2 - Check if equals zero, then check if positive or negative (nested ternary operators)

	int number2 = InputsLib::ReadNumber("Enter another number?\n");
	string result2;

	result2 = (number2 == 0) ? "Zero" : (number2 > 0) ? "Positive" : "Negative";
	cout << "The number2 " << number2 << " is " << result2 << endl;

	return 0;
}