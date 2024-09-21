#include <iostream>
#include <string>

using namespace std;

/*
	Problems are in order from #6 to #10
*/

// ----------- Problem #6 - Full Name -----------

struct stUserInfo
{
	string firstName;
	string lastName;
};

stUserInfo ReadInfo()
{
	stUserInfo userInfo;

	cout << "Please enter your first name: ";
	cin >> userInfo.firstName;

	cout << "Please enter your last name: ";
	cin >> userInfo.lastName;


	return userInfo;

}

string getFullName(stUserInfo userInfo)
{
	string fullName = userInfo.firstName + " " + userInfo.lastName;

	return fullName;
}

void PrintInfo(string userFullName)
{
	cout << "Your full name is: " << userFullName << endl;
}

// ----------- Problem #7 - Half Number -----------

int ReadNumber()
{
	int number;

	cout << "Please enter a number: ";
	cin >> number;

	return number;
}

float CalculateHalfOfNumber(int number)
{
	return float(number / 2);
}

void PrintResults(int number)
{
	string result = "Half of " + to_string(number) + " is " + to_string(CalculateHalfOfNumber(number));

	cout << result << endl;
}

// ----------- Problem #8 - Pass/Fail  -----------

enum enMarkStatus {Fail = 0, Pass = 1};

float ReadMark()
{
	float mark;

	cout << "Enter your mark: ";
	cin >> mark;

	return mark;
}

enMarkStatus CheckMark(float mark)
{
	if (mark >= 50)
		return enMarkStatus::Pass;

	return enMarkStatus::Fail;
}
 
void PrintMarkResult(enMarkStatus markStatus)
{
	if (markStatus == enMarkStatus::Pass)
		cout << "PASS" << endl;

	else
		cout << "FAIL" << endl;
}

// ----------- Problem #9 - Sum of 3 Numbers -----------

void ReadNumbers(int numbers[3])
{

	for (int i = 0; i < 3; i++)
	{
		cout << "Please enter " << i + 1 << ". number: ";
		cin >> numbers[i];
	}

}

int CalculateSum(int numbers[3])
{

	int sum = 0;

	for (int i = 0; i < 3; i++)
	{
		sum += numbers[i];
	}

	return sum;
}

void PrintSumResult(int sum)
{
	cout << "Sum = " << sum << endl;
}

// ----------- Problem #10 - Average of 3 numbers -----------

// Used ReadNumbers & CalculateSum functions from the previous problem #9
float CalculateAverage(int numbers[3])
{
	return (float)CalculateSum(numbers) / 3;
}

void PrintAverageResult(float average)
{
	cout << "Average = " << average << endl;
}

int main()
{
	int numbersArray[3];
	ReadNumbers(numbersArray);
	PrintAverageResult(CalculateAverage(numbersArray));
}
