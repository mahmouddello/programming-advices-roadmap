#include <iostream>

using namespace std;

class clsA
{
public:
	int var = 0;
	static int counter; // static member only declared in class.

	clsA()
	{
		counter++; // increase counter when new object is created.
	}

	void print()
	{
		cout << "Var = " << var << endl;
		cout << "Counter = " << counter << endl;
		cout << endl;
	}
};

int clsA::counter = 0; // static variable initialisation outside the class.

int main()
{
	clsA a1, a2, a3;

	a1.var = 10;
	a2.var = 20;
	a3.var = 30;

	a1.print();
	a2.print();
	a3.print();

	a1.counter = 500;
	cout << "After changing counter value:\n" << endl;

	a1.print();
	a2.print();
	a3.print();

	clsA a4;
	a4.var = 40;
	cout << "After creating new object:\n" << endl;

	a1.print();
	a2.print();
	a3.print();
	a4.print();

	return 0;
}
