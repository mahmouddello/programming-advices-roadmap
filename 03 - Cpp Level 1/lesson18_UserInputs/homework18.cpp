#include <iostream>
#include <limits>
#include "homework18.h"
using namespace std;


void QuestionOne()
{
    string name, city, country;
    int age;
    float monthlySalary;
    char gender;
    bool isMarried;

    cout << "Program - Question No: 1\n";
    cout << "-------------------------\n";

    cout << "Please enter your name? " << endl;
    cin >> name;

    cout << "Please enter your age? " << endl;
    cin >> age;

    cout << "Please enter your city? " << endl;
    cin >> city;

    cout << "Please enter your country? " << endl;
    cin >> country;

    cout << "Please enter your monthly salary? " << endl;
    cin >> monthlySalary;

    cout << "Please enter your gender (\'M\', \'F\')? " << endl;
    cin >> gender;

    cout << "Are you married (\'true / 1 \', \'false / 0\')? " << endl;
    cin >> isMarried;

    cout << "---------------------\n";
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "City: " << city << "\n";
    cout << "Country: " << country << "\n";
    cout << "Monthly Salary: " << monthlySalary << "\n";
    cout << "Yearly Salary: " << monthlySalary * 12 << "\n";
    cout << "Gender: " << gender << "\n";
    cout << "Married: " << isMarried << "\n";
    cout << "--------------------------\n" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
}

void QuestionTwo()
{
    cout << "Program - Question No: 2\n";
    cout << "-------------------------\n";

    int x, y, z;

    cout << "Enter x value: " << endl;
    cin >> x;

    cout << "Enter y value: " << endl;
    cin >> y;

    cout << "Enter z value: " << endl;
    cin >> z;

    int sum = x + y + z;
    cout << x << " +\n" << y << " +\n" << z << "\n";
    cout << "--------------------------\n" << sum << "\n";
    cout << "--------------------------\n" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
}

void QuestionThree()
{
    cout << "Program - Question No: 3\n";
    cout << "-------------------------\n";

    int age;
    cout << "Please enter your age: " << endl;
    cin >> age;

    cout << "After 5 years you will be " << age + 5 << " years old." << endl;
}
