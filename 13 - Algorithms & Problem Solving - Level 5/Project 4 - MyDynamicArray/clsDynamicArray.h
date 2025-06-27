#pragma once
#include <iostream>
#include "../../cpplibs/clsUtil.h"

template <class T>
class clsDynamicArray
{
protected:
	unsigned short _size;
	T* _array;
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

	bool setItem(const unsigned short& index, const T& value)
	{
		if (index < 0 || index >= _size)
			return false;

		_array[index] = value;
		return true;
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

		T* tempArray = new T[newSize];

		unsigned short limit = (newSize < _size) ? newSize : _size;

		for (short i = 0; i < limit; i++)
			tempArray[i] = _array[i];

		delete[] _array;
		this->_array = tempArray;
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

	void clear()
	{
		this->resize(0);
	}

	// # Extenstion 5
	void deleteAt(unsigned short index)
	{
		if (index >= _size)
			return;

		T* temp = new T[_size - 1];

		for (short i = 0, j = 0; i < _size; i++)
		{
			if (i == index)
				continue;

			temp[j++] = _array[i];
		}

		delete[] _array;
		_array = temp;
		_size--;
	}

	/*
		programming advices
	bool DeleteItemAt(int index)
	{

		if (index >= _size || index < 0)
		{
			return false;
		}

		_size--;

		_TempArray = new T[_size];

		copy all before index
		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = _array[i];
		}

		copy all after index
		for (int i = index + 1; i < _size + 1; i++)
		{
			_TempArray[i - 1] = _array[i];
		}

		delete[] _array;
		_array = _TempArray;
		return true;

	}
	
	*/

	// # Extension 6 to 7
	void deleteFirstItem()
	{
		if (this->isEmpty())
			return;

		this->deleteAt(0);
	}

	void deleteLastItem()
	{
		if (this->isEmpty())
			return;

		this->deleteAt(this->_size - 1);
	}

	// # Extension 8 to 9

	short find(const T& item)
	{
		for (short i = 0; i < _size; i++)
			if (_array[i] == item)
				return i;

		return -1;
	}

	bool deleteItem(const T& item)
	{
		short index = find(item);

		if (index == -1)
			return false;

		deleteAt(index);
		return true;
	}

	// Extension 10
	bool insertAt(const unsigned short& index, const T& value)
	{
		if (index > _size)
			return false;

		T* tempArr = new T[_size + 1];

		// copy before
		for (short i = 0; i < index; i++)
			tempArr[i] = _array[i];

		tempArr[index] = value;

		// copy after
		for (short j = index; j < _size; j++)
			tempArr[j + 1] = _array[j];

		delete[] _array;
		_size++;
		_array = tempArr;
		return true;
	}

	// Extensions #11 to #14

	bool insertAtBeginning(const T& value)
	{
		return insertAt(0, value);
	}

	bool insertBefore(const unsigned short& index, const T& value)
	{
		if (index < 1)
			return insertAt(0, value);
		else
			return insertAt(index - 1, value);
	}

	bool insertAfter(const unsigned short& index, const T& value)
	{
		if (index >= _size)
			return insertAt(_size, value);
		else
			return insertAt(index + 1, value);
	}

	bool insertAtEnd(const T& value)
	{
		return insertAfter(_size, value);
	}
};

