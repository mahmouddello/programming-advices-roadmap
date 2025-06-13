#include <iostream>

using namespace std;

/*
	Problems Solution are in order, from #11 to #15.
*/

// ------------ Problem #11 - Average Pass/Fail ------------

enum enPassFail { Fail = 0, Pass = 1 };

void ReadMarks(int& mark1, int& mark2, int& mark3)
{
	cout << "Enter Mark1: ";
	cin >> mark1;

	cout << "Enter Mark2: ";
	cin >> mark2;

	cout << "Enter Mark3: ";
	cin >> mark3;

}

int CalculateSumOfMarks(int mark1, int mark2, int mark3)
{
	return mark1 + mark2 + mark3;
}

float CalculateAverage(int total)
{
	return (float)total / 3;
}

enPassFail CheckAverage(float avgGrade)
{
	if (avgGrade >= 50)
		return enPassFail::Pass;

	return enPassFail::Fail;
}

void PrintMarkResult(float avgGrade)
{
	cout << avgGrade << endl;

	if (CheckAverage(avgGrade) == enPassFail::Pass)
		cout << "You Passed" << endl;

	else
		cout << "You Failed" << endl;

}

// ------------ Problem #12 - Max of 2 Numbers ------------

void Read2Numbers(int& number1, int& number2)
{
	cout << "Please enter the first number: ";
	cin >> number1;

	cout << "Please enter the second number: ";
	cin >> number2;
}

int MaxOf2Numbers(int number1, int number2)
{
	// returns the max number

	if (number1 > number2)
		return number1;

	return number2;
}

void PrintCompareResults(int max)
{
	cout << "Tha Max is: " << max << endl;
}

// ------------ Problem #13 - Max of 3 Numbers ------------

void Read3Numbers(int& number1, int& number2, int& number3)
{
	cout << "Please enter the first number: ";
	cin >> number1;

	cout << "Please enter the second number: ";
	cin >> number2;

	cout << "Please enter the third number: ";
	cin >> number3;

}

int MaxOf3Numbers(int number1, int number2, int number3)
{
	// returns the max number

	if (number1 > number2 && number1 > number3)
		return number1;

	else if (number2 > number1 && number2 > number3)
		return number2;

	return number3;
}

void PrintMaxOf3(int max)
{
	cout << "Tha Max is: " << max << endl;
}

// ------------ Problem #14 - Swap 2 Numbers ------------

// Used Read2Numbers() function from Problem #12 (Re-Usability)

void Swap2Numbers(int& number1, int& number2)
{

	int temp;

	temp = number1;
	number1 = number2;
	number2 = temp;

}

void PrintSwap2NumbersResult(int number1, int number2)
{

	cout << "Number1 : " << number1 << endl;
	cout << "Number2 : " << number2 << endl;

	cout << "------------ After Swap ------------" << endl;

	Swap2Numbers(number1, number2);

	cout << "Number1 : " << number1 << endl;
	cout << "Number2 : " << number2 << endl;

}

// ------------ Problem #15 - Rectangle Area ------------

void ReadRectangle(float& width, float& height)
{
	
	cout << "Enter the width of the rectangle: ";
	cin >> width;

	cout << "Enter the height of the rectangle: ";
	cin >> height;

}

float CalculateRectangleArea(float width, float height)
{
	return width * height;
}

void PrintRectangleArea(int area)
{
	cout << "Rectangle Area = " << area << endl;
}

int main()
{

	float width, height;
	ReadRectangle(width, height);
	PrintRectangleArea(CalculateRectangleArea(width, height));

}
