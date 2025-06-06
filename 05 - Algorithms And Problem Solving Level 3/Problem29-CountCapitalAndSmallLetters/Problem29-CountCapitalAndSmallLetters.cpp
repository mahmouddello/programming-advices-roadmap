#include <iostream>
#include <string>

using namespace std;

string ReadString();
int CountCapitalLetters(string);
int CountSmallLetters(string);

enum enWhatToCount {smallLetter = 0, capitalLetter = 1, all = 2};

// generic function
int CountLetters(string s1, enWhatToCount letterType = enWhatToCount::all)
{
	int count = 0;
	
	if (letterType == enWhatToCount::all)
		return s1.length();

	for (short i = 0; i < s1.length(); i++)
	{
		if (letterType == enWhatToCount::capitalLetter && isupper(s1[i]))
			count++;

		if (letterType == enWhatToCount::smallLetter && islower(s1[i]))
			count++;
	}

	return count;
}

string ReadString()
{
	string sentence;
	cout << "Please enter your string?" << endl;
	getline(cin, sentence);

	return sentence;
}

int CountCapitalLetters(string s1)
{
	short count = 0;

	for (short i = 0; i < s1.length(); i++)
		if (isupper(s1[i]))
			count++;
	
	return count;
}

int CountSmallLetters(string s1)
{
	short count = 0;

	for (short i = 0; i < s1.length(); i++)
		if (islower(s1[i]))
			count++;

	return count;
}

int main()
{
	string s1 = ReadString();

	cout << "\nString Length is: " << s1.length() << endl;
	cout << "Capital Letters Count = " << CountCapitalLetters(s1) << endl;
	cout << "Small Letters Count = " << CountSmallLetters(s1) << endl;

	cout << "\n------ Using Generic Function ------\n";
	cout << "\nString Length is: " << CountLetters(s1) << endl;
	cout << "Capital Letters Count = " << CountLetters(s1, enWhatToCount::capitalLetter) << endl;
	cout << "Small Letters Count = " << CountLetters(s1, enWhatToCount::smallLetter) << endl;


	return 0;
}