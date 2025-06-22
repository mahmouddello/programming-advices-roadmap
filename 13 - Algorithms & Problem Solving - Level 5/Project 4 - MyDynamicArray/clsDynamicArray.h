#pragma once
#include <iostream>
#include "../../cpplibs/clsUtil.h"

template <class T>
class clsDynamicArray
{
protected:
	unsigned short _size;
	T* _array;
	T* _tempArray;
public:
	clsDynamicArray(unsigned short size = 0)
	{
		if (size < 0)
			size = 0;

		_size = size;
		_array = new T[size];
	}

	~clsDynamicArray()
	{
		delete[] _array;
	}

	void setItem(const unsigned short& index, const T& value)
	{
		if (index < 0 || index >= _size)
			return;

		_array[index] = value;
	}

	void print()
	{
		for (unsigned short i = 0; i < _size; i++)
		{
			std::cout << *(_array + i) << " ";
		}

		std::cout << std::endl;
	}

	unsigned short size()
	{
		return _size;
	}

	bool isEmpty()
	{
		return _size == 0;
	}

	// # Extension 1
	void resize(unsigned short newSize)
	{
		if (newSize == this->_size || this->isEmpty())
			return;

		this->_tempArray = new T[newSize];

		unsigned short limit = (newSize < _size) ? newSize : _size;

		for (short i = 0; i < limit; i++)
			this->_tempArray[i] = _array[i];

		delete[] _array;
		this->_array = this->_tempArray;
		this->_size = newSize;
	}

	// # Extension 2 to 4: getItem(index), reverse(), clear()

	T getItem(const unsigned short& index)
	{
		if (index >= this->_size)
			return T();

		return this->_array[index];
	}

	void reverse()
	{
		for (short i = 0; i < _size / 2; i++)
			clsUtil::swap(this->_array[i], this->_array[_size - 1 - i]);
	}

};

