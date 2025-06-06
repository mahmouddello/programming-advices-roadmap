#include <iostream>

using namespace std;

class clsPerson
{
private:
	int _id = 10;
	string _firstName;
	string _lastName;

public:

	// property get
	int getId()
	{
		return _id;
	}

	// _id is read only property becuase it doesn't have set function.

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