#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	split:
	1 - Read String
	2 - create function named split of type vector
	3 - params: string word, string delimiter
	4 - use the delimiter to detect each word and add it the vector
	5 - return the vector

	main:
	- Each part or word in a string called token
	- Print number of tokens
	- Print the word stored inside the vector
*/

string ReadString()
{
	string sentence;
	cout << "Please enter your string?" << endl;
	getline(cin, sentence);

	return sentence;
}

vector<string> SplitString(string s1, string delimiter)
{
	vector<string> v;
	short pos = 0;
	string word = "";

	while ((pos = s1.find(delimiter)) != string::npos)
	{
		cout << "found the delimiter at pos: " << pos << endl;

		word = s1.substr(0, pos);

		if (word != "")
			v.push_back(word);

		s1.erase(0, pos + delimiter.length());
	}

	// no more delimiter found in the string (last word)
	if (s1 != "")
		v.push_back(s1);

	return v;
}

int main()
{
	string s1 = ReadString();
	string s2 = "Mohammad#,,#Ahmad#,,#Mazen";

	vector<string> vTokens = SplitString(s2, "#,,#");

	cout << "\nTokens: " << vTokens.size() << endl;

	for (const string& temp : vTokens)
		cout << temp << endl;

	return 0;
}