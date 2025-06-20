#pragma once
#include "../Project 2 - MyQueue/clsMyQueue.h"

template <class T>
class clsMyStack : public clsMyQueue<T>
{
public:
	void push(const T& value)
	{
		clsMyQueue<T>::insertAtFront(value);
	}

	T top()
	{
		return clsMyQueue<T>::front();
	}

	T bottom()
	{
		return clsMyQueue<T>::back();
	}
};

