#include <iostream>

using namespace std;

/*
	
	Syntax:

	while(condition)
	{
		
		loop body

	}

*/

void ReadPositiveNumber()
{
	int number;
	
	cout << "Enter positive number: ";
	cin >> number;

	while (number < 0)
	{
		cout << "Wrong number, please input a positive number!\n ";
		cin >> number;
	}

	cout << "You've Entered: " << number << endl;

}

int ReadIntInRange(int from, int to)
{
	int number; 

	cout << "Please enter a number in range of [" << from << ", " << to << "]: ";
	cin >> number;

	while (number < from || number > to)
	{
		cout << "Wrong input, please try again: ";
		cin >> number;
	}

	return number;
}

// ----------- HOMEWORK -----------

void Problem26(int N)
{
	// Print Numbers from 1 to N

	int i = 1;

	while (i <= N)
	{
		cout << i << endl;
		i++;
	}

}

void Problem27(int N)
{
	// Problem #27 - Print Numbers from N to 1

	while (N >= 1)
	{
		cout << N << endl;
		N--;
	}

}

int Problem28(int N)
{
	// Problem #28 - Print Sum Odd Numbers from 1 to N

	int i = 1, sum = 0;

	while (i <= N)
	{
		if (i % 2 == 1)
		{
			sum += i;
		}

		i++;
	}

	return sum;

}

int Problem29(int N)
{
	// Problem #29 - Print Sum Even Numbers from 1 to N

	int i = 1, sum = 0;

	while (i <= N)
	{
		if (i % 2 == 0)
		{
			sum += i;
		}

		i++;
	}

	return sum;
}

int Problem30(int N)
{
	// Problem #30 - Factorial of N!
	int i = 1, factorial = 1;

	while (i <= N)
	{
		factorial *= i;
		i++;
	}

	return factorial;
}

int Problem32(int M)
{
	// Problem #32 - Power of M

	int i = 1, number = 3, sum = 1;

	while (i <= M)
	{
		sum *= number;
		i++;
	}

	return sum;

}

int Problem37()
{

	// sum until -99

	int number, sum = 0;

	cout << "Enter a number to add, the sum operation will stop when you enter -99: ";
	cin >> number;

	while (number != -99)
	{
		sum += number;

		cout << "Enter a number: ";
		cin >> number;
	}

	return sum;
}

void Problem46()
{
	// Problem #46 - Print Letters from A to Z

	int index = 65; // 'A' in ASCII

	while (index <= 90)
	{
		cout << char(index) << " ";
		index++;
	}

}

void Problem50()
{
	// Problem #50 - ATM PIN 3 Times

	string pinCode = "1234", userInput;
	short balance = 7500, attepmts = 3;

	while (attepmts != 0)
	{

		cout << "Enter your pin: ";
		cin >> userInput;

		if (userInput == pinCode)
		{
			cout << "Your balance is: " << balance << endl;
			return;
		}

		else
		{
			attepmts--;
			cout << "Wrong pin, you have " << attepmts << " attempts left." << endl;
		}
	}

	if (attepmts == 0)
	{
		cout << "CARD IS LOCKED!" << endl;
	}

}

int main()
{
	Problem50();
	return 0;
}
