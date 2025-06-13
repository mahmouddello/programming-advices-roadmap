#include <iostream>

using namespace std;

string ReadPassword()
{
	cout << "Please enter a 3 capital letter password: ";
	
	string password;
	cin >> password;

	return password;

}

bool GuessPassword(string password)
{

	string word = "";
	int counter = 1;

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word += char(i);
				word += char(j);
				word += char(k);


				cout << "Trial [" << counter << "] : " << word << endl;

				if (password == word)
				{
					cout << "Password is " << password << endl;
					cout << "Found after " << counter << " Trial(s)";

					return true;
				}

				else {
					counter++;
					word = "";
				}
			}
		}
	}
}

/*
	CHAT GPT SOLUTION
	#include <iostream>

using namespace std;

const int ASCII_A = 65;
const int ASCII_Z = 90;

// Function to read a password from the user
string ReadPassword(const string& message)
{
	cout << message;
	string password;
	cin >> password;
	return password;
}

// Function to check if the generated word matches the password
bool CheckPassword(const string& generatedWord, const string& password, int trialCount)
{
	cout << "Trial [" << trialCount << "] : " << generatedWord << endl;

	if (generatedWord == password)
	{
		cout << "Password is " << password << endl;
		cout << "Found after " << trialCount << " trial(s)" << endl;
		return true;
	}

	return false;
}

// Function to generate all 3-letter uppercase combinations and check for a match
bool Generate3LetterWord(const string& password)
{
	string word;
	int counter = 1;

	for (char i = ASCII_A; i <= ASCII_Z; i++)
	{
		for (char j = ASCII_A; j <= ASCII_Z; j++)
		{
			for (char k = ASCII_A; k <= ASCII_Z; k++)
			{
				word = {i, j, k};  // Direct assignment

				// Call CheckPassword to verify
				if (CheckPassword(word, password, counter))
					return true;

				counter++;
			}
		}
	}

	return false;
}

int main()
{
	string password = ReadPassword("Please enter a 3 capital letter password: ");
	Generate3LetterWord(password);
	return 0;
}

*/

int main()
{
	
	GuessPassword(ReadPassword());

	return 0;
}