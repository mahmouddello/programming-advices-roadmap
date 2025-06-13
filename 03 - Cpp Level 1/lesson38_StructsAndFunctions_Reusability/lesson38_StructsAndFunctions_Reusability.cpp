#include <iostream>
#include <string>

using namespace std;

struct stPersonInfo {

	string name;
	string surname;
	short age;
	string phoneNumber;

};

// notice: pass by reference 
void ReadInfo(stPersonInfo& personInfo)
{
	cout << "Enter first name: ";
	cin >> personInfo.name;

	cout << "Enter last name: ";
	cin >> personInfo.surname;

	cout << "Enter age: ";
	cin >> personInfo.age;

	cout << "Enter phone number: ";
	cin >> personInfo.phoneNumber;

}

void PrintInfo(stPersonInfo personInfo)
{

	cout << "*******************" << endl;

	cout << "First Name: " << personInfo.name << endl;
	cout << "Last Name: " << personInfo.surname << endl;
	cout << "Age: " << personInfo.age << endl;
	cout << "Phone Number: " << personInfo.phoneNumber << endl;

	cout << "*******************\n" << endl;

}

// ------------- HOMEWORK -------------

struct strPerson
{

	string name, city, country;
	short age;
	unsigned int monthlySalary;
	char gender;
	bool isMarried;

};

void readPersonInfo(strPerson& person)
{

	cout << "Enter name: ";
	getline(cin, person.name);

	cout << "Enter city: ";
	cin.ignore(1, '\n');
	cin >> person.city;

	cout << "Enter country: ";
	cin >> person.country;

	cout << "Enter monthly salary: ";
	cin >> person.monthlySalary;

	cout << "Enter gender ('M', 'F'): ";
	cin >> person.gender;

	cout << "Enter Martial Status ('1', '0'): ";
	cin >> person.isMarried;

}

// Function to display the information card
void displayInfoCard(const strPerson& person) {
	cout << "Information Card:" << endl;
	cout << "Name: " << person.name << endl;
	cout << "City: " << person.city << endl;
	cout << "Country: " << person.country << endl;
	cout << "Monthly Salary: " << person.monthlySalary << endl;
	cout << "Gender: " << person.gender << endl;
	cout << "Marital Status: " << (person.isMarried ? "Married" : "Single") << endl;
}

int main()
{
	// instead of too many variables, very clean code.

	stPersonInfo personInfo1;
	ReadInfo(personInfo1);
	PrintInfo(personInfo1);

	// let's create another person, easy!

	stPersonInfo personInfo2;
	ReadInfo(personInfo2);
	PrintInfo(personInfo2);


	// Homework 
	strPerson person1;
	readPersonInfo(person1);
	displayInfoCard(person1);

}