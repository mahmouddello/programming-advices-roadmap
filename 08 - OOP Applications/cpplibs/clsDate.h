#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include "./clsString.h"

class clsDate
{
public:
	short _day;
	short _month;
	short _year;

	struct _stDate
	{
		short day = 0;
		short month = 0;
		short year = 0;
	};

	short getDay()
	{
		return _day;
	}

	void setDay(short day)
	{
		_day = day;
	}

	short getMonth()
	{
		return _month;
	}

	void setMonth(short month)
	{
		_month = month;
	}

	short getYear()
	{
		return _year;
	}

	void setYear(short year)
	{
		_year = year;
	}
	__declspec(property(get = getDay, put = setDay)) short day;
	__declspec(property(get = getMonth, put = setMonth)) short month;
	__declspec(property(get = getYear, put = setYear)) short year;

	clsDate()
	{
		time_t t = time(0);
		tm *now = localtime(&t);

		_day = now->tm_mday;
		_month = now->tm_mon + 1;
		_year = now->tm_year + 1900;
	}
	clsDate(std::string date)
	{
		std::vector<std::string> v = clsString::split(date, "/");

		_day = stoi(v[0]);
		_month = stoi(v[1]);
		_year = stoi(v[2]);
	}
	clsDate(short day, short month, short year) : _day(day), _month(month), _year(year) {}
	clsDate(short daysPassed, short year)
	{
		clsDate date = getDateFromDayOrderInYear(daysPassed, year);
		_day = date.day;
		_month = date.month;
		_year = date.year;
	}

