#include <iostream>

using namespace std;

// Problems Solution in order, from #31 to #35

// ------- Problem #31 Power of 2, 3, 4 -------

int ReadNumber()
{
	int number;

	cout << "Please enter a number: ";
	cin >> number;

	return number;
}

void PowerOf2_3_4(int number)
{
	for (int i = 2; i <= 4; i++)
		cout << number << "^" << i << " = " << pow(number, i) << endl;
}

// ------- Problem #32 - Power of M -------

int ReadPower()
{
	int power;

	cout << "Enter a power number: ";
	cin >> power;

	return power;

}

int PowerOfM(int number, int power)
{

	if (power == 0)
		return 1;

	return pow(number, power);
}

// ------- Problem #33 Grade A,B,C,D,E,F -------

enum enGrades {A = 90, B = 80, C = 70, D = 60, E = 50};

int ReadGrade(int From, int To)
{
	int grade;

	do {
		cout << "Please enter your grade: ";
		cin >> grade;
	} while (grade < From || grade > To);

	return grade;
}

char CheckGrade(int grade)
{
	if (grade >= enGrades::A)
		return 'A';

	else if (grade >= enGrades::B)
		return 'B';

	else if (grade >= enGrades::C)
		return 'C';

	else if (grade >= enGrades::D)
		return 'D';

	else if (grade >= enGrades::E)
		return 'E';

	return 'F';

}

void PrintGradeResult(char gradeCharachter)
{
	cout << "You scored " << gradeCharachter << "!" << endl;
}

// ------- Problem #34 - Commission Percentage -------

unsigned int ReadTotalSales()
{	
	unsigned int totalSales;

	do {
		cout << "Input total sales: ";
		cin >> totalSales;
	} while (totalSales < 0);

	return totalSales;

}

enum enSalesRange {};

float CalculatePercentage(unsigned int totalSales)
{
	if (totalSales >= 1'000'000)
		return totalSales * 0.01;

	else if (totalSales >= 500'000)
		return totalSales * 0.02;

	else if (totalSales >= 100'000)
		return totalSales * 0.03;


	else if (totalSales >= 50'000)
		return totalSales * 0.05;

	return totalSales;

}

void PrintFinalCommission(float commission)
{
	cout << commission << endl;
}

// ------- Problem #35 - Piggy Bank Calculator -------

enum enMoneyForm {
	penny = 1, 
	nickle = 5, 
	dime = 10, 
	quarter = 25, 
	dollar = 100
};

struct stMoney {
	int pennies;
	int nickles;
	int dimes;
	int quarters;
	int dollars;
};

stMoney ReadMoneyInfo()
{
	stMoney myMoney;

	cout << "How many pennies do you have? ";
	cin >> myMoney.pennies;

	cout << "How many nickles do you have? ";
	cin >> myMoney.nickles;

	cout << "How many dimes do you have? ";
	cin >> myMoney.dimes;

	cout << "How many quarters do you have? ";
	cin >> myMoney.quarters;

	cout << "How many dollars do you have? ";
	cin >> myMoney.dollars;

	return myMoney;

}

float CalculateTotalMoney(stMoney myMoney)
{
	float totalMoney;

	totalMoney = (myMoney.pennies * penny) + (myMoney.nickles * nickle) + (myMoney.dimes * dime);
	totalMoney = totalMoney + (myMoney.quarters) * quarter + (myMoney.dollars * dollar);

	return totalMoney;
}

void PrintPiggyBankResults(float totalMoney)
{
	cout << "Your total money that has been found in the piggy bank: \n";
	cout << totalMoney << " pennies \n" << totalMoney / 100 << " Dollars" << endl;
}


int main()
{
	PrintPiggyBankResults(CalculateTotalMoney(ReadMoneyInfo()));
	return 0;
}