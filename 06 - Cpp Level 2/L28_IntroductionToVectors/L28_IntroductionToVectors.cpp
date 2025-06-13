#include <iostream>
#include <vector>

using namespace std;

int main() {

	// std::vector <T> vector_name
	vector <int> vNumbers = { 10, 20, 30, 40 ,50 };

	cout << "Numbers vector: ";

	// ranged loop
	for (int& number : vNumbers)
	{
		cout << number << " ";
	}

	cout << endl;

	return 0;
}