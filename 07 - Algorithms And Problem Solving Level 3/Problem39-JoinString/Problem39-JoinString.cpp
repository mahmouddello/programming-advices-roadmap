#include <iostream>
#include <string>
#include <vector>

using namespace std;

string joinString(vector<string> vNames, string seperator)
{
	vector<string>::iterator iter;
	string word = "";

	for (iter = vNames.begin(); iter != vNames.end(); iter++)
	{
		
		word += *iter;
		
		if (iter != vNames.end() - 1)
			word += seperator;
	}

	return word;
}

string joinStringProgrammingAdvices(vector<string> vNames, string seperator)
{
	string word = "";

	for (const string& name : vNames)
		word += name + seperator;

	return word.substr(0, word.length() - seperator.length()); // to remove the last added sep to the string.
}

int main()
{
	vector<string> vNames{ "Mohammed", "Ali", "Maher", "Fadi" };

	string joinedString = joinStringProgrammingAdvices(vNames, "###");

	cout << "Vector after join:\n" << joinedString << endl;

	return 0;
}