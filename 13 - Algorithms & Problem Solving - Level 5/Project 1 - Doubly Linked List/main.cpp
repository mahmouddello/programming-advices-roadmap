#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
	clsDblLinkedList<int> myDblLinkedList;

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

	return 0;
}
