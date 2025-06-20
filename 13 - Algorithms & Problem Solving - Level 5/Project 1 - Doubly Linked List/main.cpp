#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
	clsDblLinkedList<int> myDblLinkedList;

	if (myDblLinkedList.isEmpty())
		cout << "List is currently empty!\n\n";
	else
		cout << "List contains element(s), not empty!\n\n";

	myDblLinkedList.insertAtBeginning(5);
	myDblLinkedList.insertAtBeginning(4);
	myDblLinkedList.insertAtBeginning(3);
	myDblLinkedList.insertAtBeginning(2);
	myDblLinkedList.insertAtBeginning(1);

	myDblLinkedList.print();


	clsDblLinkedList<int>::Node* n1 = myDblLinkedList.find(2);
	if (n1 != NULL)
		cout << "\nNode with value 2 has been found :)\n";
	else
		cout << "\nNode hasn't been found :(\n";

	myDblLinkedList.insertAfter(n1, 500);
	cout << "\nInserting 500 after node with value 2:\n";
	myDblLinkedList.print();

	cout << "\nInserting 911 at the end of linked list:\n";
	myDblLinkedList.insertAtEnd(911);
	myDblLinkedList.print();

	cout << "\nDeleting node with value (1):\n";
	clsDblLinkedList<int>::Node* n2 = myDblLinkedList.find(1);
	myDblLinkedList.deleteNode(n2);
	myDblLinkedList.print();

	cout << "\nDeleting first node:\n";
	myDblLinkedList.deleteFirstNode();
	myDblLinkedList.print();

	cout << "\nDeleting last node:\n";
	myDblLinkedList.deleteLastNode();
	myDblLinkedList.print();

	cout << "\nSize of the linked list is: " << myDblLinkedList.size() << endl;

	cout << "\nExecuting clear()." << endl;
	myDblLinkedList.clear();

	cout << "\nSize of the linked list is: " << myDblLinkedList.size() << endl;


	myDblLinkedList.insertAtBeginning(5);
	myDblLinkedList.insertAtBeginning(4);
	myDblLinkedList.insertAtBeginning(3);
	myDblLinkedList.insertAtBeginning(2);
	myDblLinkedList.insertAtBeginning(1);
	myDblLinkedList.print();
	cout << endl;

	myDblLinkedList.reverse();
	myDblLinkedList.print();

	myDblLinkedList.reverse(); // return to original state
	clsDblLinkedList<int>::Node* n3 = myDblLinkedList.getNodeByIndex(4);

	if (n3 != NULL)
		cout << "\nNode value is: " << n3->value << endl;
	else
		cout << "\nNode doesn't exist!" << endl;

	cout << "\nItem(2) value is: " << myDblLinkedList.getItem(2) << endl;

	if (myDblLinkedList.updateByIndex(2, 500))
	{
		cout << "\nNode's value updated sucessfully, Updated List:\n";
		myDblLinkedList.print();
	}
	else
		cout << "\nNode with index (2) hasn't been found! no updated performed" << endl;

	if (myDblLinkedList.insertAfter(2, 911))
	{
		cout << "\nInserting 911 after node index 2:\n";
		myDblLinkedList.print();
	}
	else
		cout << "\nNo insertion was performed, index out of range!" << endl;

	return 0;
}
