#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

// ------------------ OPERATIONS ------------------
void insertAtBeginning(Node* &head, int value)
{
	// Create new node and assign the value to data attribute
	Node* newNode = new Node();
	newNode->data = value;

	// Make new node points to head, then make head equals the new node.
	// In this way, newNode->next will point to the old first element in the LL.
	// Then head will become the newNode.
	newNode->next = head;
	head = newNode;
}

Node* find(Node* head, int value)
{
	while (head != NULL)
	{
		if (head->data == value)
			return head;

		head = head->next;
	}

	return NULL;
}

void insertAfter(Node* prevNode, int value)
{
	if (prevNode == NULL)
	{
		cout << "\nPrev Node can't be NULL!" << endl;
		return;
	}

	Node* newNode = new Node();
	newNode->data = value;

	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

void insertAtEnd(Node* &head, int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = NULL;

	// If linked list is empty, make the head the last added node
	if (head == NULL)
	{
		head = newNode;
		return;
	}

	Node* lastNode = head;

	while (lastNode->next != NULL)
		lastNode = lastNode->next;

	lastNode->next = newNode;

	return;
}

void deleteNode(Node* &head, int value)
{
	Node* current = head, * previous = head;

	// If list is empty, exit
	if (head == NULL)
		return;
	

	if (current->data == value)
	{
		head = current->next;
		delete current;
		return;
	}

	// current and previous pointers walking together until node is found or not found.
	while (current->next != NULL && current->data != value)
	{
		previous = current;
		current = current->next;
	}

	// if node not found, exit the function
	if (current == NULL)
		return;

	// Node found, make the previous points to next element of to be delete node, and free it from memory
	previous->next = current->next;
	delete current;
}

void deleteFirstNode(Node*& head)
{
	if (head == NULL)
		return;

	Node* current = head;

	head = current->next;
	delete current;
}

void deleteLastNode(Node*& head)
{
	Node *current = head, *previous = head;

	if (head == NULL)
		return;

	if (head->next == NULL)
	{
		head = NULL;
		delete current; // free from memory
		return;
	}

	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}

	previous->next = NULL;
	delete current;
}


void printLinkedList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data << " --> ";
		head = head->next; // head pointing to next node address.
	}

	cout << "NULL" << endl;
}

int main()
{
	// Node Initialization
	Node* node1 = new Node();
	Node* node2 = new Node();
	Node* node3 = new Node();

	// Assigning data to nodes
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;

	// Connecting nodes with each other 
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	// Assinging node1 to head, the beginning of the linked list
	Node* head = node1;

	cout << head << endl;

	while (head != NULL)
	{
		cout << head->data << " --> ";
		head = head->next; // head pointing to next node address.
	}

	cout << "NULL" << endl;

	cout << "\n\n------------------ OPERATIONS ------------------\n" << endl;

	cout << "1) Insert at beggining:\n";

	Node* head2 = NULL;

	insertAtBeginning(head2, 1);
	insertAtBeginning(head2, 2);
	insertAtBeginning(head2, 3);
	insertAtBeginning(head2, 4);
	insertAtBeginning(head2, 5);

	printLinkedList(head2);

	cout << "\n2) Find node:\n";

	Node* n1 = find(head2, 2);

	if (n1 != NULL)
		cout << "Node Found :-)\n";
	else
		cout << "Node not found :-(\n";

	cout << "\n3) Insert after:\n";

	insertAfter(n1, 500);
	printLinkedList(head2);

	cout << "\n4) Insert at the end:\n";
	Node* head3 = NULL;

	insertAtEnd(head3, 1);
	insertAtEnd(head3, 2);
	insertAtEnd(head3, 3);
	insertAtBeginning(head3, 0);
	insertAtEnd(head3, 4);

	printLinkedList(head3);

	cout << "\n5) Delete Node:\n";
	cout << "\nBEFORE: \n";
	printLinkedList(head3);


	deleteNode(head3, 4);
	cout << "\nAFTER: \n";
	printLinkedList(head3);

	cout << "\n6) Delete first node:\n";

	deleteFirstNode(head3);
	printLinkedList(head3);


	cout << "\n7) Delete last node:\n";

	deleteLastNode(head3);
	printLinkedList(head3);

	return 0;
}
