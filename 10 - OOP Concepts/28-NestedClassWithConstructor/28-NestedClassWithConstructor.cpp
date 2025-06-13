#include <iostream>

using namespace std;

class clsPerson
{
	class clsAddress
	{
	private:
		string _addressLine1;
		string _addressLine2;
		string _city;
		string _country;
	public:
		clsAddress(string addressLine1, string addressLine2, string city, string country)
			: _addressLine1(addressLine1), _addressLine2(addressLine2), _city(city), _country(country) {
		}

		void print()
		{
			cout << "Address:\n";
			cout << _addressLine1 << "\n";
			cout << _addressLine2 << "\n";
			cout << _city << "\n";
			cout << _country << endl;
		}			
	};
public:
	string fullName;
	clsAddress address;

	clsPerson(string name, string addressLine1, string addressLine2, string city, string country)
	: address(addressLine1, addressLine2, city, country) {
		fullName = name;
	}
};

int main()
{
	clsPerson person(
		"Mahmoud Dello",
		"Building 15",
		"King Saud Highway",
		"Riyad",
		"Saudia Arabia"
	);

	person.address.print();

	return 0;
}