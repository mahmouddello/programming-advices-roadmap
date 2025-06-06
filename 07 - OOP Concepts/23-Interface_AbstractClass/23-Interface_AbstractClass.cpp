#include <iostream>
using namespace std;

//Abstract Class / Interface / Contract.
class clsMobile
{
	// Pure Virtual Functions
	virtual void Dial(string PhoneNumber) = 0;
	virtual void SendSMS(string PhoneNumber, string Text) = 0;
	virtual void TakePicture() = 0;
};
class clsiPhone : public clsMobile
{
	//This class signed a contract with clsMobile abstract class therefore,
	// it should implement everything in the abstract class.
public:
	void Dial(string PhoneNumber)
	{
	}

	void SendSMS(string PhoneNumber, string Text)
	{
	}

	void TakePicture()
	{
	}

	// Derived class can have additional methods
	void MyOwnMethod()
	{
	}
};

class clsSamsungNote10 : public clsMobile
{
	// This class signed a contract with clsMobile abstract class
	// therefore it should implement everything in the abstract class
public:
	void Dial(string PhoneNumber)
	{
	};
	void SendSMS(string PhoneNumber, string Text)
	{
	};
	void TakePicture()
	{
	};
};

int main()
{
	// clsMobile mobile; error -> Can't create object from abstract class. Becuase it doesn't has implementation.

	clsiPhone iPhone;
}