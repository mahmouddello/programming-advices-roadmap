#include <iostream>
#include <iomanip>

using namespace std;

// My previous solution did all the work in 1 function,
// so I divided the solution like Programming Advices.

bool isLeapYear(short year)
{
	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

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

short numberOfDaysInAMonth(const short year, const short month)
{
	if (month < 1 || month > 12)
		return 0;

	short monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return month == 2 ? (isLeapYear(year) ? 29 : 28) : monthDays[month - 1];
}

short getDayofWeekOrder(short year, short month, short day)
{

	short a = (14 - month) / 12;
	year = year - a;

	short m = month + (12 * a) - 2;

	short d = (day + year + (year / 4) - (year / 100) + (year / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string getDayNameByOrder(short num)
{
	string days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return days[num];
}

string getMonthName(short month)
{
	string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	 
	return months[month - 1];
}

void printMonthCalendar(short year, short month)
{
	short firstDayOrder = getDayofWeekOrder(year, month, 1);
	string firstDayInMonth = getDayNameByOrder(firstDayOrder);
	short totalDays = numberOfDaysInAMonth(year, month);

	cout << "_________________________" << getMonthName(month) << "_________________________" << endl;
	cout << "\nSun\tMon\tTue\tWed\tThu\tFri\tSat\t" << endl;

	short dayTrack = 0;

	// print spaces
	while (dayTrack < firstDayOrder)
	{
		cout << "\t";
		dayTrack++;
	}
	
	for (short i = 1; i <= totalDays; i++)
	{
		cout << i << "\t";
		
		if (getDayNameByOrder(dayTrack) == "Sat")
		{
			cout << endl;
			dayTrack = 0;
		}
		else
		{
			dayTrack++;
		}
			
	}

	cout << "\n_____________________________________________________" << endl;

}

int main()
{

	short year = readYear();
	short month = readMonth();

	printMonthCalendar(year, month);

	return 0;
}