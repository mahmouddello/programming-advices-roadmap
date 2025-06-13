#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

void DatatypesDeclrations()
{
    // Note: By default, everything is signed

    // These are the same exact declarations
    int v1;
    signed int v2;

    // double the size of the singed integer
    unsigned int v3;

    // These also the same
    short int v4;
    short v5; // short int

    // Same declaration
    unsigned short int v6;
    unsigned short v7;

    // Same declaration
    signed long int v8;
    long int v9;
    long v10;

    unsigned long v11;

    long long int v12;

    unsigned long long v13;
}

void ExpectedErros()
{
    /*
    Some compilers may give you erros, but others for example like the
    one we are using 'Visual Studio 2022' will not give erros,
    but it will replace things on it's own.

    */
    double distance = 56E12; // 56E12 is equal to 56 * 10^12
    cout << distance << endl;

    short d = 34535; // Error!! Out of range (overflow)
    cout << d << endl; // compiler assigns a random number to d

    unsigned int a = -10; // Unsigned, can only store positive numbers
    cout << a << endl;

}

void SizeofDataTypes()
{
    // Sizes are represnted in bytes

    cout << "The size of bool data type is " << sizeof(bool) << "\n";
    cout << "The size of char data type is " << sizeof(char) << "\n";
    cout << "The size of short data type is " << sizeof(short) << "\n";
    cout << "The size of int data type is " << sizeof(int) << "\n";

    cout << "The size of long data type is " << sizeof(long) << "\n";
    cout << "The size of long long data type is " << sizeof(long long) << "\n";

    cout << "The size of float data type is " << sizeof(float) << "\n";
    cout << "The size of double data type is " << sizeof(double) << "\n";
}

void DatatypesRanges()
{
    cout << "char Range: " << CHAR_MIN << " to " << CHAR_MAX << "\n";
    cout << "unsigned char Range: 0 to " << UCHAR_MAX << "\n";

    cout << "short int Range: " << SHRT_MIN << " to " << SHRT_MAX << "\n";
    cout << "unsigned short int Range: 0 to " << USHRT_MAX << "\n";

    cout << "int Range: " << INT_MIN << " to " << INT_MAX << "\n";
    cout << "unsigned int Range: 0 to " << UINT_MAX << "\n";

    cout << "long int Range: " << LONG_MIN << " to " << LONG_MAX << "\n";
    cout << "unsigned long int Range: 0 to " << ULONG_MAX << "\n";

    cout << "long long int Range: " << LLONG_MIN << " to " << LLONG_MAX << "\n";
    cout << "unsigned long long int Range: 0 to " << ULLONG_MAX << "\n";

    cout << "float Range: " << FLT_MIN << " to " << FLT_MAX << "\n";
    cout << "float (negative) Range: " << -FLT_MIN << " to " << -FLT_MAX << "\n";

    cout << "double Range: " << DBL_MIN << " to " << DBL_MAX << "\n";
    cout << "double (negative) Range: -" << -DBL_MIN << " to -" << -DBL_MAX << "\n";

}

// Homework: Revisit all old homeworks, and edit the data types with the effecient ones.

void HomeworkQ1()
{
    cout << "Program - Question No: 1\n";
    cout << "-------------------------\n";

    short x, y, z; // from int to short

    cout << "Enter x value: " << endl;
    cin >> x;

    cout << "Enter y value: " << endl;
    cin >> y;

    cout << "Enter z value: " << endl;
    cin >> z;

    int sum = x + y + z; // from int to short
    cout << x << " +\n" << y << " +\n" << z << "\n";
    cout << "--------------------------\n" << sum << "\n";
    cout << "--------------------------\n" << endl;
}

void HomeworkQ2()
{
    string name, city, country;
    short age; // from int to short
    float monthlySalary;
    char gender;
    bool isMarried;

    cout << "Program - Question No: 2\n";
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
}

void HomeworkQ3()
{
    cout << "Program - Question No: 3\n";
    cout << "-------------------------\n";

    short age; // int to short
    cout << "Please enter your age: " << endl;
    cin >> age;

    cout << "After 5 years you will be " << age + 5 << " years old." << endl;
}

int main()
{
    
    //ExpectedErros();
    //SizeofDataTypes();
    //DatatypesRanges();
    HomeworkQ1();

    return 0;
}