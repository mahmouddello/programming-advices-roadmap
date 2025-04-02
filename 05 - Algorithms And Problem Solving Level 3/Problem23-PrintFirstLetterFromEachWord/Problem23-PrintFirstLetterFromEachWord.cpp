#include <iostream>
#include <string>


using namespace std;

void FirstLetterProgrammingAdvices(string S1)
{
	bool isFirstLetter = true;
	cout << "\nFirst letters of this string: \n";
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			cout << S1[i] << endl;
		}

		// if the letter is empty space, the next iteration will be a new word and
		// isFirstLetter flag will become true
		isFirstLetter = (S1[i] == ' ' ? true : false);
	}
}

void PrintFirstLetterFromEachWord(string sentence)
{
	string word = "";
	
	for (int i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] != char(32) && i != sentence.length() - 1)
			word += sentence[i];
		else
		{
			cout << word[0] << endl;
			word = "";
		}	
	}
}

int main() {

	string sentence;
	cout << "Please enter your string? ";
	getline(cin, sentence);

	cout << sentence << endl;
	cout << "\nFirst letters from each word in the sentence:" << endl;
	
	PrintFirstLetterFromEachWord(sentence);

	return 0;
}