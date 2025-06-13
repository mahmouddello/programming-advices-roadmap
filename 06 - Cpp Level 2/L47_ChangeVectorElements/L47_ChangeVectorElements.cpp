#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> numbers{ 1, 2, 3, 4, 5 };

	// const won't allow us to apply changes directly to the vector element
	// & we used reference to avoid making copy of each element of the vector 

	cout << "Initial Vector: ";

	for (const int& i : numbers)
	{
		cout << i << " "; 
	}
	cout << endl;

	cout << "\nUpdated Vector: ";

	// modifing the existing element through reference
	for (int& i : numbers)
	{
		i = 20;
		cout << i << " ";
	}

	cout << endl;

	// manual change
	numbers[1] = 40;
	numbers.at(2) = 60;
	numbers.at(4) = 80;

	cout << "\nFinal Vector: ";

	for (const int& i : numbers)
	{
		cout << i << " ";
	}

	cout << endl;

	return 0;
}
