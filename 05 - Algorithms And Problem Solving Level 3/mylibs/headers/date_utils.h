#pragma once

#include <iostream>
#include <iomanip>

namespace date_utils
{

    struct stDate
    {
        short day = 0;
        short month = 0;
        short year = 0;

        // Define equality operator
        bool operator==(const stDate &other) const
        {
            return day == other.day && month == other.month && year == other.year;
        }

        bool operator<=(const stDate & other) const
        {
            return day <= other.day && month <= other.month && year <= other.year;;
        }
    };

    bool isLeapYear(short year)
    {
        return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
    }

    int getNumberOfDays(short year)
    {
        return isLeapYear(year) ? 366 : 365;
    }

    int getNumberOfHours(short year)
    {
        return getNumberOfDays(year) * 24;
    }

    int getNumberOfMinutes(short year)
    {
        return getNumberOfHours(year) * 60;
    }

    int getNumberOfSeconds(short year)
    {
        return getNumberOfMinutes(year) * 60;
    }

    short readDay()
    {
        short day;
        std::cout << "Please enter a day: ";
        std::cin >> day;
        return day;
    }

    short readYear()
    {
        short year;
        std::cout << "Please enter a year: ";
        std::cin >> year;
        return year;
    }

    short readMonth()
    {
        short month;
        std::cout << "Please enter a month: ";
        std::cin >> month;
        return month;
    }

    short numberOfDaysInAMonth(short year, short month)
    {
        if (month < 1 || month > 12)
            return 0;

        short monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return month == 2 ? (isLeapYear(year) ? 29 : 28) : monthDays[month - 1];
    }

    short dayOfWeekOrder(short year, short month, short day)
    {
        short a = (14 - month) / 12;
        short y = year - a;
        short m = month + (12 * a) - 2;

        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    std::string dayShortName(short num)
    {
        std::string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return days[num];
    }

    std::string getMonthName(short month)
    {
        std::string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        return months[month - 1];
    }

    void printMonthCalendar(short year, short month)
    {
        short firstDayOrder = dayOfWeekOrder(year, month, 1);
        std::string firstDayInMonth = dayShortName(firstDayOrder);
        short totalDays = numberOfDaysInAMonth(year, month);

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

    short numberOfDaysFromBeginningOfTheYear(short year, short month, short day)
    {
        short totalDays = 0;

        // loop through all the months before the current month
        for (short i = 1; i < month; i++)
        {
            totalDays += numberOfDaysInAMonth(year, i); // add the days in the month to the total days
        }

        totalDays += day; // add the days in the current month

        return totalDays;
    }

    short numberOfDaysFromBeginningOfTheYear(const stDate &date)
    {
        return numberOfDaysFromBeginningOfTheYear(date.year, date.month, date.day);
    }

    stDate getDateFromDayOrderInYear(short dateOrderInYear, short year)
    {
        stDate date;
        short remainingDays = dateOrderInYear;
        short monthDays = 0;

        date.year = year;
        date.month = 1;

        while (true)
        {
            monthDays = numberOfDaysInAMonth(year, date.month);

            if (remainingDays > monthDays)
            {
                // اذا كان الايام المتبقية اكبر من ايام الشهر في اللوب فاطرحه وزود عداد الشهر واحد
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

    void printHorizontalLine()
    {
        std::cout << "----------------------------------------------------------------" << std::endl;
    }

    void printYearCalendar(const short &year)
    {

        printHorizontalLine();
        std::cout << std::setw(35) << "Calendar - " << year << std::endl;
        printHorizontalLine();

        std::cout << std::endl;

        for (int monthIndex = 1; monthIndex <= 12; monthIndex++)
        {
            printMonthCalendar(year, monthIndex);
        }
    }

    stDate readFullDate()
    {
        stDate date;

        date.day = readDay();
        date.month = readMonth();
        date.year = readYear();

        return date;
    }

    bool isLastDayInMonth(const stDate &date)
    {
        return date.day == numberOfDaysInAMonth(date.year, date.month);
    }

    bool isLastMonthInYear(const short &month)
    {
        return month == 12;
    }

    short dayOfWeekOrder(stDate date)
    {
        return dayOfWeekOrder(date.year, date.month, date.day);
    }

    stDate increaseDateByOneDay(stDate date)
    {
        if (isLastDayInMonth(date) && !isLastMonthInYear(date.month))
        {
            date.day = 1;
            date.month++;
        }

        else if (isLastDayInMonth(date) && isLastMonthInYear(date.month))
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

    bool isWeekend(short dayOrder)
    {
        std::string dayStr = dayShortName(dayOrder);

        return dayStr == "Fri" || dayStr == "Sat";
    }

    bool isDateBeforDate(stDate date1, stDate date2)
    {
        if (date1.year != date2.year)
            return date1.year < date2.year;

        if (date1.month != date2.month)
            return date1.month < date2.month;

        return date1.day < date2.day;
    }

    bool isDateEqualsDate(stDate date1, stDate date2)
    {
        if (date1.year != date2.year)
            return false;

        if (date1.month != date2.month)
            return false;

        return date1.day == date2.day;
    }

    stDate dateAddDaysV2(short days, stDate Date)
    {

        short reminingDays = days + numberOfDaysFromBeginningOfTheYear(Date.year, Date.month, Date.day);

        while (reminingDays > getNumberOfDays(Date.year))
        {
            reminingDays -= getNumberOfDays(Date.year);
            Date.year++;
        }

        Date = getDateFromDayOrderInYear(reminingDays, Date.year);

        return Date;
    }

    // Programming Advices
    int differenceInDays(stDate date1, stDate date2, bool includeEndDay = false)
    {
        int days = 0;

        while (isDateBeforDate(date1, date2))
        {
            days++;
            date1 = increaseDateByOneDay(date1);
        }

        return includeEndDay ? ++days : days;
    }

    bool isBusinessDay(short dayOrder)
    {
        return !isWeekend(dayOrder);
    }

    bool isDateAfterDate(stDate date1, stDate date2)
    {
        return !(isDateBeforDate(date1, date2));
    }

}
