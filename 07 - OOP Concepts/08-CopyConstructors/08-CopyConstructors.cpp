#include <iostream>

using namespace std;

class clsAddress
{
private:
	string _AddressLine1;
	string _AddressLine2;
	string _POBox;
	string _ZipCode;

public:

	// parametrized constructor overrides default constructor.
	clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode)
	{
		_AddressLine1 = AddressLine1;
		_AddressLine2 = AddressLine2;
		_POBox = POBox;
		_ZipCode = ZipCode;
	}

	// deep copy constructor: it's created automatically by the compiler even if we don't write it.
	clsAddress(const clsAddress& old_obj)
	{
		_AddressLine1 = old_obj.AddressLine1();
		_AddressLine2 = old_obj.AddressLine2();
		_POBox = old_obj.POBox();
		_ZipCode = old_obj.ZipCode();
	}

	void SetAddressLine1(string AddressLine1)
	{
		_AddressLine1 = AddressLine1;
	}

	string AddressLine1() const
	{
		return _AddressLine1;
	}

	void SetAddressLine2(string AddressLine2)
	{
		_AddressLine2 = AddressLine2;
	}

	string AddressLine2() const
	{
		return _AddressLine2;
	}

	void SetPOBox(string POBox)
	{
		_POBox = POBox;
	}

	string POBox() const
	{
		return _POBox;
	}

	void SetZipCode(string ZipCode)
	{
		_ZipCode = ZipCode;
	}

	string ZipCode() const
	{
		return _ZipCode;
	}

	void Print()
	{
		cout << "\nAddress Details:\n";
		cout << "------------------------";
		cout << "\nAddressLine1: " << _AddressLine1 << endl;
		cout << "AddressLine2: " << _AddressLine2 << endl;
		cout << "POBox : " << _POBox << endl;
		cout << "ZipCode : " << _ZipCode << endl;
	}

};

int main()
{
	clsAddress address1(
		"Riyad New City",
		"King Saud Street",
		"312567",
		"312367"
	);
	address1.Print();

	clsAddress address2 = address1; // copy constructor working under the hood.
	address2.Print();

	return 0;
}
