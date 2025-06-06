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

void CapitalizeFirstLetterOfEachWord(string& S1)
{
	bool isFirstLetter = true;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			S1[i] = toupper(S1[i]);
		}

		// if the letter is empty space, the next iteration will be a new word and
		// isFirstLetter flag will become true
		isFirstLetter = (S1[i] == ' ' ? true : false);
	}
}

int main()
{
	string sentence = ReadString();
	cout << sentence << endl;


	CapitalizeFirstLetterOfEachWord(sentence);

	cout << "\n" << sentence << endl;

	return 0;
 }