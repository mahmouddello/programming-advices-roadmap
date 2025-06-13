#pragma once
#include <iostream>

class clsChar
{
public:
    static char invertCharacterCase(const char& c)
    {
        return isupper(c) ? tolower(c) : toupper(c);
    }

    static bool isVowel(const char& c)
    {
        char c2 = tolower(c);

        return ((c2 == 'a') || (c2 == 'e') || (c2 == 'i') || (c2 == 'o') || (c2 == 'u'));
    }
};

