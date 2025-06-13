

#include <iostream>
using namespace std;

enum enScreenColor { Red = 1, Blue = 2, Green = 3, Yellow = 4 };
enum enCountryChoice { Jordan = 1, Tunisa = 2, Algeria = 3, Oman = 4, Egypt = 5, Iraq = 6, Other = 7 };

void EnumsExample1()
{
    cout << "****************************\n";
    cout << "Please Chose the number of your color?\n";
    cout << "(1) Red\n";
    cout << "(2) Blue\n";
    cout << "(3) Green\n";
    cout << "(4) Yellow\n";
    cout << "****************************\n\n";
    cout << "Your Choice? ";

    int c;
    enScreenColor Color;

    cin >> c;
    Color = (enScreenColor)c;

    if (Color == enScreenColor::Red)
    {
        system("color 4F");

    }
    else if (Color == enScreenColor::Blue)
    {
        system("color 1F");
    }
    else if (Color == enScreenColor::Green)
    {
        system("color 2F");
    }
    else if (Color == enScreenColor::Yellow)
    {
        system("color 6F");
    }

    else

    {
        system("color 4F");
    };
}

void EnumsExample2()
{
    cout << "****************************\n";
    cout << "Please Enter the number of your country?\n";
    cout << "(1) Jordan\n";
    cout << "(2) Tunisa\n";
    cout << "(3) Algeria\n";
    cout << "(4) Oman\n";
    cout << "(5) Egypt\n";
    cout << "(6) Iraq\n";
    cout << "(7) Other\n";
    cout << "****************************\n\n";
    cout << "Your Choice? ";

    int c;
    enCountryChoice Coutnry;

    cin >> c;
    Coutnry = (enCountryChoice)c;

    if (Coutnry == enCountryChoice::Jordan)
    {
        cout << "Your country is Jordan\n";

    }
    else if (Coutnry == enCountryChoice::Tunisa)
    {
        cout << "Your country is Tunisa\n";
    }
    else if (Coutnry == enCountryChoice::Algeria)
    {
        cout << "Your country is Algeria\n";
    }
    else if (Coutnry == enCountryChoice::Oman)
    {
        cout << "Your country is Oman\n";
    }
    else if (Coutnry == enCountryChoice::Egypt)
    {
        cout << "Your country is Egypt\n";
    }
    else if (Coutnry == enCountryChoice::Iraq)
    {
        cout << "Your country is Iraq\n";
    }
    else

    {

        cout << "Your country is Other\n";
    }
}

int main()
{
    EnumsExample2();
    return 0;
}

