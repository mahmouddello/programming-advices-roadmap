#include <iostream>

using namespace std;

class clsPerson
{
	class clsAddress
	{
	public:
		string addressLine1;
		string addressLine2;
		string city;
		string country;

		void print()
		{
			cout << "Address:\n";
			cout << addressLine1 << "\n";
			cout << addressLine2 << "\n";
			cout << city << "\n";
			cout << country << endl;
		}
	};
public:
	string fullName;
	clsAddress address;

	clsPerson()
	{
		fullName = "Mahmoud Dello";
		address.addressLine1 = "Building 15";
		address.addressLine2 = "King Saud Highway";
		address.city = "Riyad";
		address.country = "Saudia Arabia";
	}

};

int main()
{
	clsPerson person;
	person.address.print();

	return 0;
}