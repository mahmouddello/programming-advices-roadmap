#include <iostream>

using namespace std;

// by default, the values starts from 0 to n
enum Color {
    Red = 100,
    Green = 200,
    Yellow = 300,
    Blue = 400
};

enum Direction {
    East,
    West,
    North,
    South
};

enum Week {
    Sat,
    Sun,
    Mon,
    Tue,
    Wed,
    Thu,
    Fri
};

enum Gender {
    Male,
    Female
};

enum Status {
    Single,
    Married
};

void IntroductionToEnums()
{
    Color MyColor, MyColor2;
    Direction MyDirection;
    Week Today;
    Status MyStatus;


    // This are the same
    MyColor = Color::Yellow;
    MyColor2 = Yellow;

    MyDirection = Direction::North; // MyDirection = North;

    Today = Week::Sat; // saturday

    MyStatus = Status::Single;

    cout << "Color is: " << MyColor << endl;
}

// ----------- HOMEWORK -----------


void Homework()
{
    string name = "Mahmoud Dello", city = "Mersin", country = "Turkey";
    short age = 21;
    float monthlySalary = 5000;
    Gender gender = Gender::Male;
    Status isMarried = Status::Single;

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

int main()
{

    Homework();
    return 0;
}
