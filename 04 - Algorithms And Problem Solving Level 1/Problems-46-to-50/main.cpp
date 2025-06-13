#include <iostream>

using namespace std;

// Problem Solving in order from #46 to #50

// ----------- Problem #46 - Print Letters from A to Z -----------

void PrintLettersAtoZ()
{
	for (int i = 65; i <= 90; i++)
	{
		cout << char(i) << " ";
	}

	cout << "\n" << endl;
}

// ----------- Problem #47 - Loan Instalment Months -----------

int ReadPositiveNumber(string message)
{
	int number;

	do {
		cout << message;
		cin >> number;
	} while (number <= 0);

	return number;
}

int TotalMonths(int totalLoan, int monthlyPayment)
{
	return totalLoan / monthlyPayment;
}

// ----------- Problem #48 - Monthly Loan Installment -----------

float MonthlyPaymentAmount(int loanAmonut, int months)
{
	return loanAmonut / months;
}

// ----------- Problem #49 - ATM PIN -----------

string ReadUserPIN()
{
	string pin;

	cout << "Please enter your pin: ";
	cin >> pin;

	return pin;
}

bool Login()
{

	string userPIN;

	do {
		userPIN = ReadUserPIN();

		if (userPIN == "1234")
		{
			return 1; // true
		}

		else
		{
			system("Color 4F"); // turn screen to red
			cout << "Wrong Pin!" << endl;
		}
	} while (userPIN != "1234");
}

// ----------- Problem #50 - ATM PIN (3 tries) -----------

bool LoginWith3Tries()
{

	string userPIN;
	int tries = 3;

	do {
		userPIN = ReadUserPIN();

		if (userPIN == "1234")
		{
			return 1; // true
		}

		else
		{
			system("Color 4F"); // turn screen to red
			cout << "Wrong Pin!" << endl;
			tries--;
			cout << "You have " << tries << " tries left!" << endl;
		}
	} while (tries >= 1);

	return 0;
}

int main()
{
	if (LoginWith3Tries())
	{
		system("Color 2F"); // turn screen to green
		cout << "Your Balance Is 7500" << endl;
	}

	else
		cout << "You are out of tries, card is locked !" << endl;

	return 0;
}