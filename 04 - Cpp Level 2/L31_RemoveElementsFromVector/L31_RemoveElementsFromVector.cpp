#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector <int> vNumbers;

	// adding elements
	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);

	cout << "Stack Size after adding elements: " << vNumbers.size() << endl;
	
	vNumbers.pop_back(); // removes 50
	vNumbers.pop_back(); // removes 40
	vNumbers.pop_back(); // removes 30
	vNumbers.pop_back(); // removes 20
	vNumbers.pop_back(); // removes 10

	cout << "Stack Size after deleting elements: " << vNumbers.size() << endl;
	
	if (!vNumbers.empty())
	{
		vNumbers.pop_back(); // will raise an error becuase stack is empty, we should handle this
	}

	if (vNumbers.size() > 0)
	{
		vNumbers.pop_back(); // will raise an error becuase stack is empty, we should handle this
	}

	cout << "Numbers Vector: ";

	for (int& number : vNumbers) {
		cout << number << " ";
	}

	// adding elements
	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);

	vNumbers.clear(); // alternative way to delete all elements of the vector

	cout << endl;

	return 0;
}