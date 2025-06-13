#include <iostream>

using namespace std;

class clsPerson
{
private:
	int _id;
	string _firstName;
	string _lastName;
	string _email;
	string _phoneNumber;

public:
	clsPerson(int id, string firstName, string lastName, string email, string phoneNumber)
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

	string getFirstName()
	{
		return _firstName;
	}

	void setFirstName(const string& firstName)
	{
		_firstName = firstName;
	}

	string getLastName()
	{
		return _lastName;
	}

	void setLastName(const string& lastName)
	{
		_lastName = lastName;
	}

	string getEmail()
	{
		return _email;
	}

	void setEmail(const string& email)
	{
		_email = email;
	}

	string getPhoneNumber()
	{
		return _phoneNumber;
	}

	void setPhoneNumber(const string& phoneNumber)
	{
		_phoneNumber = phoneNumber;
	}

	string getFullName()
	{
		return _firstName + " " + _lastName;
	}

	void print()
	{
		cout << "Info:" << endl;
		cout << "--------------------------------" << endl;
		cout << "ID: " << getId() << endl;
		cout << "First Name: " << _firstName << endl;
		cout << "Last Name: " << _lastName << endl;
		cout << "Full Name: " << getFullName() << endl;
		cout << "Email: " << _email << endl;
		cout << "Phone Number: " << _phoneNumber << endl;
		cout << "--------------------------------\n" << endl;
	}

	void sendEmail(const string& subject, const string& body)
	{
		cout << "The following message sent successfully to email: " << _email << endl;
		cout << "Subject: " << subject << endl;
		cout << "Body: " << body << endl;

		cout << endl;
	}

	void sendSMS(const string& message)
	{
		cout << "SMS has been sent successfully to phone: " << _phoneNumber << endl;
		cout << "Message: " << message << endl;

		cout << endl;
	}
};

// clsEmployee inherits everything from clsPerson
class clsEmployee : public clsPerson
{
private:
	string _title;
	string _department;
	float _salary;
public:
	clsEmployee(
		int id,
		string firstName,
		string lastName,
		string email,
		string phoneNumber,
		string title,
		string department,
		float salary
	) : clsPerson(id, firstName, lastName, email, phoneNumber)
	{
		_title = title;
		_department = department;
		_salary = salary;
	}

	//Property Set
	void setTitle(string title)
	{
		_title = title;
	}
	//Property Get
	string getTitle()
	{
		return _title;
	}
	//Property Set
	void setDepartment(string department)
	{
		_department = department;
	}
	//Property Get
	string getDepartment()
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
		cout << "Info:" << endl;
		cout << "--------------------------------" << endl;
		cout << "ID: " << getId() << endl;
		cout << "First Name: " << getFirstName() << endl;
		cout << "Last Name: " << getLastName() << endl;
		cout << "Full Name: " << getFullName() << endl;
		cout << "Email: " << getEmail() << endl;
		cout << "Phone Number: " << getPhoneNumber() << endl;
		cout << "Title: " << _title << endl;
		cout << "Deparment: " << _department << endl;
		cout << "Salary: " << _salary << endl;
		cout << "--------------------------------\n" << endl;
	}
};

int main()
{
	clsEmployee employee
	(
		10,
		"Mahmoud",
		"Dello",
		"me@gmail.com",
		"+1 123-456-789",
		"Software Engineer",
		"Software Development",
		15000
	);
	employee.print();

	return 0;
}