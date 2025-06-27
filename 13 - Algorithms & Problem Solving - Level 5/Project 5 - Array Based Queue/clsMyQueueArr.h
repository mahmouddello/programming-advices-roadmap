#pragma once
#include "../Project 4 - MyDynamicArray/clsDynamicArray.h"

template <class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray<T> _myArray;
public:
	void push(const T& value)
	{
		_myArray.insertAtEnd(value);
	}

	void pop()
	{
		_myArray.deleteFirstItem();
	}

	void print()
	{
		_myArray.print();
	}

	T front()
	{
		return _myArray.getItem(0);
	}

	T back()
	{
		return _myArray.getItem(_myArray.size() - 1);
	}

	T getItem(const short& index)
	{
		return _myArray.getItem(index);
	}

	void reverse()
	{
		_myArray.reverse();
	}

	bool updateItem(const short& index, const T& val)
	{
		return _myArray.setItem(index, val);
	}

	bool insertAfter(const short& index, const T& val)
	{
		return _myArray.insertAfter(index, val);
	}

	void insertAtFront(const T& val)
	{
		_myArray.insertAtBeginning(val);
	}

	void insertAtBack(const T& val)
	{
		_myArray.insertAtEnd(val);
	}

	void clear()
	{
		_myArray.clear();
	}

	unsigned short size()
	{
		return _myArray.size();
	}
};

