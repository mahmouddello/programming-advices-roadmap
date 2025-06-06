#pragma once
#include <iostream>
#include <vector>
#include "clsChar.h"

/*
    This class, clsString, encapsulates a std::string and provides functionality for basic string operations.

    Static methods are used when the functionality does not depend on a particular instance of the class. This allows
    such methods to be called using the class name directly without instantiating an object.

    In scenarios where we want to call the same static method via an instance (object) of the class, we create a
    corresponding instance method. This method typically takes no parameters and internally calls the static method
    using the object's current state (such as its internal string value). This maintains both flexibility and
    usability from an object-oriented design perspective.
*/

class clsString
{
private:
	std::string _value;
public:

    // Default constructor initializes the string to an empty value
    clsString()
    {
        _value = "";
    }

    // Parameterized constructor initializes the string with a given value
    clsString(std::string value)
    {
        this->_value = value;
    }

	// property get
	std::string getValue()
	{
		return _value;
	}

	// property set
	void setValue(std::string value)
	{
		_value = value;
	}

    __declspec(property(get = getValue, put = setValue)) std::string value;

    // --- Static methods ---
    static short length(std::string s1)
    {
        return s1.length();
    }
    static void printFirstLetterOfEachWord(const std::string& s1)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < s1.length(); i++)
        {
            if (s1[i] != ' ' && isFirstLetter)
            {
                std::cout << s1[i] << std::endl;
            }

            /* if the letter is empty space, the next iteration will be a new word,
                and isFirstLetter flag will become true */
            isFirstLetter = (s1[i] == ' ' ? true : false);
        }
    }
    static std::string upperFirstLetterOfEachWord(std::string s1)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < s1.length(); i++)
        {
            if (s1[i] != ' ' && isFirstLetter)
            {
                s1[i] = toupper(s1[i]);
            }

            /* if the letter is empty space, the next iteration will be a new word,
                and isFirstLetter flag will become true */
            isFirstLetter = (s1[i] == ' ' ? true : false);
        }

        return s1;
    }
    static std::string upperAllLetters(std::string s1)
    {

        for (size_t i = 0; i < s1.length(); i++)
        {
            s1[i] = toupper(s1[i]);
        }

        return s1;
    }
    static std::string lowerFirstLetterOfEachWord(std::string s1)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < s1.length(); i++)
        {
            if (s1[i] != ' ' && isFirstLetter)
            {
                s1[i] = tolower(s1[i]);
            }

            /* if the letter is empty space, the next iteration will be a new word,
                and isFirstLetter flag will become true */
            isFirstLetter = (s1[i] == ' ' ? true : false);
        }

        return s1;
    }
    static std::string lowerAllLetters(std::string s1)
    {

        for (size_t i = 0; i < s1.length(); i++)
        {
            s1[i] = tolower(s1[i]);
        }

        return s1;
    }
    static std::string invertAllLettersCase(std::string s1)
    {
        for (short i = 0; i < s1.length(); i++)
        {
            s1[i] = clsChar::invertCharacterCase(s1[i]);
        }

        return s1;
    }
    static short countCharacter(const std::string& s1, const char& c, bool matchCase = true)
    {
        short count = 0;

        for (short i = 0; i < s1.length(); i++)
        {
            if (matchCase)
            {
                if (s1[i] == c)
                    count++;
            }
            else
            {
                if (tolower(s1[i]) == tolower(c))
                    count++;
            }
        }

        return count;
    }
    static void printEachWordInString(std::string s1, std::string delim = " ")
    {
        short pos = 0;
        std::string sWord; // define a string variable

        // use find() function to get the position of the delimiters
        while ((pos = s1.find(delim)) != std::string::npos)
        {
            sWord = s1.substr(0, pos); // store the word
            if (sWord != "")
                std::cout << sWord << std::endl;

            s1.erase(0, pos + delim.length()); /* erase() until positon and move to next word. */
        }

        if (s1 != "")
        {
            std::cout << s1 << std::endl; // it print last word of the string.
        }
    }
    static short countWords(std::string s1, std::string delimiter = " ")
    {
        short count = 0;
        short pos = 0;
        std::string sWord; // define a string variable

        while ((pos = s1.find(delimiter)) != std::string::npos)
        {

            sWord = s1.substr(0, pos);

            if (sWord != "")
            {
                count++;
            }

            s1.erase(0, pos + delimiter.length());
        }

        if (s1 != "")
        {
            count++;
        }

        return count;
    }
    static std::vector<std::string> split(std::string s1, std::string delimiter = " ")
    {
        std::vector<std::string> v;
        short pos = 0;
        std::string word = "";

        while ((pos = s1.find(delimiter)) != std::string::npos)
        {

            word = s1.substr(0, pos);
            v.push_back(word); // add the word to the vector

            s1.erase(0, pos + delimiter.length());
        }

        // no more delimiter found in the string (last word)
        if (s1 != "")
            v.push_back(s1);

        return v;
    }
    static std::string lTrim(const std::string& s, const char& delimiter = ' ')
    {
        for (short i = 0; i < s.length(); i++)
        {
            if (s[i] != delimiter)
            {
                /*
                    from where we found a char to the end of the (string.length() - i),
                    to execulde first delimiters
                    e.g. : "--Mohammed--" i = 2, return s.substr(i, length - i) from index 2 get next 10 chars
                */
                return s.substr(i, s.length() - i);
            }
        }

        return "";
    }
    static std::string rTrim(const std::string& s, const char& delimiter = ' ')
    {
        for (short i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] != delimiter)
            {
                /*
                    Mohammed--
                    01234567 (until index 7 we have 8 chars)
                    returns new string from the index 0 until next (i + 1) characters.
                */
                return s.substr(0, i + 1);
            }
        }

        return "";
    }
    static std::string trim(const std::string& s, const char& delim = ' ')
    {
        return (lTrim(rTrim(s, delim), delim));
    }
    static std::string join(const std::vector<std::string>& vNames, std::string delimiter = " ")
    {
        std::string word = "";

        for (const std::string& name : vNames)
            word += name + delimiter;

        return word.substr(0, word.length() - delimiter.length()); // to remove the last added sep to the string.
    }
    static std::string join(const std::string array[], short arrLen, std::string seperator)
    {
        std::string word = "";

        for (short i = 0; i < arrLen; i++)
        {
            word += array[i] + seperator;
        }

        return word.substr(0, word.length() - seperator.length());
    }
    static std::string replaceAll(const std::string& originalStr, const std::string& toReplace, const std::string& replaceTo, bool matchCase = true)
    {
        std::string str = originalStr; // the result string we'll modify

        if (matchCase)
        {
            size_t pos = 0;
            while ((pos = str.find(toReplace, pos)) != std::string::npos)
            {
                str.replace(pos, toReplace.length(), replaceTo);
                pos += replaceTo.length();
            }
        }
        else
        {
            std::string strLower = clsString::lowerAllLetters(originalStr);
            std::string toReplaceLower = clsString::lowerAllLetters(toReplace);

            size_t pos = 0;
            while ((pos = strLower.find(toReplaceLower, pos)) != std::string::npos)
            {
                str.replace(pos, toReplace.length(), replaceTo);
                // Keep both str and strLower in sync
                strLower.replace(pos, toReplace.length(), replaceTo); // keep indexes aligned
                pos += replaceTo.length();
            }
        }

        return str;
    }


    // --- Instance methods ---
    short length()
    {
        return length(_value);
    }
    void printFirstLetterOfEachWord()
    {
        printFirstLetterOfEachWord(_value);
    }
    void upperFirstLetterOfEachWord()
    {
        _value = upperFirstLetterOfEachWord(_value); // update the value of the string
    }
    void upperAllLetters()
    {
        _value = upperAllLetters(_value);
    }
    void lowerFirstLetterOfEachWord()
    {
        _value = lowerFirstLetterOfEachWord(_value);
    }
    void lowerAllLetters()
    {
        _value = lowerAllLetters(_value);
    }
    void invertAllLettersCase()
    {
        _value = invertAllLettersCase(_value);
    }
    short countCharacter(const char& c, bool matchCase = true)
    {
        return countCharacter(_value, matchCase);
    }
    void printEachWordInString(std::string delimiter = " ")
    {
        printEachWordInString(_value, delimiter);
    }
    short countWords(std::string delimiter = " ")
    {
        return countWords(_value, delimiter);
    }
    std::vector<std::string> split(std::string delimiter = " ")
    {
        return split(_value, delimiter);
    }
    void lTrim(const char& delimiter = ' ')
    {
        _value = lTrim(_value, delimiter);
    }
    void rTrim(const char& delimiter = ' ')
    {
        _value = rTrim(_value, delimiter);
    }
    void trim(const char& delimiter = ' ')
    {
        _value = trim(_value, delimiter);
    }
    void replaceAll(const std::string& toReplace, const std::string& replaceTo, bool matchCase = true)
    {
        _value = replaceAll(_value, toReplace, replaceTo, matchCase);
    }
};

