#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string sentence;
	cout << "Please enter your string?" << endl;
	getline(cin, sentence);

	return sentence;
}

bool IsVowel(char c)
{
	c = tolower(c);

	return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}

short CountVowelLetters(const string& sentence)
{
	short count = 0;
	
	for (short i = 0; i < sentence.length(); i++)
		if (IsVowel(sentence[i]))
			count++;

	return count;
}

int main()
{
	cout << "\nNumber of vowels: " << CountVowelLetters(ReadString()) << endl;
	return 0;
}