#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct stSecondsFormats {

	unsigned int secondsInDay = 24 * pow(60, 2);
	unsigned int secondsInHour = pow(60, 2);
	unsigned int secondsInMinutes = 60;

};

int MySumFunction(int Num1, int Num2)
{
	return Num1 + Num2;
}

// ----------------- HOMEWORK -----------------

void Problem1()
{
	// Problem #1 - Write your name on screen
	cout << "Mahmoud Dello" << endl;
}

void Problem2()
{
	string name;

	cout << "Please enter your name: " << endl;
	getline(cin, name);

	cout << "Your name is: " << name << endl;
}

void Problem14()
{
	// Problem #14 - Swap 2 Numbers
	int num1, num2, temp;

	cin >> num1;
	cin >> num2;

	cout << "Num1: " << num1 << endl;
	cout << "Num2: " << num2 << endl;

	cout << "------------ AFTER SWAP ---------" << endl;

	temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "Num1: " << num1 << endl;
	cout << "Num2: " << num2 << endl;

}

int Problem15(int a, int b)
{
	// Problem #15 - Rectangle Area

	int area = a * b;

	return area;

}

float Problem16(float a, float d)
{
	// Problem #16 - Rectangle area Through Diagonal and Side Area

	return a * sqrt(pow(d, 2) - pow(a, 2));

}

float Problem19(float d)
{
	// Problem #19 - Circle Area Through Diameter

	const float PI = 3.14;

	return (PI * pow(d, 2)) / 4;

}

float Problem20(float A)
{
	// Problem #20 Circle Area Inscribed in a Square

	const float PI = 3.14;

	return (PI * pow(A, 2)) / 4;

}

float Problem21(float L)
{
	// Problem #21 - Circle Area Along the Circumference
	const float PI = 3.14;

	return pow(L, 2) / (4 * PI);

}

float Problem22(float a, float b)
{
	// Problem #22 Circle Area Inscribed in an Isosceles Triangle

	const float PI = 3.14;

	return PI * (pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));

}

float Problem23(float a, float b, float c)
{
	// Problem #23 - Circle Area circle Described Around an Arbitrary Triangle

	const float PI = 3.14;
	float area, p;

	p = (a + b + c) / 2;

	area = PI * pow(((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)))), 2); // area

	return area;
}

void Problem31(int number)
{
	// Problem #31 Power of 2,3,4

	cout << number << " ^ 2 = " << pow(number, 2) << endl;
	cout << number << " ^ 3 = " << pow(number, 3) << endl;
	cout << number << " ^ 4 = " << pow(number, 4) << endl;

}

int Problem32(int number, int exponenet)
{
	// Problem #32 Power of m

	return pow(number, exponenet);

}

unsigned int Problem42(short days, short hours, short minutes, short seconds)
{
	// Problem #42 - Task Duration In Seconds
	stSecondsFormats secondsFormat;
	unsigned int totalSeconds;

	totalSeconds = (days * secondsFormat.secondsInDay);
	totalSeconds = totalSeconds + (hours * secondsFormat.secondsInHour);
	totalSeconds = totalSeconds + (minutes * secondsFormat.secondsInMinutes) + seconds; 

	return totalSeconds;

}

void Problem43(short days, short hours, short minutes, short seconds)
{
	// Problem #43 - Seconds to Days Hours Minutes Seconds

	stSecondsFormats secondsFormat;
	unsigned int totalSeconds, reminder;

	cout << "Input total seconds: ";
	cin >> totalSeconds;

	days = totalSeconds / secondsFormat.secondsInDay;
	reminder = totalSeconds % secondsFormat.secondsInDay;

	hours = reminder / secondsFormat.secondsInHour;
	reminder = totalSeconds % secondsFormat.secondsInHour;

	minutes = reminder / secondsFormat.secondsInMinutes;
	reminder = totalSeconds % secondsFormat.secondsInMinutes;

	seconds = reminder;

	cout << days << ":" << hours << ":" << minutes << ":" << seconds << endl;

}


int main()
{
	unsigned short days, hours, minutes, seconds;

	cout << "Input days: ";
	cin >> days;

	cout << "Input hours: ";
	cin >> hours;

	cout << "Input minutes: ";
	cin >> minutes;

	cout << "Input seconds: ";
	cin >> seconds;

	cout << "Total Seconds is: " << Problem42(days, hours, minutes, seconds) << endl;

	return 0;

}
