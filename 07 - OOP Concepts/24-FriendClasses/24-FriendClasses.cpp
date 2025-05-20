#include <iostream>

using namespace std;

class clsA
{
private:
	int __var1;
protected:
	int _var2;
public:
	int var3;

	clsA ()
	{
		__var1 = 10;
		_var2 = 20;
		var3 = 30;
	}

	friend class clsB;
};

class clsB
{
	// clsB is friend with clsA, it can only access clsA's elements from inside.
public:
	// object is a datatype and we can pass an object as param
	void display(clsA a)
	{
		cout << "var1 = " << a.__var1 << endl;
		cout << "var2 = " << a._var2 << endl;
		cout << "var3 = " << a.var3 << endl;
	}
};

int main()
{
	clsA a;
	clsB b;

	b.display(a);

	return 0;
}