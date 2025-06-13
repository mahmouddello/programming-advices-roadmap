#include <iostream>
#include <vector>

using namespace std;

// iterators: a way to loop on vector elements using pointers

int main() {

	vector<int> numbers{ 1, 2, 3, 4, 5 };

	// declare iterator, acts internally like a pointer
	vector<int>::iterator iter;

	// numbers.begin: first element address in vector
	// numbers.end: one past last element address in memory
	// *iter pointing on each element address like pointer, we dereferencing it to get values

	for (iter = numbers.begin(); iter != numbers.end(); iter++)
	{
		cout << "Iterator pointing to address -> " << &(*iter) << endl;
		cout << *iter << endl;
	}

	/*
		Once iter is equal to numbers.end(), the condition iter != numbers.end() becomes false, 
		and the loop exits.

		Key Idea
		begin() points to the first element’s address.
		end() points past the last element’s address.
		The loop stops when iter reaches end() because their stored addresses match.
	*/

	return 0;
}