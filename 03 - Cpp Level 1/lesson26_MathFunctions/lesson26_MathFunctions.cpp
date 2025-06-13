#include <iostream>
#include <cmath>
using namespace std;

void SqrtExplination()
{
    // sqrt: Square Root of a number

    double x = 64;
    cout << sqrt(x) << endl; // gives 8
    cout << sqrt(50) << endl; // 7.07107

}

void RoundExplination()
{
   cout << round(2.4) << endl;   // gives 2
   cout << round(2.5) << endl;   // gives 3
   cout << round(2.7) << endl;   // gives 3
   cout << sqrt(50) << endl;     // gives 7.07107
   cout << round(sqrt(50)) << endl; // gives 7
}

void PowerExplination()
{
    int x = 2, y = 4;

    cout << "x^y = 2^4 = " << pow(x, y) << endl;
    cout << "2^3 = " << pow(2, 3) << endl;

}

void FloorAndCeilExplination()
{

    cout << ceil(2.9) << endl; // 3
    cout << floor(2.9) << endl; // 2

    cout << ceil(-2.9) << endl; // -2
    cout << floor(-2.9) << endl; // -3
}

void AbsExplination()
{
    cout << abs(-10) << endl; // gives 10
    cout << abs(10) << endl; // gives 10

}

// --------- HOMEWORK ------------

void Problem16()
{
    // Problem #16 - Rectangle area Through Diagonal and Side Area
    float a, d, area;

    cout << "Enter a's value: ";
    cin >> a;

    cout << "Enter d's value: ";
    cin >> d;

    area = a * sqrt(pow(d, 2) - pow(a, 2));

    cout << "Area = " << area << endl;
}

void Problem18()
{
    float r, area;
    const float PI = 3.14;

    cout << "Enter r's value: ";
    cin >> r;

    area = PI * pow(r, 2);

    cout << "Area = " << area << endl;

}

void Problem19()
{
    // Problem #19 - Circle Area Through Diameter

    float d, area;
    const float PI = 3.14;

    cout << "Enter d's value: ";
    cin >> d;

    area = (PI * pow(d, 2)) / 4;

    cout << "Area = " << area << endl;

}

void Problem20()
{
    // Problem #20 Circle Area Inscribed in a Square

    float A, area;
    const float PI = 3.14;

    cout << "Enter A's value: ";
    cin >> A;

    area = (PI * pow(A, 2)) / 4;

    cout << "Area = " << area << endl;

}

void Problem21()
{
    // Problem #21 - Circle Area Along the Circumference
    const float PI = 3.14;
    float L, area;

    cout << "Enter L's value: ";
    cin >> L;

    area = pow(L, 2) / (4 * PI);
    cout << "Area = " << area << endl;

}

void Problem22()
{
    // Problem #22 Circle Area Inscribed in an Isosceles Triangle

    const float PI = 3.14;
    float a, b, area;

    cout << "Enter a's value: ";
    cin >> a;

    cout << "Enter b's value: ";
    cin >> b;

    area = PI * (pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));
    cout << "Area = " << area << endl;

}

void Problem23()
{
    // Problem #23 - Circle Area circle Described Around an Arbitrary Triangle

    const float PI = 3.14;
    float a, b, c, p, area;

    cout << "Enter a's value: ";
    cin >> a;

    cout << "Enter b's value: ";
    cin >> b;

    cout << "Enter c's value: ";
    cin >> c;

    p = (a + b + c) / 2;

    area = PI * pow(((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)))), 2);

    cout << "Area = " << area << endl;

}

void Problem31()
{
    // Problem #31 Power of 2,3,4

    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << number << " ^ 2 = " << pow(number, 2) << endl;
    cout << number << " ^ 3 = " << pow(number, 3) << endl;
    cout << number << " ^ 4 = " << pow(number, 4) << endl;

}

void Problem32()
{
    // Problem #32 Power of m

    int number, exponent;

    cout << "Enter a number: ";
    cin >> number;

    cout << "Enter a exponent: ";
    cin >> exponent;

    cout << number << " ^ " << exponent << " = " << pow(number, exponent) << endl;

}

void Problem42()
{
    // Problem #42 - Task Duration In Seconds

    unsigned short days, hours, minutes, seconds;
    unsigned int totalSeconds;
    unsigned int secondsInDay = 24 * pow(60, 2);
    unsigned int secondsInHour = pow(60, 2);
    unsigned int secondsInMinutes = 60;

    cout << "Input days: ";
    cin >> days;

    cout << "Input hours: ";
    cin >> hours;

    cout << "Input minutes: ";
    cin >> minutes;

    cout << "Input seconds: ";
    cin >> seconds;

    totalSeconds = (days * secondsInDay) + (hours * secondsInHour) + (minutes * secondsInMinutes) + seconds;

    cout << "Total seconds is = " << totalSeconds << endl;


}

void Problem43()
{
    // Problem #43 - Seconds to Days Hours Minutes Seconds

    unsigned short days, hours, minutes, seconds;
    unsigned int totalSeconds, reminder;
    unsigned int secondsInDay = 24 * pow(60, 2);
    unsigned int secondsInHour = pow(60, 2);
    unsigned int secondsInMinutes = 60;

    cout << "Input total seconds: ";
    cin >> totalSeconds;

    days = totalSeconds / secondsInDay;
    reminder = totalSeconds % secondsInDay; // reminder from this is hours represnted in day, .3 days which is 24/3 = 8

    hours = reminder / secondsInHour;
    reminder = totalSeconds % secondsInHour;

    minutes = reminder / secondsInMinutes;
    reminder = totalSeconds % secondsInMinutes;

    seconds = reminder;

    cout << days << ":" << hours << ":" << minutes << ":" << seconds << endl;

}

int main()
{
    Problem43();
    return 0;
}
