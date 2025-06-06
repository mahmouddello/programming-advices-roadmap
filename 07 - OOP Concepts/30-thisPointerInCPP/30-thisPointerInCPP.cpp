#include <iostream>

using namespace std;

class clsEmployee
{
public:
	int id;
	string name;
	float salary;

	clsEmployee(int id, string name, float salary)
	{
		// name conflicting if `this` not used.
		this->id = id;
		this-> name = name;
		this->salary = salary;
	}

	static void func1(clsEmployee employee)
	{
		employee.print();
	}

	void func2()
	{
		func1(*this); // sends the current object to the static func1 method.
	}

	void print()
	{
		// by default, compiler implicitly adds `this->` pointer for each member call.
		cout << id << " " << name << " " << salary << endl;
	}

};

int main()
{
	clsEmployee employee(101, "Mahmoud Dello", 15000.f);
	employee.print();

	employee.func2();

	return 0;
}