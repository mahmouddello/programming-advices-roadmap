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

bool isNewWord(char c)
{
    return c == ' ';
}

void PrintEachWord(string s1)
{
    string word = "";

    for (short i = 0; i < s1.length(); i++)
    {
        if (!isNewWord(s1[i]))
        {
            word += s1[i]; // build the word
        }
        else
        {
            if (word != "")
            {
                cout << word << endl;
                word = ""; // reset after printing
            }
        }
    }

    // Handle the last word (no space after it)
    if (word != "")
    {
        cout << word << endl;
    }
}

void PrintEachWordInString(string S1)
{
    string delim = " "; // delimiter
    cout << "\nYour string wrords are: \n\n";

    short pos = 0;
    string sWord; // define a string variable 
    
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(delim)) != string::npos)
    {
        cout << "\nfound the delimiter at position: " << pos << endl;

        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            cout << "Current word:" << sWord << endl;
        }

        S1.erase(0, pos + delim.length()); /* erase() until positon and move to next word. */
        cout << "\nnew string:" << S1 << endl;
    }

    cout << "\nNo more spaces, last word" << endl;

    if (S1 != "")
    {
        cout << S1 << endl; // it print last word of the string.
    }
}

int main()
{
    string s1 = ReadString();

    PrintEachWordInString(s1);

    return 0;
}
