#include <iostream>

using namespace std;

struct strInfo
{
	string firstName;
	string lastName;
	short age;
	string phoneNumber;
};

// --------- HOMEWORK ---------

void readPersonInfo(strInfo& person)
{

	cout << "Enter first name: ";
	cin >> person.firstName;

	cout << "Enter last name: ";
	cin >> person.lastName;

	cout << "Enter age: ";
	cin >> person.age;

	cout << "Enter phone number: ";
	cin >> person.phoneNumber;

	cout << "-----------------------------" << endl;

}

void writePersonInfo(const strInfo& person)
{

	cout << "*******************************" << endl;
	cout << "First Name: " << person.firstName << endl;
	cout << "Last Name: " << person.lastName << endl;
	cout << "Age: " << person.age << endl;
	cout << "Phone Number: " << person.phoneNumber << endl;
	cout << "*******************************" << endl;

}

void readAllPersons(strInfo persons[2])
{
	readPersonInfo(persons[0]);
	readPersonInfo(persons[1]);
}

void writeAllPersons(strInfo persons[2])
{
	writePersonInfo(persons[0]);
	writePersonInfo(persons[1]);
}

int main()
{
	strInfo persons[2];

	readAllPersons(persons);
	writeAllPersons(persons);

	return 0;
}