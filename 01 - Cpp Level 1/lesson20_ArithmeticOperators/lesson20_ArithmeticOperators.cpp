#include <iostream>
using namespace std;

void IntroCode()
{
	short A = 10, B = 20;

	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	cout << "A + B = " << A + B << endl;
	cout << "A - B = " << A - B << endl;
	cout << "A * B = " << A * B << endl;
	cout << "A / B = " << A / B << endl;
	cout << "A % B = " << A % B << endl; // modulo
}

void Problem01()
{
	// basic calculations

	int a, b;

	cout << "Please enter the first Number (a): ";
	cin >> a;

	cout << "Please enter the second Number (b): ";
	cin >> b;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl;
	cout << "a / b = " << a / b << endl;
	cout << "a % b = " << a % b << endl; // modulo
}

void Problem07()
{
	// Half of number problem

	int number;
	cout << "Please enter a number: ";
	cin >> number;

	cout << "Half of " << number << " is " << number / 2 << endl;
}

void Problem09()
{
	// Sum of 3 Numbers

	int a, b, c;

	cout << "Please enter first number (a): ";
	cin >> a;

	cout << "Please enter second number (b): ";
	cin >> b;

	cout << "Please enter third number (c): ";
	cin >> c;

	cout << a + b + c << endl;

}

void Problem10()
{

	// Average of 3 Numbers

	int a, b, c;

	cout << "Please enter first number (a): ";
	cin >> a;

	cout << "Please enter second number (b): ";
	cin >> b;

	cout << "Please enter third number (c): ";
	cin >> c;

	cout << (a + b + c) / 3 << endl;

}

void Problem14()
{
	/*
		Swap 2 Numbers Problem
	*/

	int a, b, temp;

	cout << "Enter a's value: " << endl;
	cin >> a;

	cout << "Enter b's value: " << endl;
	cin >> b;

	cout << "Before Swap\n" << "a = " << a << ", b = " << b << endl;

	// Swap the numbers via temporary variable
	temp = a;
	a = b;
	b = temp;

	cout << "After Swap\n" << "a = " << a << ", b = " << b << endl;

}

void Problem15()
{
	// Rectangle Area

	int width, length, area;

	cout << "Enter width: " << endl;
	cin >> width;

	cout << "Enter length: " << endl;
	cin >> length;

	area = width * length;

	cout << "Area of rectangle (" << width << "x" << length << ") = " << area << endl;
}

void Problem17()
{
	int a, h, area;

	cout << "Enter a: " << endl;
	cin >> a;

	cout << "Enter h:" << endl;
	cin >> h;

	area = a / 2 * h;
	cout << "Tringle Area = " << area << endl;
}

void Problem19()
{
	// Circle Area Through Diameter

	float d, area;
	const float PI = 3.14;

	cout << "Enter D Value: " << endl;
	cin >> d;

	area = (PI * d * d) / 4;

	cout << "Area = " << area << endl;
}

void Problem20()
{
	// Problem #20 Circle Area Inscribed in a Square
	// area = PI * (a/2)^2 = PI * a^2 / 4

	float a, area;
	const float PI = 3.14;

	cout << "Enter A's value: " << endl;
	cin >> a;

	area = (PI * a * a) / 4;
	cout << "Area = " << area << endl;
}

void Problem21()
{
	// Problem #21 - Circle Area Along the Circumference

	float l, area;

	cout << "Enter L Value:" << endl;
	cin >> l;

	const float PI = 3.14;

	area = (l * l) / (4 * PI);

	cout << "Area = " << area << endl;
}

void Problem22()
{
	// Problem #22 Circle Area Inscribed in an Isosceles Triangle
	float a, b, area;
	const float PI = 3.14;

	cout << "Enter a value: " << endl;
	cin >> a;

	cout << "Enter b value:" << endl;
	cin >> b;

	area = (PI * (b * b / 4)) * ((2 * a - b) / (2 * a + b ));
	cout << "Area =  " << area << endl;

}

