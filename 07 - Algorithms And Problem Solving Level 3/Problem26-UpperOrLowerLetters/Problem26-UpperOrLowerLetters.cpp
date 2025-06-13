#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string sentence;
	cout << "Please enter your string? ";
	getline(cin, sentence);

	return sentence;
}

string UpperAllLetters(string S1)
{
	
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}

	return S1;
}

string LowerAllLetters(string S1)
{
	
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}

	return S1;
}

string UpperLetterRangedLoop(string S1)
{
	for (char& c : S1)
	{
		c = toupper(c);
	}

	return S1;
}

int main()
{
	string sentence = ReadString();

	string upperedSentence = UpperAllLetters(sentence);
	string loweredSentence = LowerAllLetters(sentence);


	cout << "\nString after upper:\n" << upperedSentence << endl;
	cout << "\nString after lower:\n" << loweredSentence << endl;

	cout << "\nUpper V2:\n" << UpperLetterRangedLoop(sentence) << endl;

	return 0;
}