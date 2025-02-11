#include <iostream>
using namespace std;

struct Owner
{
    // Owner Information
    string name;
    string phoneNumber;
    short age;

};

struct Car 
{
    // we organized all these variables under one struct

    string brand;
    string model;
    short year;

    Owner owner; // another user defined struct variable.

};

void StructExplination()
{
    // like when creating a normal variable `int` , `Car` here also a "User Defined" datatype.
    Car myCar1, myCar2;

    // easier access to related variable
    myCar1.brand = "Audi";
    myCar1.model = "A7";
    myCar1.year = 2022;

    // Car1 Owner - notice how we access variable of Owner struct from Car struct.
    myCar1.owner.name = "Mahmoud";
    myCar1.owner.age = 21;
    myCar1.owner.phoneNumber = "05318554074";

    myCar2.brand = "BMW";
    myCar2.model = "X5";
    myCar2.year = 2020;

    // Car2 Owner
    myCar2.owner.name = "Anas";
    myCar2.owner.age = 23;
    myCar2.owner.phoneNumber = "05056668289";

    // Print details for myCar1
    cout << "Car 1 Details:" << endl;
    cout << "Brand: " << myCar1.brand << endl;
    cout << "Model: " << myCar1.model << endl;
    cout << "Year: " << myCar1.year << endl;
    cout << "Owner: " << myCar1.owner.name << endl;
    cout << "Owner Age: " << myCar1.owner.age << endl;
    cout << "Owner Phone Number: " << myCar1.owner.phoneNumber << endl;
    cout << endl;

    // Print details for myCar2
    cout << "Car 2 Details:" << endl;
    cout << "Brand: " << myCar2.brand << endl;
    cout << "Model: " << myCar2.model << endl;
    cout << "Year: " << myCar2.year << endl;
    cout << "Owner: " << myCar2.owner.name << endl;
    cout << "Owner Age: " << myCar2.owner.age << endl;
    cout << "Owner Phone Number: " << myCar2.owner.phoneNumber << endl;
}

// --------- HOMEWORK ---------

struct Person
{
    
    string name, city, country;
    short age;
    unsigned int monthlySalary;
    char gender;
    bool isMarried;

};

void Homework()
{
    Person person1;

    person1.name = "Mahmoud Dello";
    person1.age = 21;
    person1.city = "Mersin";
    person1.country = "Turkey";
    person1.monthlySalary = 5000;
    person1.gender = 'M';
    person1.isMarried = false;

    cout << "***********************" << endl;
    cout << "Name: " << person1.name << endl;
    cout << "Age: " << person1.age << endl;
    cout << "City: " << person1.city << endl;
    cout << "Country: " << person1.country << endl;
    cout << "Monthly Salary: " << person1.monthlySalary << endl;
    cout << "Yearly Salary: " << person1.monthlySalary * 12 << endl;
    cout << "Gender: " << person1.gender << endl;
    cout << "Is married? " << person1.isMarried << endl;
    cout << "***********************" << endl;

}

int main()
{
    Homework();
    return 0;
}