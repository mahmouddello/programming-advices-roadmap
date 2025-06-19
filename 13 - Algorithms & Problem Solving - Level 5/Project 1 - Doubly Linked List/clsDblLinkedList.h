#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDblLinkedList
{
public:
	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;
	};
	Node* head;

	clsDblLinkedList() : head(NULL) {}

	void insertAtBeginning(const T& value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->prev = NULL;

		if (this->head == NULL)
		{
			newNode->next = NULL;
			this->head = newNode;
			return;
		}

		newNode->next = this->head;
		this->head->prev = newNode;
		this->head = newNode;
	}

	void print()
	{
		Node* temp = this->head;
		while (temp != NULL)
		{
			cout << temp->value << " <---> ";
			temp = temp->next;
		}

		cout << endl;
		delete temp;
	}

	Node* find(const T& value)
	{
		Node* current = this->head;
		
		while (current != NULL)
		{
			if (current->value == value)
				return current;

			current = current->next;
		}

		return NULL;
	}

	Node* findLastNode()
	{
		if (head == NULL)
			return NULL;

		Node* current = head;
		
		while (current->next != NULL)
			current = current->next;

		return current;
	}
	
	void insertAfter(Node* node, const T& value)
	{
		if (node == NULL)
			return;

		Node* newNode = new Node();
		newNode->value = value;

		newNode->next = node->next;
		newNode->prev = node;
		
		if (node->next != NULL)
		{
			node->next->prev = newNode;
		}

		node->next = newNode;
	}

	void insertAtEnd(const T& value)
	{
		Node* lastNode = findLastNode();

		Node* newNode = new Node();
		newNode->value = value;

		// no node
		if (lastNode == NULL)
		{
			newNode->prev = NULL;
			newNode->next = NULL;
			this->head = newNode;
			return;
		}

		newNode->next = NULL;
		newNode->prev = lastNode;

		lastNode->next = newNode;
	}

	void deleteNode(Node* node)
	{
		if (node == NULL)
			return;

		if (node == this->head)
		{
			this->head = node->next;

			if (this->head != NULL)
				this->head->prev = NULL;

			delete node;
			return;
		}

		// node is NOT the head, so node->prev is guaranteed not NULL
		node->prev->next = node->next;

		if (node->next != NULL)
			node->next->prev = node->prev;

		delete node;
	}

	void deleteFirstNode()
	{
		if (this->head == NULL)
			return;

		Node* nodeToDelete = head;

		// single node
		if (this->head->next == NULL)
		{
			this->head = NULL;
			delete nodeToDelete;
			return;
		}

		this->head = this->head->next;
		this->head->prev = NULL;

		delete nodeToDelete;
	}

	void deleteLastNode()
	{
		Node* nodeToDelete = findLastNode();

		if (nodeToDelete == NULL)
			return;

		if (nodeToDelete == this->head)
		{
			delete nodeToDelete;
			this->head = NULL;
			return;
		}
			
		nodeToDelete->prev->next = NULL;
		delete nodeToDelete;
	}

};

