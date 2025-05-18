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

	clsPerson()
	{

	}

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
	// Adding new properties after inheritance.
	string _title;
	string _department;
	float _salary;
public:
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
};

int main()
{
	clsEmployee employee;

	// As we can see employee now has the same class members as `clsPerson`
	employee.setFirstName("Mahmoud");
	employee.setLastName("Dello");
	employee.setEmail("me@gmail.com");
	employee.setSalary(50000);

	// original `print()` doesn't meet our needs in this class, we need to override it later.
	employee.print();
	employee.sendEmail("Hi", "How Are You?");

	return 0;
}