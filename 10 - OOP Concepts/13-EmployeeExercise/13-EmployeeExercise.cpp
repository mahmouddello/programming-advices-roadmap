#include <iostream>

using namespace std;

class clsEmployee
{
private:
	int _id;
	string _firstName;
	string _lastName;
	string _email;
	string _phoneNumber;
	string _title;
	string _department;
	double _salary;

public:

	clsEmployee(int id, string firstName, string lastName, string email, string phoneNumber, string title, string department, double salary)
	{
		_id = id;
		_firstName = firstName;
		_lastName = lastName;
		_email = email;
		_phoneNumber = phoneNumber;
		_title = title;
		_department = department;
		_salary = salary;
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

	string getFullName()
	{
		return _firstName + " " + _lastName;
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

	string getTitle()
	{
		return _title;
	}

	void setTitle(const string& title)
	{
		_title = title;
	}

	string getDepartment()
	{
		return _department;
	}

	void setDepartment(const string& department)
	{
		_department = department;
	}

	double getSalary()
	{
		return _salary;
	}

	void setSalary(const double& salary)
	{
		_salary = salary;
	}

	void print()
	{
		cout << "\nInfo:";
		cout << "\n--------------------------------";
		cout << "\nID: " << _id;
		cout << "\nFirst Name: " << _firstName;
		cout << "\nLast Name: " << _lastName;
		cout << "\nFull Name: " << getFullName();
		cout << "\nTitle: " << _title;
		cout << "\nDepartment: " << _department;
		cout << "\nEmail: " << _email;
		cout << "\nPhone Number: " << _phoneNumber;
		cout << "\nSalary: " << _salary;
		cout << "\n--------------------------------" << endl;
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

int main()
{
	clsEmployee employee(10, "Mahmoud", "Dello", "mail@me.com", "+1 123-456-789", "Software Engineer", "Software Development", 28000.0);
	employee.print();

	employee.sendEmail("Hi", "How are you?");
	employee.sendSMS("How are you?");
}