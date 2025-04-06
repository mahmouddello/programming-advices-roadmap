#include <iostream>
#include <string>
#include <vector>

using namespace std;

string joinString(vector<string> vNames, string seperator)
{
	string word = "";

	for (const string& name : vNames)
		word += name + seperator;

	return word.substr(0, word.length() - seperator.length()); // to remove the last added sep to the string.
}

string joinString(string array[], short arrLen, string seperator)
{
	string word = "";

	for (short i = 0; i < arrLen; i++)
	{
		word += array[i] + seperator;
	}

	return word.substr(0, word.length() - seperator.length());
}

int main()
{
	vector<string> vNames{ "Mohammed", "Ali", "Maher", "Fadi" };
	string joinedStrVector = joinString(vNames, " ");
	cout << "Vector after join:\n" << joinedStrVector << endl;


	string nameArr[] = { "Mohammed", "Ali", "Maher", "Fadi" };
	short length = sizeof(nameArr) / sizeof(nameArr[0]);
	string joinedStrArr = joinString(nameArr, length, " ");
	cout << "\nArray after join:\n" << joinedStrArr << endl;

	return 0;
}