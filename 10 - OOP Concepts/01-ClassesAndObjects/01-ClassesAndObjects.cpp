#include <iostream>

using namespace std;

/*
    Struct is a data type used to group multiple variables together under one name.
    With structs, we don't need to declare the same variables repeatedly when creating new instances (e.g., students).
    However, structs have some limitations. For example, we can't use them to encapsulate behavior (functions) in the same way as classes.
    While it's possible to add functions to a struct, doing so may lead to confusion — this will become clearer as we progress through the course.
*/
struct stStudent
{
    string firstName;
    string lastName;
};

/*
    Class:
    A class is similar to a struct but also allows us to define functions (called methods).
    You can think of a class as a blueprint for creating objects.
    In addition to storing data, a class can define behavior.
*/
class clsStudent
{
    // By default, all members of a class are private if no access modifier is specified.
    // This means they cannot be accessed directly from outside the class.
    // The 'public' keyword is used to expose certain members so they can be accessed through an object.

public:
    string firstName;
    string lastName;

    string getFullName()
    {
        return firstName + " " + lastName;
    }

private:
    // If we don't explicitly declare this as 'private', it would still be private by default.
    int x;
};

int main()
{
    stStudent student1;
    student1.firstName = "Mahmoud";
    student1.lastName = "Dello";

    // Just like with structs, we need to create an object to access a class’s properties.

    clsStudent student2; // Creating an object of clsStudent
    student2.firstName = "Omar";
    student2.lastName = "Dello";

    cout << student2.getFullName() << endl;

    // Another example of a class and object:
    string s1 = "Programming"; // 'string' is a class, and 's1' is an object of that class.
    s1.pop_back(); // 'pop_back' is a method defined in the string class.

    return 0;
}
