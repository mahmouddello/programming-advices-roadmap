#include <iostream>
#include "clsMyStackArr.h"

using namespace std;

int main()
{
	clsMyStackArr<int> myStk;

	myStk.push(10);
	myStk.push(20);
	myStk.push(30);
	myStk.push(40);
	myStk.push(50);

	myStk.print();

	cout << "\n\nStack after pop:\n";
	myStk.pop();
	myStk.print();

	cout << "\nStack Top = " << myStk.top();
	cout << "\nStack Bottom = " << myStk.bottom();
}