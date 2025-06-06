#include <iostream>

using namespace std;

class clsPerson
{
public:
	string fullName;

	// Constructor is called when an object of the class is created
	clsPerson()
	{
		cout << "Constructor Building Object..." << endl;
		fullName = "Mahmoud Dello";
	}

	// Destructor is called automatically when an object goes out of scope or is deleted
	~clsPerson()
	{
		cout << "Destructor Destroying Object..." << endl;
	}
};

void func1()
{
	// Object is created on the stack; destructor will be called automatically when the function ends
	clsPerson person1;
}

void func2()
{
	// Object is created on the heap (dynamic allocation); destructor will NOT be called automatically
	// We must use 'delete' to deallocate memory and invoke the destructor manually
	clsPerson* person2 = new clsPerson;
	delete person2;
}

int main()
{
	func1();  // Will call constructor and destructor automatically
	func2();  // Will call constructor, and we manually call destructor via delete
	system("pause>0");
	return 0;
}
