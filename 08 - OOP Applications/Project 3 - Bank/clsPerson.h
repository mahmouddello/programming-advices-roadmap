#pragma once
#include <iostream>

using std::string;
using std::cout; 
using std::endl;

class clsPerson
{
private:
	string _firstName;
	string _lastName;
	string _email;
	string _phoneNumber;
public:
	clsPerson(string firstName, string lastName, string email, string phoneNumber)
	{
		_firstName = firstName;
		_lastName = lastName;
		_email = email;
		_phoneNumber = phoneNumber;
	}

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

	__declspec(property(get = getFirstName, put = setFirstName)) string firstName;

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

	__declspec(property(get = getLastName, put = setLastName)) string lastName;

	// property set
	void setEmail(string email)
	{
		_email = email;
	}

	// property get
	string getEmail()
	{
		return _email;
	}

	__declspec(property(get = getEmail, put = setEmail)) string email;


	// property set
	void setPhoneNumber(string phoneNumber)
	{
		_phoneNumber = phoneNumber;
	}

	// property get
	string getPhoneNumber()
	{
		return _phoneNumber;
	}

	string getFullName()
	{
		return _firstName + " " + _lastName;
	}

	__declspec(property(get = getPhoneNumber, put = setPhoneNumber)) string phoneNumber;


	void print()
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nFirstName: " << _firstName;
		cout << "\nLastName : " << _lastName;
		cout << "\nFull Name: " << getFullName();
		cout << "\nEmail    : " << _email;
		cout << "\nPhone    : " << _phoneNumber;
		cout << "\n___________________\n";

	}
};

