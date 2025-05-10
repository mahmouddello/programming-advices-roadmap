#include <iostream>
#include <iomanip>
#include "../mylibs/headers/date_utils.h"

using namespace std;

void printHorizontalLine()
{
	cout << "----------------------------------------------------------------" << endl;
}

void printYearCalendar(const short& year)
{
	
	printHorizontalLine();
	cout << setw(35) << "Calendar - " << year << endl;
	printHorizontalLine();

	cout << endl;

	for (int monthIndex = 1; monthIndex <= 12; monthIndex++)
	{
		date_utils::printMonthCalendar(year, monthIndex);
	}
}

int main()
{
	short year = date_utils::readYear();

	printYearCalendar(year);

	return 0;
}