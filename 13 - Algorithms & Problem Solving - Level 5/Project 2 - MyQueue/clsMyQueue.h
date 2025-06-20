#pragma once
#include "../Project 1 - Doubly Linked List/clsDblLinkedList.h"

template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList<T> _myList; // composition
public:

	void push(const T& value)
	{
		_myList.insertAtEnd(value);
	}

	void pop()
	{
		_myList.deleteFirstNode();
	}

	void print()
	{
		_myList.print();
	}

	unsigned short size()
	{
		return _myList.size();
	}

	T front()
	{
		return _myList.getItem(0);
	}

	T back()
	{
		return _myList.getItem(_myList.getSize() - 1);
	}

	T getItem(const short& index)
	{
		return _myList.getItem(index);
	}

	void reverse()
	{
		_myList.reverse();
	}

	bool updateItem(const short& index, const T& val)
	{
		return _myList.updateByIndex(index, val);
	}

	bool insertAfter(const short& index, const T& val)
	{
		return _myList.insertAfter(index, val);
	}

	void insertAtFront(const T& val)
	{
		_myList.insertAtBeginning(val);
	}

	void insertAtBack(const T& val)
	{
		_myList.insertAtEnd(val);
	}

	void clear()
	{
		_myList.clear();
	}

};

