#include <iostream>

int multiplicationSum(short n)
{
	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) 
		{
			sum += i * j;
		}
	}

	return sum;
}

int main()
{
    std::cout << multiplicationSum(5);
}
