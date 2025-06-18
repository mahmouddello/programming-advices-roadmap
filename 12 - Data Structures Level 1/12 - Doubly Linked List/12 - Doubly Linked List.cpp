#include <iostream>

using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node* previous;
};

// --------------- OPERATIONS ---------------

void insertAtBeginning(Node* &head, int value)
{
	// creating node in heap
	Node* newNode = new Node();
	newNode->value = value;

	// connecting the new node with linked list
	newNode->next = head;
	newNode->previous = NULL;

	// If there was a head in the linked list, assign it's previous to newNode
	if (head != NULL)
		head->previous = newNode;

	head = newNode;
}

Node* findNode(Node* head, int value)
{
	while (head != NULL)
	{
		if (head->value == value)
			return head;

		head = head->next;
	}

	return NULL;
}

void insertAfter(Node* current, int value)
{
	/*
		1 - Create a new node with the desired value
		2 - Set the next pointer of the new node to the next node of current node
		3 - set the previous pointer of new node to the current node
		4 - set the next pointer of current node to new node.
		5 - set the previous pointer of next node to new node (If exist)
	*/

	Node* node = new Node();
	node->value = value;
	node->next = current->next;

	if (current->next != NULL)
		current->next->previous = node;

	current->next = node;
}

void insertAtEnd(Node* &head, int value)
{
	Node* newNode = new Node();
	newNode->value = value;
	newNode->next = NULL;

	if (head == NULL)
	{
		newNode->previous = NULL;
		head = newNode;
		return;
	}

	Node* current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = newNode;
	newNode->previous = current;

	return;
}

void deleteNode(Node* &head, int value)
{
	if (head == NULL)
		return;

	if (head->next == NULL && head->previous == NULL)
		delete head;

	Node* nodeToDelete = findNode(head, value);

	if (nodeToDelete != NULL)
	{
		nodeToDelete->next->previous = nodeToDelete->previous;
		nodeToDelete->previous = nodeToDelete->next;

		nodeToDelete->previous = NULL;
		nodeToDelete->next = NULL;
		delete nodeToDelete;
	}

}

void deleteFirstNode(Node*& head)
{
	// no node case
	if (head == NULL)
		return;

	Node* current = head;

	head = current->next;
	
	// Single node case
	if (head->next != NULL)
		head->previous = NULL;

	delete current;
}

void deleteLastNode(Node* head)
{
	// no node case
	if (head == NULL)
		return;

	Node* current = head;

	while (current->next != NULL)
	{
		current = current->next;
	}

	if (current->previous != NULL)
		current->previous->next = NULL;

	delete current;
}

void printDoublyLinkedList(Node* head)
{
	cout << "NULL";
	while (head != NULL)
	{
		cout << " <---> " << head->value;
		head = head->next;
	}
	cout << " ---> NULL\n";
}

int main()
{
	Node* head = NULL;

	// allocate 3 nodes
	Node* node1 = new Node();
	Node* node2 = new Node();
	Node* node3 = new Node();

	// assign value
	node1->value = 1;
	node2->value = 2;
	node3->value = 3;

	// connecting nodes
	node1->previous = NULL;
	node1->next = node2;

	node2->previous = node1;
	node2->next = node3;

	node3->previous = node2;
	node3->next = NULL;

	// Print the doubly linked list

	head = node1;
	
	printDoublyLinkedList(head);
	insertAtBeginning(head, 15);

	printDoublyLinkedList(head);

	if (findNode(head, 15) != NULL)
		cout << "\nNode Found :)" << endl;
	else
		cout << "\nNode not found :(" << endl;

	Node* target = findNode(head, 15);
	insertAfter(target, 800);
	printDoublyLinkedList(head);

	insertAtEnd(head, 950);
	printDoublyLinkedList(head);

	deleteFirstNode(head);
	printDoublyLinkedList(head);

	deleteLastNode(head);
	printDoublyLinkedList(head);

	return 0;
}
