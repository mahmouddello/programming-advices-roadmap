#include <iostream>
#include <cmath>

using namespace std;

/*
	Problem Solution in order: from #16 to #20
*/

// -------- Problem #16 - Rectangle area Through Diagonal and Side Area --------

void ReadRectangleInfo(float& a, float& d)
{
	
	cout << "Please enter a's value: ";
	cin >> a;

	cout << "Please enter d's value: ";
	cin >> d;

}

float CalculateRectangleArea(float a, float d)
{
	return a * sqrt(pow(d, 2) - pow(a, 2));
}

void PrintRectangleAreaResult(float area)
{
	cout << "Area = " << area << endl;
}

// -------- Problem #17 - Triangle Area --------

void ReadTringleInfo(float& a, float& h)
{

	cout << "Please enter a's value: ";
	cin >> a;

	cout << "Please enter h's value: ";
	cin >> h;

}

float CalculateTringleArea(float a, float h)
{
	return (a / 2) * h;
}

void PrintTringleAreaResult(float area)
{
	cout << "Tringle Area = " << area << endl;
}

// -------- Problem #18 Circle Area --------

float ReadRadius()
{
	float r;

	cout << "Enter the value of the radius of the circle: ";
	cin >> r;

	return r;
}

float CalculateCircleArea(float r)
{
	const float PI = 3.14;

	return PI * pow(r, 2);

}

void PrintCircleArea(float area)
{
	cout << "Circle Area = " << area << endl;

}

// -------- Problem #19 - Circle Area Through Diameter --------

float ReadDiameter()
{
	float d;

	cout << "Enter the diameter value: ";
	cin >> d;

	return d;

}

float CircleAreaThroughDiameter(float d)
{
	const float PI = 3.14;

	return (PI * pow(d, 2)) / 4;
}

// Use Circle Area From Problem #18

// -------- Problem #20 Circle Area Inscribed in a Square --------

float ReadSquareSide()
{
	int A;

	cout << "Enter side of the square (A's) value: ";
	cin >> A;

	return A;

}

float CircleAreaInscribedInSquare(float A)
{
	const float PI = 3.14;

	return (PI * pow(A, 2)) / 4;
}

// Use Circle Area From Problem #18

int main()
{
	PrintCircleArea(CircleAreaInscribedInSquare(ReadSquareSide()));
	return 0;
}
