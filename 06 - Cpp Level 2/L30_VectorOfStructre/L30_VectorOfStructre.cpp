#include <iostream>
#include <vector>

using namespace std;

struct stEmployee {
	string firstName;
	string lastName;
	float salary;
};

void ReadEmployeeData(vector <stEmployee>& vEmployees) {

	stEmployee tempEmployee;
	char readMore = 'Y';

	do {
		cout << "Enter Firstname: ";
		cin >> tempEmployee.firstName;
		
		cout << "Enter Lastname: ";
		cin >> tempEmployee.lastName;

		cout << "Enter Salary: ";
		cin >> tempEmployee.salary;

		vEmployees.push_back(tempEmployee);

		cout << "\nDo you want to add more employees? 'y', 'n'? ";
		cin >> readMore;

	} while (readMore == 'Y' || readMore == 'y');
}

void PrintEmployeesData(vector <stEmployee>& vEmployees)
{
	for (const stEmployee& employee : vEmployees) {
		cout << "First Name: " << employee.firstName << endl;
		cout << "Last Name: " << employee.lastName << endl;
		cout << "Salary: $" << employee.salary << endl;
		cout << endl;
	}
}

int main() {
	
	// vector <T> vectorName;
	vector <stEmployee> vEmployees;

	stEmployee tempEmployee;

	tempEmployee.firstName = "Mahmoud";
	tempEmployee.lastName = "Dello";
	tempEmployee.salary = 50;
	vEmployees.push_back(tempEmployee);	
	
	tempEmployee.firstName = "Mohammed";
	tempEmployee.lastName = "Abu-Hadhoud";
	tempEmployee.salary = 50000;
	vEmployees.push_back(tempEmployee);	
	
	tempEmployee.firstName = "Lucas";
	tempEmployee.lastName = "Quintrell";
	tempEmployee.salary = 100;
	vEmployees.push_back(tempEmployee);

	for (const stEmployee& employee : vEmployees) {
		cout << "First Name: " << employee.firstName << endl;
		cout << "Last Name: " << employee.lastName << endl;
		cout << "Salary: " << employee.salary << endl;
		cout << endl;
	}

	cout << "--------------------\n" << "HOMEWORK\n" << "--------------------\n" << endl;

	vector <stEmployee> vEmployees2;
	ReadEmployeeData(vEmployees2);
	PrintEmployeesData(vEmployees2);

	return 0;
}