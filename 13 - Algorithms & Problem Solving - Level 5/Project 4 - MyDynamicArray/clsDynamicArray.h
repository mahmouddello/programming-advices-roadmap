#pragma once
#include <iostream>

template <class T>
class clsDynamicArray
{
protected:
	unsigned short _maxSize;
	T* _array;
public:
	clsDynamicArray(unsigned short maxSize = 0)
	{
		if (maxSize < 0)
			maxSize = 0;

		_maxSize = maxSize;
		_array = new T[maxSize];
	}

	~clsDynamicArray()
	{
		delete[] _array;
	}

	void setItem(const unsigned short& index, const T& value)
	{
		if (index < 0 || index >= _maxSize)
			return;

		_array[index] = value;
	}

	void print()
	{
		for (unsigned short i = 0; i < _maxSize; i++)
		{
			std::cout << *(_array + i) << " ";
		}

		std::cout << std::endl;
	}

	unsigned short size()
	{
		return _maxSize;
	}

	bool isEmpty()
	{
		return _maxSize == 0;
	}
};

