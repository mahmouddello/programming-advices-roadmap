#include <iostream>

using namespace std;

class clsPerson
{
public:
	string fullName = "Mahmoud Dello";
};

class clsEmployee : public clsPerson
{
public:
	string title = "Software Engineer";
};

int main()
{
	clsEmployee employee;
	cout << employee.fullName << endl;

	// (Up Casting)
	clsPerson* person = &employee; // person object points to employee's address.
	cout << person->fullName << endl;
	// cout << person->title << endl; error -> title doesn't exist in person class even if it's pointing to employee

	clsPerson person2;
	cout << person2.fullName << endl; // OK

	// clsEmployee* employee2 = &person2; // error -> person is smaller from employee in terms of class members.

	/*
		Simple Rule
		Base* base = &derived -> OK, small can point to the bigger
		Derived* derived = &base -> NOT OK, bigger can't point to the small
	*/

	return 0;
}