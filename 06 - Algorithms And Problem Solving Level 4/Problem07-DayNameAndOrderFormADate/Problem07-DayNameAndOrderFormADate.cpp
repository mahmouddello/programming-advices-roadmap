#include <iostream>

using namespace std;

// My previous solution did all the work in 1 function,
// so I divided the solution like Programming Advices.

short readYear()
{
	short year;

	cout << "Please enter a year: ";
	cin >> year;

	cout << endl;

	return year;
}

short readMonth()
{
	short month;

	cout << "Please enter a month: ";
	cin >> month;

	cout << endl;

	return month;
}

short readDay()
{
	short day;

	cout << "Please enter a day: ";
	cin >> day;

	cout << endl;

	return day;
}

short getDayofWeekOrder(short year, short month, short day)
{
	
	short a = (14 - month) / 12;
	year = year - a;

	short m = month + (12 * a) - 2;

	short d = (day + year + (year / 4) - (year / 100) + (year / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string getDayNameGeorgianCalendar(short num)
{
	string days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	return days[num];
}

int main()
{

	short year = readYear();
	short month = readMonth();
	short day = readDay();

	cout << "\nDate: " << day << "/" << month << "/" << year << endl;
	cout << "Day Order: " << getDayofWeekOrder(year, month, day) << endl;
	cout << "Day Name: " << getDayNameGeorgianCalendar(getDayofWeekOrder(year, month, day)) << endl;

	return 0;
}