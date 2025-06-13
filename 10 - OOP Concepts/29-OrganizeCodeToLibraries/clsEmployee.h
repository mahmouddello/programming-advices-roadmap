#pragma once
#include <iostream>
#include "clsPerson.h"

// clsEmployee inherits everything from clsPerson
class clsEmployee : public clsPerson
{
private:
	std::string _title;
	std::string _department;
	float _salary;
public:
	clsEmployee(
		int id,
		std::string firstName,
		std::string lastName,
		std::string email,
		std::string phoneNumber,
		std::string title,
		std::string department,
		float salary
	) : clsPerson(id, firstName, lastName, email, phoneNumber)
	{
		_title = title;
		_department = department;
		_salary = salary;
	}

	//Property Set
	void setTitle(std::string title)
	{
		_title = title;
	}
	//Property Get
	std::string getTitle()
	{
		return _title;
	}
	//Property Set
	void setDepartment(std::string department)
	{
		_department = department;
	}
	//Property Get
	std::string getDepartment()
	{
		return _department;
	}
	//Property Set
	void setSalary(float salary)
	{
		_salary = salary;
	}
	//Property Get
	float getSalary()
	{
		return _salary;
	}

	// overrides clsPerson::print() function.
	void print()
	{
		std::cout << "Info:" << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << "ID: " << getId() << std::endl;
		std::cout << "First Name: " << getFirstName() << std::endl;
		std::cout << "Last Name: " << getLastName() << std::endl;
		std::cout << "Full Name: " << getFullName() << std::endl;
		std::cout << "Email: " << getEmail() << std::endl;
		std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
		std::cout << "Title: " << _title << std::endl;
		std::cout << "Deparment: " << _department << std::endl;
		std::cout << "Salary: " << _salary << std::endl;
		std::cout << "--------------------------------\n" << std::endl;
	}
};