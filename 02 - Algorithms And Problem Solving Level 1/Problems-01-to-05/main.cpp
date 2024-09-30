#include <iostream>
#include <string>

using namespace std;

/*
	Problem solving are in order, from 1 to 5.
	A solution might use more than a function or a procedure.
*/

// ----------- Problem 1 - Print Your Name -----------

void PrintName(string name)
{
    cout << "Hello there, " << name << "!" << endl;
}

// ----------- Problem 2 - Read Name and Print on Screen (Used both functions) -----------

string ReadName()
{
	string name;

	cout << "Please enter your name: ";
	getline(cin, name);

	return name;

}

// ----------- Problem 3 - Number Odd or Even -----------

enum enNumberType {Odd = 1, Even = 2};

int ReadNumber()
{
	int number;

	cout << "Please enter an integer number: ";
	cin >> number;

	return number;

}

enNumberType CheckNumberType(int number)
{
	// we can use return statements without else, becuase the return exists the function anyway.

	cout << "The number your entered: " << number << endl;

	if (number % 2 == 0)
		return enNumberType::Even;
	
	return enNumberType::Odd;
}

void OddOrEven(enNumberType numberType)
{
	if (numberType == enNumberType::Even)
		cout << "It's an Even Number" << endl;
	else
		cout << "It's an Odd Number" << endl;
}

// ----------- Problem 4 - Hire a driver Case #1 -----------

// 4.1) My Solution
enum enDriverLicenseState  {hasNoLicense = 0, hasLicense = 1};

short ReadAge()
{
	short age;

	cout << "Please enter your age: ";
	cin >> age;

	return age;

}

enDriverLicenseState ReadDriverLicesne()
{

	bool hasDriverLicense;

	cout << "Enter driver license state by typing: (true / false) or (1 / 0): ";
	cin >> hasDriverLicense;

	return (enDriverLicenseState)hasDriverLicense;

}

void hiringDecision(short age, enDriverLicenseState driverLicenseState)
{
	if (age > 21 && driverLicenseState == enDriverLicenseState::hasLicense)
		cout << "HIRED" << endl;

	else
		cout << "REJECTED" << endl;
}

// 4.2) Programming Advices Solution

struct stInfo
{
	short age;
	bool hasDriverLicense;
};

stInfo ReadInfo()
{
	stInfo personInfo;

	cout << "Enter your age: ";
	cin >> personInfo.age;

	cout << "Do you have a driver license? (0 or 1): ";
	cin >> personInfo.hasDriverLicense;

	return personInfo;

}

bool isAccepeted(stInfo info)
{
	return (info.age > 21 && info.hasDriverLicense);
}

void PrintResult(stInfo info)
{
	if (isAccepeted(info))
		cout << "HIRED" << endl;

	else
		cout << "REJECTED" << endl;
}

// ----------- Problem #5 - Hire a Driver (Case 2) -----------

/*
	modification on this case will be, by adding a boolean variable to the struct
	and modifying the condition in isAccepted function.
*/ 

struct stInfo2
{
	short age;
	bool hasDriverLicense;
	bool hasRecommendation;
};

stInfo2 ReadInfo2()
{
	stInfo2 personInfo;

	cout << "Enter your age: ";
	cin >> personInfo.age;

	cout << "Do you have a driver license? (0 or 1): ";
	cin >> personInfo.hasDriverLicense;

	cout << "Does this person has a recommendation? (0 or 1): ";
	cin >> personInfo.hasRecommendation;

	return personInfo;

}

bool isAccepted2(stInfo2 info)
{
	if (info.hasRecommendation)
		return true;

	return (info.age > 21 && info.hasDriverLicense);
}

void PrintResult2(stInfo2 info)
{
	if (isAccepted2(info))
		cout << "HIRED" << endl;

	else
		cout << "REJECTED" << endl;
}

int main()
{
	PrintResult2(ReadInfo2());
    return 0;
}
