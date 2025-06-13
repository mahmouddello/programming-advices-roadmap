#include <iostream>
#include "clsDate.h"

using namespace std;

int main()
{
	clsDate date1;
	date1.print();

	clsDate date2("31/12/2022");
	date2.print();

	clsDate date3(4, 10, 2002);
	date3.print();

	clsDate date4(250, 2022);
	date4.print();

	cout << date2.isLastDayInMonth() << endl;
	cout << date2.isLastMonthInYear() << endl;

	date2.increaseByOneDay();
	date2.print();

	cout << date1.isDateBeforeDate(date2) << endl;

	cout << date1.isBusinessDay() << endl;

	cout << date1.isDateAfterDate(date2) << endl;

	date2.addDays(10);
	date2.print();

	clsDate date5(21, 1, 2023);

	cout << date2.differenceInDays(date5) << endl;

	return 0;
}