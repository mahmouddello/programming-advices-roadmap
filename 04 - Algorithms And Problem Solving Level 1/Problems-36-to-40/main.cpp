#include <iostream>
#include <cmath>

using namespace std;

// Problem Solving in order, from #36 to # 40

// ----------- Problem #36 - Simple Calculator -----------

enum enOperationType {
	Add = '+', 
	Substract = '-', 
	Multiply = '*', 
	Divide = '/'
};

float ReadNumber(string message)
{
	cout << message;

	int number;
	cin >> number;

	return number;
}

enOperationType ReadOperation()
{
	char operation = '+'; // placeholder

	cout << "Choose an operation from (+, -, *, /): ";
	cin >> operation;

	return enOperationType(operation);

}

float CalculateResult(int number1, int number2, enOperationType operationType)
{
	switch (operationType)
	{
	case Add:
		return number1 + number2;
	case Substract:
		return number1 - number2;
	case Multiply:
		return number1 * number2;
	case Divide:
		return number1 / number2;
	default:
		return number1 + number2;
	}
}

// ----------- Problem #37 - Sum Until -99 -----------

int CalculateSumUntilMinus99()
{
	int number = 0, sum = 0;
	
	while (true)
	{
		number = ReadNumber("Please enter a number: ");

		if (number == -99)
			break;

		sum += number;
	}

	return sum;
}

void DisplaySumResult(int sum)
{
	cout << "Sum of numbers is: " << sum << endl;
}

// ----------- Problem #38 Is Prime Number -----------

enum enNumberStatus {Prime = 1, NotPrime = 2};

enNumberStatus CheckNumber(int number)
{

	int m = number / 2;

	for (int i = 2; i <= m; i++)
		if (number % i == 0)
			return enNumberStatus::NotPrime;

	return enNumberStatus::Prime;
}

void PrintNumberPrimeStatus(enNumberStatus numberStatus)
{
	if (numberStatus == enNumberStatus::Prime)
		cout << "The number above is a prime number";
	else
		cout << "The number above is a non-prime number";
}

// ----------- Problem #39 - Pay Remainder -----------

struct stBill
{
	float totalBill;
	float cashPaid;
};

stBill ReadBillInfo()
{
	stBill billInfo;

	cout << "Enter total bill: ";
	cin >> billInfo.totalBill;

	cout << "Enter total cash paid: ";
	cin >> billInfo.cashPaid;

	return billInfo;
}

float CalculateReminder(stBill billInfo)
{
	return billInfo.cashPaid - billInfo.totalBill;
}

void PrintBillReminder(float reminder)
{
	if (reminder < 0)
		cout << "No reminder, you should pay $" << abs(reminder) << " more." << endl;
	else
		cout << "Reminder: " << reminder << endl;
}

// ----------- Problem #40 - Service Fee and Sales Tax -----------

float ReadBillValue()
{
	float billValue;

	cout << "Enter bill value: ";
	cin >> billValue;

	return billValue;
}

float CalculateFee(float billValue)
{
	billValue = billValue + (billValue * 0.1);
	billValue = billValue + (billValue * 0.16);

	return billValue;
}

void PrintBillAfterFee(float billAfterFee)
{
	cout << "Bill After Taxes: " << billAfterFee << endl;
}

int main()
{
	PrintBillAfterFee(CalculateFee(ReadBillValue()));
	return 0;
}