	// --- STATIC METHODS ---
	static bool isLeapYear(short year)
	{
		return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
	}
	static unsigned short numberOfDaysInAMonth(short month, short year)
	{
		if (month < 1 || month > 12)
			return 0;

		short monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		return month == 2 ? (isLeapYear(year) ? 29 : 28) : monthDays[month - 1];
	}
	static unsigned short getNumberOfDays(short year)
	{
		return isLeapYear(year) ? 366 : 365;
	}
	static unsigned int getNumberOfHours(short year)
	{
		return getNumberOfDays(year) * 24;
	}
	static unsigned int getNumberOfMinutes(short year)
	{
		return getNumberOfHours(year) * 60;
	}
	static unsigned int getNumberOfSeconds(short year)
	{
		return getNumberOfMinutes(year) * 60;
	}
	static unsigned short dayOfWeekOrder(short day, short month, short year)
	{
		short a = (14 - month) / 12;
		short y = year - a;
		short m = month + (12 * a) - 2;

		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	static std::string getDayName(short num)
	{
		std::string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
		return days[num];
	}
	static unsigned short numberOfDaysFromBeginningOfTheYear(clsDate date)
	{
		short totalDays = 0;

		// loop through all the months before the current month
		for (short i = 1; i < date.month; i++)
		{
			totalDays += numberOfDaysInAMonth(date.year, i); // add the days in the month to the total days
		}

		totalDays += date.day; // add the days in the current month

		return totalDays;
	}
	static std::string getMonthName(short month)
	{
		std::string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
								"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
		return months[month - 1];
	}
	clsDate getDateFromDayOrderInYear(short dateOrderInYear, short year)
	{
		clsDate date;
		short remainingDays = dateOrderInYear;
		short monthDays = 0;

		date.year = year;
		date.month = 1;

		while (true)
		{
			monthDays = numberOfDaysInAMonth(date.month, year);

			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				date.month++;
			}
			else
			{
				date.day = remainingDays; // assigns the left over days to day variable.
				break;
			}
		}

		return date;
	}
	static void printMonthCalendar(short month, short year)
	{
		short firstDayOrder = dayOfWeekOrder(1, month, year);
		std::string firstDayInMonth = getDayName(firstDayOrder);
		short totalDays = numberOfDaysInAMonth(month, year);

		std::cout << "\n_________________________" << getMonthName(month) << "_________________________" << std::endl;
		std::cout << "\nSun\tMon\tTue\tWed\tThu\tFri\tSat\t" << std::endl;

		short dayTrack = 0;

		while (dayTrack < firstDayOrder)
		{
			std::cout << "\t";
			dayTrack++;
		}

		for (short i = 1; i <= totalDays; i++)
		{
			std::cout << i << "\t";

			if (dayTrack == 6)
			{
				std::cout << std::endl;
				dayTrack = 0;
			}
			else
			{
				dayTrack++;
			}
		}

		std::cout << "\n_____________________________________________________" << std::endl;
	}
	static void printHorizontalLine()
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
	}
	static void printYearCalendar(const short &year)
	{

		printHorizontalLine();
		std::cout << std::setw(35) << "Calendar - " << year << std::endl;
		printHorizontalLine();

		std::cout << std::endl;

		for (int monthIndex = 1; monthIndex <= 12; monthIndex++)
		{
			printMonthCalendar(monthIndex, year);
		}
	}
	static bool isLastDayInMonth(clsDate date)
	{
		return date.day == numberOfDaysInAMonth(date.month, date.year);
	}
	static bool isLastMonthInYear(short month)
	{
		return month == 12;
	}
	static clsDate increaseByOneDay(clsDate date)
	{
		if (isLastDayInMonth(date) && !clsDate::isLastMonthInYear(date.month))
		{
			date.day = 1;
			date.month++;
		}

		else if (isLastDayInMonth(date) && clsDate::isLastMonthInYear(date.month))
		{
			date.day = 1;
			date.month = 1;
			date.year++;
		}

		else
		{
			date.day++;
		}

		return date;
	}
	static bool isDateBeforeDate(clsDate date1, clsDate date2)
	{
		if (date1.year != date2.year)
			return date1.year < date2.year;

		if (date1.month != date2.month)
			return date1.month < date2.month;

		return date1.day < date2.day;
	}
	static bool isDateEqualsDate(clsDate date1, clsDate date2)
	{
		if (date1.year != date2.year)
			return false;

		if (date1.month != date2.month)
			return false;

		return date1.day == date2.day;
	}
	static bool isDateAfterDate(clsDate date1, clsDate date2)
	{
		return !(isDateBeforeDate(date1, date2));
	}
	static bool isWeekend(short dayOrder)
	{
		std::string dayStr = getDayName(dayOrder);

		return dayStr == "Fri" || dayStr == "Sat";
	}
	static bool isBusinessDay(short dayOrder)
	{
		return !isWeekend(dayOrder);
	}
	static int differenceInDays(clsDate date1, clsDate date2, bool includeEndDay = false)
	{
		int days = 0;

		while (clsDate::isDateBeforeDate(date1, date2))
		{
			days++;
			date1 = clsDate::increaseByOneDay(date1);
		}

		return includeEndDay ? ++days : days;
	}

	static std::string getSystemDate()
	{
		time_t t = time(0);
		tm *now = localtime(&t);

		return std::to_string(now->tm_mday) + "/" + std::to_string(now->tm_mon + 1) + "/" + std::to_string(now->tm_year + 1900);
	}

	static std::string getSystemTime()
	{
		time_t t = time(0);
		tm *now = localtime(&t);

		return std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec);
	}

	static std::string getSystemDateTime()
	{
		return getSystemDate() + " - " + getSystemTime();
	}

	// --- INSTANCE METHODS ---
	void print()
	{
		printf("%d/%d/%d\n", _day, _month, _year);
	}
	bool isLeapYear()
	{
		return isLeapYear(_year);
	}
	unsigned short numberOfDaysInAMonth()
	{
		return numberOfDaysInAMonth(_month, _year);
	}
	unsigned short getNumberOfDays()
	{
		return getNumberOfDays(_year);
	}
	unsigned int getNumberOfHours()
	{
		return getNumberOfDays(_year) * 24;
	}
	unsigned int getNumberOfMinutes()
	{
		return getNumberOfHours(_year) * 60;
	}
	unsigned int getNumberOfSeconds()
	{
		return getNumberOfMinutes(_year) * 60;
	}
	unsigned short dayOfWeekOrder()
	{
		return dayOfWeekOrder(_day, _month, _year);
	}
	std::string getDayName()
	{
		return getDayName(dayOfWeekOrder());
	}
	std::string getMonthName()
	{
		return getMonthName(_month);
	}
	unsigned short numberOfDaysFromBeginningOfTheYear()
	{
		return numberOfDaysFromBeginningOfTheYear(*this);
	}
	void addDays(short days)
	{

		// assume days from the beginning of the year: 300, and days to add: 150
		// we go back to the beginning of the year, and add 450 days and see where we reach
		short remainingDays = clsDate::numberOfDaysFromBeginningOfTheYear(*this);
		remainingDays += days;

		short monthDays = 0;
		this->month = 1;

		while (true)
		{
			monthDays = clsDate::numberOfDaysInAMonth(this->month, this->year);

			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				this->month++; // increment month by 1 to move to next month

				if (this->month > 12)
				{
					this->year++;
					this->month = 1;
					// if month reachs 13 this means we passed a year, increment year by 1 and reset month to 1
				}
			}
			else
			{
				// here it didn't pass the first condition, so the remaining days are less than a monthDays
				this->day = remainingDays;
				break;
			}
		}
	}
	void printMonthCalendar()
	{
		printMonthCalendar(_month, _year);
	}
	void printYearCalendar()
	{
		printYearCalendar(_year);
	}
	bool isLastDayInMonth()
	{
		return isLastDayInMonth(*this);
	}
	bool isLastMonthInYear()
	{
		return isLastMonthInYear(_month);
	}
	void increaseByOneDay()
	{
		*this = increaseByOneDay(*this);
	}
	bool isDateBeforeDate(clsDate date2)
	{
		// *this represents the first date, which is fetched from current object
		return isDateBeforeDate(*this, date2);
	}
	bool isDateEqualsDate(clsDate date2)
	{
		return isDateEqualsDate(*this, date2);
	}
	bool isDateAfterDate(clsDate date2)
	{
		return isDateAfterDate(*this, date2);
	}
	bool isWeekend()
	{
		return isWeekend(dayOfWeekOrder());
	}
	bool isBusinessDay()
	{
		return isBusinessDay(dayOfWeekOrder());
	}
	int differenceInDays(clsDate date2)
	{
		return differenceInDays(*this, date2);
	}

	const enum enDateCompare { eBefore = -1, eEqual = 0, eAfter = 1 };

	static enDateCompare compareDates(const clsDate &date1, const clsDate &date2)
	{
		if (isDateEqualsDate(date1, date2))
			return enDateCompare::eEqual;

		else if (isDateBeforeDate(date1, date2))
			return enDateCompare::eBefore;

		return enDateCompare::eAfter;
	}

	static bool isDateValid(clsDate date)
	{
		return date.month < 1 || date.month > 12 ? false : date.day <= numberOfDaysInAMonth(date.month, date.year);
	}
};
