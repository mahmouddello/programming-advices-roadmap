#include <vector>
#include <iostream>
using namespace std;

void VectorCapacityAllocation()
{
	vector<int> v;

	for (int i = 1; i <= 10; ++i) {
		v.push_back(i);
		std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << std::endl;
	}
}

int main()
{
	vector<int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);

	if (vNumbers.size() > 0)
	{
		// we should handle these 2 lines becuase if the stack is empty it will raise an execption
		cout << "First Element: " << vNumbers.front() << endl;
		cout << "Last Element: " << vNumbers.back() << endl;
	}

	//returns the number of elements present in the vector
	cout << "Size: " << vNumbers.size() << endl;

	//check the overall size of a vector
	cout << "Capacity : " << vNumbers.capacity() << endl;

	//returns 1 (true) if the vector is empty
	cout << "Empty : " << vNumbers.empty() << endl;

	cout << "\n----------------" << endl;

	VectorCapacityAllocation();

	return 0;
}