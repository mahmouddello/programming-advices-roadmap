#include <iostream>

using namespace std;

void PrintIntroduction()
{
	cout << "\t\t\t\tMultiplication Table From 1 to 10\n" << endl;
	for (int i = 1; i <= 10; i++)
		cout << "\t" << i;
	
	cout << "\n" << endl;
}

void PrintDivider()
{
	cout << "-------------------------------------------------------------------------------";
	cout << "-----------" << endl;
}

void PrintMultiplicationTable()
{

	PrintIntroduction();
	PrintDivider();

	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t|";
		for (int j = 1; j <= 10; j++)
			cout << i * j << "\t";
		cout << "\n";
	}
}

int main()
{
	PrintMultiplicationTable();
	return 0;
}
