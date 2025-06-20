#include <iostream>
#include "clsMyQueue.h"

using namespace std;

int main()
{
	clsMyQueue<int> myQueue;

	myQueue.push(10);
	myQueue.push(20);
	myQueue.push(30);
	myQueue.push(40);
	myQueue.push(50);

	myQueue.print();

	cout << "Size = " << myQueue.size() << endl;
	cout << "Front = " << myQueue.front() << endl;
	cout << "Back = " << myQueue.back() << endl;

	myQueue.pop();
	cout << "\nQueue after pop():\n";
	myQueue.print();

	// Extensions

	// #1 getItem(index)
	cout << "\n\nItem at index (2) = " << myQueue.getItem(2);
	myQueue.reverse();

	// #2 reverse queue
	cout << "\n\nReversed Queue:\n";
	myQueue.print();

	// #3 updateItem(index, val)
	if (myQueue.updateItem(2, 911))
	{
		cout << "\nUpdate Item at index (2) to 911:\n";
		myQueue.print();
	}
	else
		cout << "\nNo updated performed, error occurd!" << endl;

	// #4 insertAfter(index, val)
	if (myQueue.insertAfter(2, 420))
	{
		cout << "\nInsert Item after index (2) , val = 420:\n";
		myQueue.print();
	}
	else
		cout << "\nNo insertion performed, error occurd!" << endl;

	// #5 insertAtFront(val)
	myQueue.insertAtFront(679);
	cout << "\nInsert 679 at front:\n";
	myQueue.print();

	// #6 insertAtBack(val)
	myQueue.insertAtBack(1337);
	cout << "\nInsert 1337 at back:\n";
	myQueue.print();

	// #7 clear
	myQueue.clear();
	cout << "\nAfter cleaning queue, Size = " << myQueue.size() << endl;
	myQueue.print();

	return 0;
}