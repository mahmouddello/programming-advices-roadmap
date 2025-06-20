#pragma once
#include <iostream>
#include "../../cpplibs/clsUtil.h"

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
private:
	Node* head;
	unsigned short elementCount;
public:
	clsDblLinkedList() : head(NULL), elementCount(0){}

	void insertAtBeginning(const T& value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->prev = NULL;

		if (this->head == NULL)
		{
			newNode->next = NULL;
			this->head = newNode;
			elementCount++;
			return;
		}

		newNode->next = this->head;
		this->head->prev = newNode;
		this->head = newNode;

		elementCount++;
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
		elementCount++;
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

		elementCount++;
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
			elementCount--;
			return;
		}

		// node is NOT the head, so node->prev is guaranteed not NULL
		node->prev->next = node->next;

		if (node->next != NULL)
			node->next->prev = node->prev;

		elementCount--;
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
			elementCount--;
			return;
		}

		this->head = this->head->next;
		this->head->prev = NULL;

		elementCount--;
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
			elementCount--;
			return;
		}
			
		nodeToDelete->prev->next = NULL;
		elementCount--;
		delete nodeToDelete;
	}

	unsigned short size()
	{
		return elementCount;
	}

	bool isEmpty()
	{
		return elementCount == 0;
	}

	void clear()
	{
		while (elementCount > 0)
		{
			this->deleteFirstNode();
		}
	}

	void reverse()
	{
		if (head == NULL)
			return;

		Node* temp = nullptr;
		Node* current = head;

		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		// setting new head
		if (temp != nullptr)
			this->head = temp->prev;
	}

};

