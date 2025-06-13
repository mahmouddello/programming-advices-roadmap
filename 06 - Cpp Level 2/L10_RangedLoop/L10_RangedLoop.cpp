#include <iostream>

using namespace std;

int main()
{
	int array[] = { 10, 20, 30, 40, 50 };

	for (int n : array)
	{
		cout << n << endl;
	}

	string name = "Mahmoud Dello";

	for (char c : name)
	{
		cout << c << " ";
	}

	return 0;
}