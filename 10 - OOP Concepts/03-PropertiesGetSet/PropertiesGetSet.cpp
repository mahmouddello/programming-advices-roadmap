#include <iostream>

using namespace std;

class clsPerson
{
	// We shouldn't have public variables in class, always use getters and setters
private:
	string _firstName;
	string _lastName;

public:

	// property set
	void setFirstName(string firstName)
	{
		_firstName = firstName;
	}

	// property get
	string getFirstName()
	{
		return _firstName;
	}

	// property set
	void setLastName(string lastName)
	{
		_lastName = lastName;
	}

	// property get
	string getLastName()
	{
		return _lastName;
	}

	string getFullName()
	{
		return getFirstName() + " " + getLastName();
	}

};

int main()
{
	clsPerson person;

	// cout << person.firstName << endl; -> error, we can't directly get a private variable, use property get.
	// person.firstName = "Ali"; -> error, we can't directly edit a private variable, use property set.

	person.setFirstName("Ali");
	person.setLastName("Hamada");

	cout << person.getFullName() << endl;

	return 0;
}