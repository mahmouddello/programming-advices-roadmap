#include <iostream>

using namespace std;

class clsA
{
public:
	int x = 0;
	void print()
	{
		cout << "Value of x = " << x << endl;
	}
};


//object sent by value, any updates will not be reflected on the original object
void fun1(clsA a)
{
	a.x = 100;
}

//object sent by reference, any updates will be reflected on the original object
void fun2(clsA& a)
{
	a.x = 200;
}

int main()
{
	clsA a;

	a.x = 50;
	cout << "\na.x before calling function1:\n";
	a.print();

	//Pass by value, object will not be afected.
	fun1(a);
	cout << "\nA.x after calling function1 byval: \n";
	a.print();

	//Pass by reference, object will be afected.
	fun2(a);
	cout << "\nA.x after calling function2 byref: \n";
	a.print();
	system("pause>0");

}