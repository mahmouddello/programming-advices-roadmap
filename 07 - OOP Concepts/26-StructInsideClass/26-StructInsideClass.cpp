#include <iostream>

using namespace std;

class clsPerson
{
private:
	// struct is a datatype like int, string, ..etc. We can use it inside class too.
	struct stAddress
	{
		string addressLine1;
		string addressLine2;
		string city;
		string country;
	};
public:
	string fullName;
	stAddress address;

	clsPerson()
	{
		fullName = "Mahmoud Dello";
		address.addressLine1 = "Building 15";
		address.addressLine2 = "King Saud Highway";
		address.city = "Riyad";
		address.country = "Saudia Arabia";
	}

	void printAddress()
	{
		cout << "Address:\n";
		cout << address.addressLine1 << "\n";
		cout << address.addressLine2 << "\n";
		cout << address.city << "\n";
		cout << address.country << endl;
	}
};

int main()
{
	clsPerson person;
	person.printAddress();

	return 0;
}