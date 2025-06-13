#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include "../mylibs/headers/date_utils.h"

using date_utils::stDate;
using namespace std;

stDate getTodayDate()
{
	stDate todayDate;
	time_t t = time(0); // get time now
	tm* now = localtime(&t);

	todayDate.year = now->tm_year + 1900;
	todayDate.month = now->tm_mon + 1;
	todayDate.day = now->tm_mday;

	return todayDate;
}

int calculateAgeInDays(stDate birthDate, stDate todayDate)
{
	return date_utils::differenceInDays(birthDate, todayDate, true);
}

int main()
{
	cout << "Please enter your birth date details\n" << endl;
	stDate birthDate = date_utils::readFullDate();
	stDate todayDate = getTodayDate();

	unsigned int ageInDays = calculateAgeInDays(birthDate, todayDate);

	printf("Your age is: %d Day(s).\n", ageInDays);

	return 0;
}