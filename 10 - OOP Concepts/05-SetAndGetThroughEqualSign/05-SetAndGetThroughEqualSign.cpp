#include <iostream>

using namespace std;

class clsPerson
{
private:
	string _firstName;
	string _lastName;

public:

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

	// Think of this line like alias, if it has `cout` it maps to getFirstName() method [get]
	// If '=' is mentioned it maps put to setFirstName method [set]
	// put is equivalent to set
	__declspec(property(get = getFirstName, put = setFirstName)) string firstName;
	__declspec(property(get = getLastName, put = setLastName)) string lastName;

};

int main()
{
	clsPerson person;

	person.setFirstName("Ali");
	person.setLastName("Hamada");

	cout << person.getFullName() << endl;

	// instead of above we only write this
	person.firstName = "Mahmoud";
	person.lastName = "Dello";

	cout << person.firstName << " " << person.lastName << endl;

	return 0;
}