#include <iostream>
#include <vector>

using namespace std;

// try-catch slows our programs, we should only use it in a situation we can't handle
// or have control on

int main() {

	vector<int> numbers{ 1, 2, 3, 4, 5 };

	cout << numbers.at(2) << endl; // no errors

	// it's better to not use try catch because we can control the input of the user
	try
	{
		cout << numbers.at(6) << endl;
	}
	catch (...)
	{
		cout << "Out Of Bounds !!" << endl;
	}

	int num = 0;

	cout << "Enter the poistion of element do you want: ";
	cin >> num;
	cout << "Size  " << numbers.size() << endl;
	if (num <= numbers.size() && num > 0)
	{
		printf("the element number %d is %d  ", num, numbers[num - 1]);
	}
	else
		cout << "Out of range";

	return 0;
}