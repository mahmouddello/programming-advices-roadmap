#include <iostream>
using namespace std;

class clsPerson
{
public:
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

	// Static/Early Binding
	employee.Print(); // The compiler knows which print() to call during compile time.
	student.Print();

	// upcasting
	clsPerson* person1 = &employee;
	clsPerson* person2 = &student;

	// Dynamic/Late Binding
	person1->Print(); // which `print()` to call? doesn't know employee or student address
	person2->Print(); // during runtime, connected print through virtual table "late"

	return 0;
}
