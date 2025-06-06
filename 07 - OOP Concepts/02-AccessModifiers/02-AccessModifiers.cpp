#include <iostream>

using namespace std;

class clsPerson
{
private:
	// only accessible inside the class.
	int variable1 = 5;
	
	int func1()
	{
		return 40;
	}

protected:
	// only accessible inside the class, and the classes that inherits this class 
	int variable2 = 100;

	int func2()
	{
		return 50;	
	}

public:
	// accessible from everywhere inside and outside the class.
	string firstName;
	string lastName;

	string getFullName()
	{
		return firstName + " " + lastName;
	}

	float func3()
	{
		return func1() * variable1 * variable2;
	}
};

int main()
{
	clsPerson person;

	// We can only access firstName, lastName, getFullName(), func3() because their access modifier is public
	person.firstName = "Mahmoud";
	person.lastName = "Dello";

	// person.func1() -> error, can't access it because it's private (only internal use).
	// person.func2() -> error, can't access it because it's protected (internal and classes that inherits clsPerson use).
	
	cout << person.getFullName() << endl;

	// Another example from `string` class, we can only access the `public` methods from outside of string class.
	string s1 = "HelloWorld";
	cout << s1.length() << endl;

	return 0;
}
	