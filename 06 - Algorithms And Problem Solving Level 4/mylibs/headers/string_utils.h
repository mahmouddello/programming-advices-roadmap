#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "./char_utils.h"

namespace string_utils
{
    std::string readString(std::string message = "Please enter your string: ")
    {
        std::string sentence;
        std::cout << message;
        std::getline(std::cin, sentence);

        return sentence;
    }

    void printFirstLetterOfEachWord(const std::string &s1)
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

    std::string capitalizeFirstLetterOfEachWord(const std::string &s1)
    {
        bool isFirstLetter = true;
        std::string s1Copy = s1; // copy the string to modify it

        for (short i = 0; i < s1.length(); i++)
        {
            if (s1Copy[i] != ' ' && isFirstLetter)
            {
                s1Copy[i] = toupper(s1[i]);
            }

            /* if the letter is empty space, the next iteration will be a new word,
                and isFirstLetter flag will become true */
            isFirstLetter = (s1Copy[i] == ' ' ? true : false);
        }

        return s1Copy;
    }

    std::string lowerFirstLetterOfEachWord(const std::string &s1)
    {
        bool isFirstLetter = true;
        std::string s1Copy = s1; // copy the string to modify it

        for (short i = 0; i < s1Copy.length(); i++)
        {
            if (s1Copy[i] != ' ' && isFirstLetter)
            {
                s1Copy[i] = tolower(s1Copy[i]);
            }

            /* if the letter is empty space, the next iteration will be a new word,
                and isFirstLetter flag will become true */
            isFirstLetter = (s1Copy[i] == ' ' ? true : false);
        }

        return s1Copy;
    }

    std::string lowerAllLetters(const std::string &s1)
    {
        std::string s1Copy = s1; // copy the string to modify it

        for (size_t i = 0; i < s1Copy.length(); i++)
        {
            s1Copy[i] = tolower(s1Copy[i]);
        }

        return s1Copy;
    }

    std::string upperAllLetters(const std::string &s1)
    {
        std::string s1Copy = s1; // copy the string to modify it

        for (size_t i = 0; i < s1Copy.length(); i++)
        {
            s1Copy[i] = toupper(s1Copy[i]);
        }

        return s1Copy;
    }

    std::string invertAllLettersCase(const std::string &s1)
    {
        std::string s1Copy = s1; // copy the string to modify it

        for (short i = 0; i < s1.length(); i++)
        {
            s1Copy[i] = char_utils::invertCharacterCase(s1Copy[i]);
        }

        return s1Copy;
    }

    int countCharacterInString(const std::string &s1, const char &c, bool matchCase = true)
    {
        int count = 0;

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

    short countVowelLetters(const std::string &sentence)
    {
        short count = 0;

        for (short i = 0; i < sentence.length(); i++)
            if (char_utils::isVowel(sentence[i]))
                count++;

        return count;
    }

    void printEachWordInString(std::string s1, std::string delim = " ")
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

    int countWords(const std::string& s1, std::string delimiter = " ")
    {

        std::string s1Copy = s1; // copy the string to modify it
        short count = 0;
        short pos = 0;
        std::string sWord; // define a string variable

        while ((pos = s1Copy.find(delimiter)) != std::string::npos)
        {

            sWord = s1Copy.substr(0, pos);

            if (sWord != "")
            {
                count++;
            }

            s1Copy.erase(0, pos + delimiter.length());
        }

        if (s1Copy != "")
        {
            count++;
        }

        return count;
    }

    std::vector<std::string> splitString(const std::string &s1, std::string delimiter = " ")
    {
        std::vector<std::string> v;
        short pos = 0;
        std::string word = "";
        std::string s1Copy = s1; // copy the string to modify it

        while ((pos = s1Copy.find(delimiter)) != std::string::npos)
        {

            word = s1Copy.substr(0, pos);

            if (word != "")
                v.push_back(word);

            s1Copy.erase(0, pos + delimiter.length());
        }

        // no more delimiter found in the string (last word)
        if (s1Copy != "")
            v.push_back(s1Copy);

        return v;
    }

    std::string lTrim(const std::string &s, const char &delimiter = ' ')
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

    std::string rTrim(const std::string &s, const char &delimiter = ' ')
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

    std::string trim(const std::string &s, const char &delim = ' ')
    {
        return (lTrim(rTrim(s, delim), delim));
    }

    std::string joinString(const std::vector<std::string> &vNames, std::string delimiter = " ")
    {
        std::string word = "";

        for (const std::string &name : vNames)
            word += name + delimiter;

        return word.substr(0, word.length() - delimiter.length()); // to remove the last added sep to the string.
    }

    std::string joinString(const std::string array[], short arrLen, std::string seperator)
    {
        std::string word = "";

        for (short i = 0; i < arrLen; i++)
        {
            word += array[i] + seperator;
        }

        return word.substr(0, word.length() - seperator.length());
    }

    std::string replaceWords(const std::string& originalStr, const std::string& toReplace, const std::string &replaceTo, bool matchCase = true)
    {
        std::vector<std::string> v = string_utils::splitString(originalStr);

        for (std::string &str : v)
        {

            // if matchCase is true, only replace the matched words.
            if (matchCase)
            {
                if (str == toReplace)
                {
                    str = replaceTo;
                }
            }

            // else, lower each word and compare it with lowering the word to replace, if equals replace it
            // with new word
            else
            {
                if (string_utils::lowerAllLetters(str) == string_utils::lowerAllLetters(toReplace))
                {
                    str = replaceTo;
                }
            }
        }

        return string_utils::joinString(v, " ");
    }

    std::string replaceAll(const std::string &originalStr, const std::string &toReplace, const std::string &replaceTo, bool matchCase = true)
    {
        std::string str = originalStr; // copy the string to modify it

        // if matchCase is true, only replace the matched words.
        if (matchCase)
        {
            while (str.find(toReplace) != std::string::npos)
            {
                str.replace(str.find(toReplace), toReplace.length(), replaceTo);
            }
        }
        else
        {
            while (str.find(string_utils::lowerAllLetters(toReplace)) != std::string::npos)
            {
                str.replace(str.find(string_utils::lowerAllLetters(toReplace)), toReplace.length(), replaceTo);
            }
        }

        return str;
    }

}
