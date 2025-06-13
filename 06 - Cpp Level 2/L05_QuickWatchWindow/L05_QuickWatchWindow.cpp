#include <iostream>

using namespace std;

// Explination in Notion

int MySum(int a, int b)
{
	int sum = 0;
	sum = a + b;
	return sum;
}

int main()
{
	int array[5] = { 10, 20, 30, 40, 50 };

	int a, b, c;

	a = 10;
	b = 20;
	a++;
	++b;

	c = a + b;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	for (int i = 1; i <= 5; i++)
	{
		cout << i << endl;
		a = a + a * i;
	}

	c = MySum(a, b);
	cout << c << endl;

	return 0;
}