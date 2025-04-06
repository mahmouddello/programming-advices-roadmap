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

int CountWords(string S1)
{
    string delim = " "; // delimiter

    short count = 0;
    short pos = 0;
    string sWord; // define a string variable 

    while ((pos = S1.find(delim)) != string::npos)
    {
        
        sWord = S1.substr(0, pos);

        if (sWord != "")
        {
            count++;
        }

        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        count++;
    }

    return count;
}

int main()
{
    string s1 = ReadString();

    cout << "\n\nThe number of words in this string is: " << CountWords(s1) << endl;

    return 0;
}
