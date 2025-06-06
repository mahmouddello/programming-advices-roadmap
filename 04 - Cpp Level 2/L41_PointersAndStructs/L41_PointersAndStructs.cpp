#include <iostream>

using namespace std;

struct stEmployee
{
	string name;
	float salary;
};

int main() {

	stEmployee tempEmployee, * ptr; // pointer from stEmployee type

	tempEmployee.name = "Mahmoud Dello";
	tempEmployee.salary = 19000;

	cout << tempEmployee.name << endl;
	cout << tempEmployee.salary << endl;

	ptr = &tempEmployee; // address of tempEmployee stored inside the pointer

	cout << "\n------------------------\n";
	cout << ptr->name << endl;
	cout << ptr->salary << endl;

	cout << "\n------------------------\n";
	cout << "Test other operations \n" << endl;

	// ptr->Name is equivalent to *(ptr).name but not works in syntax

	cout << "The address of the struct through &tempEmployee = " << &tempEmployee << endl;
	cout << "The address of the struct through ptr = " << ptr << endl;

	cout << "Address of variable name from the structs = " << &tempEmployee.name << endl;
	cout << "Address of variable name from the pointer = " << &ptr->name << endl;

	return 0;
}