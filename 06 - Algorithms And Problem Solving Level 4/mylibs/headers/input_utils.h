#pragma once

#include <iostream>
#include <string>

namespace input_utils
{
    int readNumber(std::string Message)
    {
        int Number = 0;

        std::cout << Message << std::endl;
        std::cin >> Number;

        return Number;
    }
    
    int readPositiveNumber(std::string Message)
    {
        int Number = 0;
        do
        {
            std::cout << Message;;
            std::cin >> Number;
        } while (Number <= 0);
        return Number;
    }

}
