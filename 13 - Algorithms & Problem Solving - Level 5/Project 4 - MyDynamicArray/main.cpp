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

	//cout << "\nArray after clearing elements:\n";
	//myDynamicArr.clear();
	//myDynamicArr.print();

	cout << "\nArray after deleting item (1):\n";
	myDynamicArr.deleteAt(1);
	myDynamicArr.print();

	cout << "\nArray after deleting first item:\n";
	myDynamicArr.deleteFirstItem();
	myDynamicArr.print();

	cout << "\nArray after deleting last item:\n";
	myDynamicArr.deleteLastItem();
	myDynamicArr.print();

	short index = myDynamicArr.find(20);
	if (index == -1)
		cout << "\nItem wasn't found :(\n";
	else
		cout << "\nItem 20 found at index " << index;

	if (myDynamicArr.deleteItem(20))
	{
		cout << "\nItem deleted successfully! New Array: ";
		myDynamicArr.print();
	}
	else
		cout << "\nItem wasn't found, no deletion performed\n" << endl;


	// reset array
	myDynamicArr.resize(5);
	myDynamicArr.setItem(0, 10);
	myDynamicArr.setItem(1, 20);
	myDynamicArr.setItem(2, 30);
	myDynamicArr.setItem(3, 40);
	myDynamicArr.setItem(4, 50);

	cout << "\nArray after inseting 500 at index (2):\n";
	myDynamicArr.insertAt(2, 500);
	myDynamicArr.print();

	return 0;
}
