#pragma once

#include <iostream>

namespace math_utils
{
    int myAbsFunction(int number)
    {
        if (number > 0)
            return number;

        return number * -1;
    }

    float getFractionPart(float number)
    {
        return number - int(number); // e.g. : 10.3 - 10 = 0.3
    }

    int myRound(float number)
    {
        int integerPart = int(number); // 10.3 becomes -> 10

        // instead of checking for +0.5 and -0.5, we took abs to summarize.
        if (abs(getFractionPart(number)) > 0.5)
        {
            if (number > 0) // if it was 10.3, we skip here and return the integer part 10;
                return ++integerPart;
            else
                return --integerPart;
        }

        else
        {
            return integerPart;
        }
    }

    int myFloor(float number)
    {
        int integerPart = int(number);

        return (number >= 0) ? integerPart : (number == integerPart ? integerPart : integerPart - 1);
    }

    int myCeil(float number)
    {
        int integerPart = int(number);

        if (getFractionPart(number) <= 0)
            return integerPart;

        return ++integerPart;
    }

    double mySqrt(double number)
    {
        return pow(number, (0.5));
    }

}