#pragma once
#include "clsDate.h"

class clsPeriod
{
public:
    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;
    }

    static bool isOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::compareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::eBefore ||
            clsDate::compareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::eAfter)
            return false;
        else
            return true;
    }

    bool isOverLapWith(clsPeriod Period2)
    {
        return isOverlapPeriods(*this, Period2);
    }

    static bool isDateInPeriod(clsPeriod period, clsDate date)
    {
        // if not before the date, and not after, false || false = false -> !false = true
        return !(
            clsDate::compareDates(date, period.StartDate) == clsDate::enDateCompare::eBefore ||
            clsDate::compareDates(date, period.EndDate) == clsDate::enDateCompare::eAfter);
    }
};