void Problem31()
{
	// Power of number for 2, 3, and 4

	short number;

	cout << "Enter a number: " << endl;
	cin >> number;

	cout << number << "^2 = " << pow(number, 2) << endl;
	cout << number << "^3 = " << pow(number, 3) << endl;
	cout << number << "^4 = " << pow(number, 4) << endl;

}

void Problem35()
{
	// Piggy Bank Calculator

	float pennies, nickles, dimes, quarters, dollars, totalPennies;
	
	cout << "Piggy Bank Calculator\n" << "----------------" << endl;

	cout << "Enter pennies: " << endl;
	cin >> pennies;

	cout << "Enter nickles: " << endl;
	cin >> nickles;

	cout << "Enter dimes: " << endl;
	cin >> dimes;

	cout << "Enter quarters: " << endl;
	cin >> quarters;

	cout << "Enter dollars: " << endl;
	cin >> dollars;

	totalPennies = (pennies * 1) + (nickles * 5) + (dimes * 10) + (quarters * 25) + (dollars * 100);

	cout << "Pennies = " << totalPennies << endl;
	cout << "Dollars = " << totalPennies / 100 << endl;
}

void Problem39()
{
	// Pay Reminder
	float totalBill, cashPaid, reminder;

	cout << "Enter Total Bill: " << endl;
	cin >> totalBill;

	cout << "Enter Cash Paid: " << endl;
	cin >> cashPaid;

	reminder = cashPaid - totalBill;
	cout << "Reminder is = " << reminder;
}

void Problem40()
{
	// Service Fee and Sales Tax
	const float serviceFee = 0.1, salesTax = 0.16;
	float billValue, totalBill;

	cout << "Enter billValue: " << endl;
	cin >> billValue;

	totalBill = billValue + (billValue * serviceFee);

	totalBill = totalBill + (totalBill * salesTax);

	cout << "Your total bill after service fee and sales tax is : " << totalBill << endl;

}

void Problem42()
{
	// Task duration in seconds

	const unsigned int secondsInDay = 24 * 60 * 60;
	const unsigned int	secondsInHour = 60 * 60;
	const unsigned int secondsInminute = 60;
	unsigned short days, hours, minutes, seconds;
	unsigned int totalSeconds;

	cout << "Input Days: " << endl;
	cin >> days;

	cout << "Input Hours: " << endl;
	cin >> hours;

	cout << "Input Minutes: " << endl;
	cin >> minutes;

	cout << "Input Seconds: " << endl;
	cin >> seconds;

	totalSeconds = (days * secondsInDay) + (hours * secondsInHour) + (minutes * secondsInminute) + seconds;
	cout << "Total Seconds is: " << totalSeconds << endl;

}

void Problem43()
{
	// Seconds to -> days:hours:minutes:seconds

	const unsigned int secondsInDay = 24 * 60 * 60;
	const unsigned int	secondsInHour = 60 * 60;
	const unsigned int secondsInminute = 60;
	unsigned short days, hours, minutes, seconds;
	float reminder;
	unsigned int totalSeconds;



	cout << "Input Total Seconds: " << endl;
	cin >> totalSeconds;

	days = totalSeconds / secondsInDay;

	reminder = totalSeconds % secondsInDay; // after decimal point, the reminder is the hours

	hours = reminder / secondsInHour;
	reminder = totalSeconds % secondsInHour; // after decimal point, the reminder is the minutes

	minutes = reminder / secondsInminute;
	reminder = totalSeconds % secondsInminute; // after decimal point, the reminder is the seconds

	seconds = reminder;

	cout << days << ":" << hours << ":" << minutes << ":" << seconds << endl;

}

void Problem47()
{
	// Problem #47 - Loan Instalment Months
	float loanAmount, monthlyPayment;
	short months;

	cout << "Enter your loan amount: " << endl;
	cin >> loanAmount;

	cout << "Enter your monthlyPayment: " << endl;
	cin >> monthlyPayment;

	months = loanAmount / monthlyPayment;
	cout << "Months: " << months;

}

int main()
{
	Problem47();
    return 0;
}

