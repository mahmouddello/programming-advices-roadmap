#include <iostream>
#include "D:/MyCPP_Libs/headers/date_utils.h"

using date_utils::stDate;
using namespace std;

void swapDates(stDate& date1, stDate& date2)
{
    stDate temp;
    temp = date1;
    date1 = date2;
    date2 = temp;
}

// My Soltuion
int differenceInDaysV2(stDate date1, stDate date2, bool includeEndDay = false)
{
    int days = 0;
    bool flag = date_utils::isDateBeforDate(date2, date1);

    if (flag)
        swapDates(date1, date2);

    while (date_utils::isDateBeforDate(date1, date2))
    {
        days++;
        date1 = increaseDateByOneDay(date1);
    }

    return flag ? -1 * (includeEndDay ? ++days : days) : includeEndDay ? ++days : days;
}

int differenceInDaysProgrammingAdvices(stDate date1, stDate date2, bool includeEndDay = false)
{
    int days = 0;
    short swapFlagValue = 1;

    // if date 1 is not less than date 2, swap and mark the swapFlagValue as -1 to produce negative result.
    if (!date_utils::isDateBeforDate(date1, date2))
    {
        swapDates(date1, date2);
        swapFlagValue = -1;
    }

    while (date_utils::isDateBeforDate(date1, date2))
    {
        days++;
        date1 = increaseDateByOneDay(date1);
    }

    return includeEndDay ? swapFlagValue * ++days : swapFlagValue * days;
}

int main()
{
    
    stDate date1 = date_utils::readFullDate();
    stDate date2 = date_utils::readFullDate();

    cout << "Difference is: " << differenceInDaysV2(date1, date2) << endl;
    cout << "Difference is (End day included): " << differenceInDaysV2(date1, date2, true) << endl;

    
    return 0;
}

