#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "My Name is Mahmoud Dello, I love programming.";

    // prints the length of the string object
    cout << s1.length() << endl;

    // retunrs the letter at n.th position (0 based indexing)
    cout << s1.at(3) << endl;

    // adds @ProgrammingAdvices to the end of the string
    s1.append(" @ProgrammingAdvices");
    cout << s1 << endl;

    //inserts Ali at position 7
    s1.insert(7, " Ali ");
    cout << s1 << endl;

    //Prints all the next 7 letters from position 16.
    cout << s1.substr(16, 7) << endl;


    // Adds one character to the end of the string
    s1.push_back('X');
    cout << s1 << endl;

    //Removes one character from the end of the string
    s1.pop_back();
    cout << s1 << endl;

    //Finds Ali in the string
    cout << s1.find("Ali") << endl;

    //Finds ali in the string
    cout << s1.find("ali") << endl;

    // npos: long number represent no position
    if (s1.find("ali") == s1.npos)
    {
        cout << "ali is not found";
    }

    //clears all string letters.
    s1.clear();
    cout << s1 << endl;

    return 0;
}

