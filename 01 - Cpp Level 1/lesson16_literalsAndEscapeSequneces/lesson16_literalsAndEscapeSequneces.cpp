#include <iostream>
#include "homework16.h"
using namespace std;

int main()
{
    ///*
    //The compiler interpreted the `\` character in the string "M1\M2" as an escape character,
    //which is not a valid escape sequence. As a result, the `\` did not appear in the output.
    //*/
    //cout << "M1\M2 \n";

    ///*
    //The second backslash escapes the first one, 
    //indicating to the compiler that it should treat the 
    //backslash as a literal character to be printed.
    //*/
    //cout << "M1\\M2 \n\n"; 
    //

    //// \t is tab which is 4 spaces.
    //cout << "M1\tM2 \n";
    //cout << "M3\tM4 \n\n";

    // // \" is important becuase some times we need print a name inside of double quotaion.
    //cout << "My name is \"Mahmoud\"\n";

    //cout << "\a";

    questionOne();
    questionTwo();
    questionThree();

    return 0;
}
