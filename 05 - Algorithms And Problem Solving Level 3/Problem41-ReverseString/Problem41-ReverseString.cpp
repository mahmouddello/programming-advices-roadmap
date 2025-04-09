#include <iostream>
#include <string>
#include <vector>
#include "D:/MyCPP_Libs/stringUtils.h"

using namespace std;

// My 2 Solutions
string reverseString(string s1, char delimiter)
{
	string reversedWord = "";

	for (short i = s1.length() - 1; i >= 0; i--)
	{

		if (s1[i] == delimiter)
		{

			reversedWord += s1.substr(i + 1, s1.length() - 1) + delimiter;
			s1.erase(i, s1.length() - 1);
		}
	}

	// if no delimiter left
	if (s1 != "")
		reversedWord += s1;

	return reversedWord;
}

string reverseStringRangedLoop(string s1, char delimiter)
{
	string word = "";
	vector<string> vTemp;

	for (const char& c : s1)
	{
		if (c == delimiter)
		{
			vTemp.push_back(word);
			word = "";
		}
		else
		{
			word += c;
		}
	}

	// if no delimiter found it's last word (from backward)
	if (!word.empty())
		vTemp.push_back(word);

	string reversedWord = "";

	for (short i = vTemp.size() - 1; i >= 0; i--)
	{
		reversedWord += vTemp.at(i);

		if (i > 0)
			reversedWord += delimiter;
	}

	return reversedWord;
}

// Programming Advices Solution
string reverseWordsInString(string S1)
{
	vector<string> vString;
	string S2 = "";
	vString = stringUtils::splitString(S1, " ");

	// declare iterator
	vector<string>::iterator iter = vString.end();
	while (iter != vString.begin())
	{
		--iter;
		S2 += *iter + " ";
	}

	S2 = S2.substr(0, S2.length() - 1); //remove last space.
	return S2;
}

int main()
{
	string word = stringUtils::readString();

	cout << "\n\nReversed String:\n" << reverseWordsInString(word) << endl;

	return 0;
}