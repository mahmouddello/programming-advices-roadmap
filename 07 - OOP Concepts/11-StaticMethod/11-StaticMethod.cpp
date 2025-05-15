#include <iostream>

using namespace std;

class clsA
{
public:
	static int function1()
	{
		return 10;
	}

	int function2()
	{
		return 20;
	}
};

class MyClass {
	int nonStaticVar = 10;
	static int staticVar;

public:
	static void staticMethod() {
		//nonStaticVar = 5; // Error: cannot access non-static member
		staticVar = 20;      // OK: static member accessed
	}

	void instanceMethod() {
		nonStaticVar = 5;    // OK
		staticVar = 10;      // OK
	}
};

int main()
{

	cout << clsA::function1() << endl; // static method, we can call it without object.
	// cout << clsA::function2() << endl; error -> a nonstatic member reference must be relative to a specific object.

	clsA a1, a2;
	cout << a1.function1() << endl; // calling static method using object, it's not necessary or recommended.
	cout << a1.function2() << endl; // accessing a nonstatic member using object only.

	cout << a2.function1() << endl;
	cout << a2.function2() << endl;

	return 0;
}