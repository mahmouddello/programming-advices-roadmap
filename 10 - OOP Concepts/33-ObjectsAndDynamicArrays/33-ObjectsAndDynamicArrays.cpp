#include <iostream>

using namespace std;

class clsA
{
public:
	int x = 0;

	// dummy constructor
	clsA() {}

	// parametrized constructor
	clsA(int x)
	{
		this->x = x;
	}

	void print()
	{
		cout << "Value of x = " << this->x << endl;
	}
};

int main()
{
	short numberOfObjects = 5;

	// allocationg dynamic memory on heap of size `numberOfObjects`.
	clsA* arrA = new clsA[numberOfObjects];

	for (short i = 0; i < numberOfObjects; i++)
	{
		arrA[i] = clsA(i);
	}

	for (short i = 0; i < numberOfObjects; i++)
	{
		arrA[i].print();
	}

	// deallocation
	delete[] arrA;

	return 0;
}