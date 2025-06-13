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

	clsA()
	{
		__var1 = 10;
		_var2 = 20;
		var3 = 30;
	}

	// mySum can access all of clsA's private, protected, and public members within scope.
	friend int mySum(clsA);
};

int mySum(clsA a)
{
	return a.__var1 + a._var2 + a.var3;
}

//int func2(clsA a)
//{
//	return a.__var1 + a._var2 + a.var3;
//}

int main()
{
	clsA a;
	cout << mySum(a) << endl;

	return 0;
}