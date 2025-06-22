#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

int main()
{
	clsDynamicArray<int> myDynamicArr(5);

	myDynamicArr.setItem(0, 10);
	myDynamicArr.setItem(1, 20);
	myDynamicArr.setItem(2, 30);
	myDynamicArr.setItem(3, 40);
	myDynamicArr.setItem(4, 50);

	myDynamicArr.print();

	//myDynamicArr.resize(2);
	//cout << "\nArray after resize, size = " << myDynamicArr.size() << endl;
	//myDynamicArr.print();

	//myDynamicArr.resize(10);
	//cout << "\nArray after resize, size = " << myDynamicArr.size() << endl;
	//myDynamicArr.print();

	cout << "\n" << myDynamicArr.getItem(2) << endl;
	cout << "\nReversed Array:\n";

	myDynamicArr.reverse();
	myDynamicArr.print();

	cout << "\nArray after clearing elements:\n";
	myDynamicArr.clear();
	myDynamicArr.print();

	return 0;
}
