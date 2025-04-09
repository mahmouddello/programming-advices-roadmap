#include <iostream>
#include <string>
#include <vector>
#include "D:/MyCPP_Libs/stringUtils.h"

using namespace std;

string removePunctuationsFromString(string s1)
{
	vector<string> vTemp = stringUtils::splitString(s1, " ");

	for (string& word : vTemp)
	{
		for (size_t i = 0; i < word.length(); i++)
		{
			if (ispunct(word[i]))
				word.replace(i, 1, "");
			// we can also use word.erase(i, 1) which remove 1 character from position (i)
		}
	}

	return stringUtils::joinString(vTemp, " ");
}

string removePunctV2(string s1)
{
	string s2 = "";

	for (short i = 0; i < s1.length(); i++)
	{
		if (!ispunct(s1[i]))
			s2 += s1[i];
	}

	return s2;
}

int main()
{
	string s = "Welcome to Jordan, Jordan is a nice country; it's amazing.";

	cout << "Original String:\n" << s << endl;

	cout << "\nPunctuations removed:\n" << removePunctuationsFromString(s) << endl;
	cout << "\nPunctuations removed:\n" << removePunctV2(s) << endl;

	return 0;
}