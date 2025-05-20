#pragma once
#include <iostream>

class clsPerson
{
private:
	int _id;
	std::string _firstName;
	std::string _lastName;
	std::string _email;
	std::string _phoneNumber;

public:
	clsPerson(int id, std::string firstName, std::string lastName, std::string email, std::string phoneNumber)
	{
		_id = id;
		_firstName = firstName;
		_lastName = lastName;
		_email = email;
		_phoneNumber = phoneNumber;
	}

	// Read-Only Property
	int getId()
	{
		return _id;
	}

	std::string getFirstName()
	{
		return _firstName;
	}

	void setFirstName(const std::string& firstName)
	{
		_firstName = firstName;
	}

	std::string getLastName()
	{
		return _lastName;
	}

	void setLastName(const std::string& lastName)
	{
		_lastName = lastName;
	}

	std::string getEmail()
	{
		return _email;
	}

	void setEmail(const std::string& email)
	{
		_email = email;
	}

	std::string getPhoneNumber()
	{
		return _phoneNumber;
	}

	void setPhoneNumber(const std::string& phoneNumber)
	{
		_phoneNumber = phoneNumber;
	}

	std::string getFullName()
	{
		return _firstName + " " + _lastName;
	}

	void print()
	{
		std::cout << "Info:" << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << "ID: " << getId() << std::endl;
		std::cout << "First Name: " << _firstName << std::endl;
		std::cout << "Last Name: " << _lastName << std::endl;
		std::cout << "Full Name: " << getFullName() << std::endl;
		std::cout << "Email: " << _email << std::endl;
		std::cout << "Phone Number: " << _phoneNumber << std::endl;
		std::cout << "--------------------------------\n" << std::endl;
	}

	void sendEmail(const std::string& subject, const std::string& body)
	{
		std::cout << "The following message sent successfully to email: " << _email << std::endl;
		std::cout << "Subject: " << subject << std::endl;
		std::cout << "Body: " << body << std::endl;
		std::cout << std::endl;
	}

	void sendSMS(const std::string& message)
	{
		std::cout << "SMS has been sent successfully to phone: " << _phoneNumber << std::endl;
		std::cout << "Message: " << message << std::endl;

		std::cout << std::endl;
	}
};