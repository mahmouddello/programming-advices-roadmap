#include <iostream>
using namespace std;

class clsPerson
{
public:
	/*
	The `virtual` keyword tells the compiler to use dynamic (runtime) dispatch for this function.
	It creates a virtual table (vtable) to store function addresses, allowing the correct
	overridden method to be called through a base class pointer or reference.
	*/
	virtual void Print()
	{
		cout << "Hi, I'm a person!\n";
	}
};

class clsEmployee : public clsPerson
{
public:
	void Print()
	{
		cout << "Hi, I'm an employee\n";
	}
};

class clsStudent : public clsPerson
{
public:
	void Print()
	{
		cout << "Hi, I'm a student\n";
	}
};

int main()
{
	clsEmployee employee;
	clsStudent student;

	employee.Print();
	student.Print();

	// upcasting
	clsPerson* person1 = &employee;
	clsPerson* person2 = &student;

	// without `virtual` keyword in Base Class, the compiler will get confused which `print()` to call.
	person1->Print();
	person2->Print();

	return 0;
}
