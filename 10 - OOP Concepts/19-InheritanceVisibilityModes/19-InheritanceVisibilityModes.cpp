#include <iostream>

using namespace std;

class clsA
{
private:
	// Private: Accessible only within this class.
	// Not accessible from derived classes or outside the class.
	int _var1 = 10;
	void _func1()
	{
		// Private function: accessible only within clsA
	}

protected:
	// Protected: Accessible within this class and derived classes.
	// Not accessible from outside the class or via objects.
	int var2 = 20;
	void func2()
	{
		// Protected function: accessible within clsA and derived classes
	}

public:
	// Public: Accessible from anywhere where the object is visible.
	int var3 = 30;
	void func3()
	{
		// Public function: accessible from any scope where the object is visible
	}
};

// Public inheritance: 
// - Public members of clsA remain public in clsB
// - Protected members remain protected
// - Private members of clsA remain inaccessible
class clsB : public clsA
{
public:
	void func1()
	{
		// This func1 is specific to clsB (not overriding any base class method since clsA::_func1 is private)
		// Add functionality here
	}
};

// Protected inheritance:
// - Public and protected members of clsA become protected in clsC
// - Private members remain inaccessible
// - clsA's public and protected members cannot be accessed through clsC objects directly
class clsC : protected clsA
{
public:
	void func5()
	{
		// Within this method, clsA's protected and public members are accessible
		// Example:
		var2 = 100;   // OK: var2 is accessible because it's inherited as protected
		clsA::func2();      // OK: func2 is also accessible here
		clsA::func3();      // OK: func3 is also accessible here
	}
};

// Private inheritance:
// - All public and protected members of clsA become private in clsD
// - Private members remain inaccessible
// - clsA's members are not accessible through clsD objects or derived classes of clsD
class clsD : private clsA
{
	// clsA's public and protected members become private here
};

// Class derived from another derived class (clsC)
// Since clsC inherited clsA as protected, clsA's public and protected members are now protected in clsC.
// So in clsE, they will remain protected (due to protected inheritance chain).
class clsE : public clsC
{
public:
	void func6()
	{
		// We can still access clsA's protected members through clsC
		var2 = 200;  // OK: var2 is protected in clsC
		clsA::func2();     // OK: func2 is protected in clsC
		clsC::func5();     // OK: func5 is public in clsC
	}
};

// Basic Example
class Base {
	public:    int pub;
	protected: int prot;
	private:   int priv;
};

class Derived : public Base {
	public:    int myPub;
	protected: int myProt;
	private:   int myPriv;
};

class Derived2 : protected Derived {
	// Now we're looking at access in Derived2.
};


int main()
{
	clsB b;
	// b.var2; // Error: var2 is protected in clsA and remains protected in clsB (not accessible through object)

	b.var3;       // OK: var3 is public in clsA and remains public in clsB
	b.func3();    // OK: func3 is public in clsA and accessible via object of clsB
	b.func1();    // OK: func1 is defined as public in clsB

	clsC c;
	// c.var3;    // Error: var3 is inherited as protected in clsC, not accessible via object
	// c.func3(); // Error: func3 is protected in clsC due to protected inheritance
	c.func5();    // OK: func5 is public in clsC

	clsE e;
	// e.var2; // Error: var2 is still protected
	// e.func2(); // Error: still protected
	// e.func3(); // Error: still protected
	e.func5();   // OK: public in clsC
	e.func6();   // OK: public in clsE

	return 0;
}
