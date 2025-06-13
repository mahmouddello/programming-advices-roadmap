#include <iostream>

using namespace std;

class clsA
{
public:
	int x = 0;

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
	// Initializing 3 array Objects with function calls of parameterized constructor as elements of that array
	clsA objArr[] = { clsA(10), clsA(20), clsA(30) };

	for (short i = 0; i < 3; i++)
	{
		objArr[i].print();
	}

	return 0;
}