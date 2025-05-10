#pragma once

#include <iostream>

using namespace std;

namespace random_utils
{
    enum enCharType
    {
        smallLetter = 1,
        capitalLetter = 2,
        specialChar = 3,
        digit = 4
    };

    int randomNumberInRange(int from, int to)
    {

        /*
            For example, if you want numbers between 3 and 7:

            (7 - 3 + 1) = 5, so rand() % 5 gives numbers from 0 to 4.
            Adding 3 shifts it to 3 to 7.
        */

        int randomNumber = rand() % (to - from + 1) + from;

        return randomNumber;
    }

    char getRandomCharacter(enCharType charType)
    {
        switch (charType)
        {
        case enCharType::smallLetter:
            return char(randomNumberInRange(97, 122));
        case enCharType::capitalLetter:
            return char(randomNumberInRange(65, 90));
        case enCharType::specialChar:
            return char(randomNumberInRange(33, 47));
        case enCharType::digit:
            return char(randomNumberInRange(48, 57));
        }
    }
}