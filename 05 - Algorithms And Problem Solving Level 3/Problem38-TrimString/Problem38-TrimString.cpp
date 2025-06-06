#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string sentence;
	cout << "Please enter your string?" << endl;
	getline(cin, sentence);

	return sentence;
}

string LTrim(string s, char delim)
{
	for (short i = 0; i < s.length(); i++)
	{
		if (s[i] != delim)
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

string RTrim(string s, char delim)
{
	for (short i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] != delim)
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

string Trim(string s, char delim)
{
	return(LTrim(RTrim(s, delim), delim));
}

int main()
{
	string s = ReadString();

	cout << Trim(s, ' ') << endl;

	return 0;
}