#include <iostream>

using namespace std;

class clsA
{
private:
	// Private: Accessible only within this class. Cannot be accessed from derived classes or external code.
	int _var1 = 10;
	void _func1()
	{
		// code
	}

protected:
	// Protected: Accessible within this class and derived classes. Cannot be accessed from external code.
	int var2 = 20;
	void func2()
	{
		cout << "Hi from protected func2 in clsA" << endl;
	}

public:
	// Public: Accessible from anywhere, including within this class, derived classes, and external code.
	int var3 = 30;
	void func3()
	{
		cout << "Hi from public func3 in clsA!" << endl;
	}
};

class clsB : public clsA
{
public:
	void func1()
	{
		// Accessing protected derived members with scope resultion `::`
		cout << "Func1 in clsB! ";
		clsA::func2();
		cout << clsA::var2 << endl;
	}
};

int main()
{
	// object `a` has access to only public class members (var3, func3)
	clsA a;
	a.func3();
	cout << a.var3 << endl;

	// object `b` has access to `clsA` public members (var3, func3) and it's own (func1).
	clsB b;
	b.func1();
	b.func3(); // derived
	cout << b.var3 << endl; // derived
}