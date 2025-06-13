#include <iostream>

using namespace std;

// Problems in order, from #21 to #25

const float PI = 3.14;

// ------- Problem #21 - Circle Area Along the Circumference ------- 

float ReadCircumference()
{
    float l;

    cout << "Enter the circumference: ";
    cin >> l;

    return l;
}

float CircleAreaAlongTheCircumference(float l)
{
    return (pow(l, 2)) / (4 * PI);
}

void PrintCircleArea(float area)
{
    cout << "Circle Area = " << area << endl;
}

// ------- Problem #22 Circle Area Inscribed in an Isosceles Triangle -------

void ReadInscribedTringleSides(float& a, float& b)
{
    cout << "Enter a's value: ";
    cin >> a;

    cout << "Enter b's value: ";
    cin >> b;
}

float CircleAreaInscribedInAnIsoscelesTriangle(float a, float b)
{
    return (PI * (pow(b, 2) / 4)) * ((2 * a - b) / (2 * a + b));
}

// Use PrintCircleArea from Problem #21

// ------- Problem #23 - Circle Area circle Described Around an Arbitrary Triangle -------

void ReadAbritaryTringleInfo(float& a, float& b, float& c)
{
    cout << "Enter a's value: ";
    cin >> a;

    cout << "Enter b's value: ";
    cin >> b;

    cout << "Enter c's value: ";
    cin >> c;

}

float CircleAreaCircleDescribedAroundAnArbitraryTriangle(float a, float b, float c)
{
    float p = (a + b + c) / 2;

    return PI * pow(((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)))), 2);

}

// Use PrintCircleArea from Problem #21

// ------- Problem #24 Validate Age Between 18 and 45 -------

int ReadAge()
{
    int age;

    cout << "Please enter your age: ";
    cin >> age;

    return age;

}

bool ValidateAge(int age)
{
    return (age >= 18 && age <= 45);
}

void PrintAgeResult(bool result)
{
    if (result)
        cout << "Valid Age" << endl;

    else
        cout << "Invalid Age" << endl;
}

// ------- Problem #25 Read Until Age Between 18 and 45 -------

int ValidateAgeInRange()
{
    int age;

    do {
        age = ReadAge();
    } while (!ValidateAge(age));

    return age;

}

int main()
{

    PrintAgeResult(ValidateAgeInRange());
    return 0;

}
