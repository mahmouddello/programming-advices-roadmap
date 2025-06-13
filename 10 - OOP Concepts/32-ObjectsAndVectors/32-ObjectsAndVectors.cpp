#include <iostream>
#include <vector>

using namespace std;

class clsA
{
public:
	int x = 0;

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
	vector<clsA> v1;
	short numberOfObjects = 5;

	for (short i = 0; i < numberOfObjects; i++)
	{
		v1.push_back(clsA(i));
	}

	for (short i = 0; i < numberOfObjects; i++)
	{
		v1[i].print();
	}

	return 0;
}