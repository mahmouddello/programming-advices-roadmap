#include <iostream>
#include <string>
#include <vector>
#include "D:/MyCPP_Libs/stringUtils.h"

using namespace std;

string replaceWordsMatchCase(string originalString, string wordToReplace, string newWord, bool matchCase = true)
{
	vector<string> v = stringUtils::splitString(originalString, " ");

	for (string& str : v)
	{

		// if matchCase is true, only replace the matched words.
		if (matchCase)
		{
			if (str == wordToReplace)
			{
				str = newWord;
			}
		}

		// else, lower each word and compare it with lowering the word to replace, if equals replace it
		// with new word
		else
		{
			if (stringUtils::lowerAllLetters(str) == stringUtils::lowerAllLetters(wordToReplace))
			{
				str = newWord;
			}
		}
	}

	return stringUtils::joinString(v, " ");
}

int main()
{
	//string s1 = stringUtils::readString();
	string s2 = "Mahmoud from Syria , Syria is a wonderful country!";


	cout << "Replace with match case:\n";
	cout << replaceWordsMatchCase(s2, "syria", "USA");

	cout << "\n\nReplace with no match case:\n";
	cout << replaceWordsMatchCase(s2, "syria", "USA", false) << endl;


	return 0;
}
