#pragma once
#include "../Project 4 - MyDynamicArray/clsDynamicArray.h"

template <class T>
class clsMyStackArr
{
protected:
	clsDynamicArray<T> _stack;

public:
	void push(const T& value)
	{
		_stack.insertAtBeginning(value);
	}

	void pop()
	{
		_stack.deleteFirstItem();
	}

	T top()
	{
		return _stack.getItem(0);
	}

	T bottom()
	{
		return _stack.getItem(_stack.size() - 1);
	}

	void print()
	{
		_stack.print();
	}
};

