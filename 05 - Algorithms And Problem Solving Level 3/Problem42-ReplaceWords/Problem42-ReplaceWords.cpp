#include <iostream>
#include <string>
#include "D:/MyCPP_Libs/stringUtils.h"

using namespace std;

string replaceWords(string originalString, string wordToReplace, string newWord)
{
	short pos = 0;
	
	while ((pos = originalString.find(wordToReplace)) != string::npos)
	{
		cout << "\nRemoving " << wordToReplace << " found at position: " << pos << endl;
		originalString.erase(pos, wordToReplace.length());

		cout << "\nAdding the new string in the position " << pos << endl;
		originalString.insert(pos, newWord);

		cout << "\nnew original string status: " << originalString << endl;
	}

	return originalString;
}

string replaceWordInStringUsingBuiltinFunction(string s1, string toReplace, string replaceTo)
{
	short pos = s1.find(toReplace);

	cout << "position= " << pos << endl;

	while (pos != string::npos)
	{
		s1 = s1.replace(pos, toReplace.length(), replaceTo);
		pos = s1.find(toReplace); // find next word's position to replace
		cout << "position= " << pos << endl;


	}

	return s1;
}

int main()
{
	string s1 = stringUtils::readString();

	cout << replaceWords(s1, "Syria", "USA") << endl;
	cout << "\n\n" << replaceWordInStringUsingBuiltinFunction(s1, "Syria", "Canada") << endl;

	return 0;
}