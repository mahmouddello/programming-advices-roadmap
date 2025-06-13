#include <iostream>
#include <vector>

using namespace std;

void ReadNumbers(vector <int>& vUserNumbers)
{
	int number = 0;
	char choice = 'y';

	do {
		cout << "Enter a number to add to the vector:\n";
		cin >> number;

		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid Input, Enter a valid number:" << endl;
			cin >> number;
		}

		vUserNumbers.push_back(number);

		cout << "Do you want to add more numbers? 'y' or 'n'?\n";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');

}

void PrintNumbers(vector <int>& vUserNumbers)
{
	cout << "User Number Vector: ";

	for (int& number : vUserNumbers)
	{
		cout << number << " ";
	}

	cout << endl;
}

int main() {

	//vector <int> vNumbers;
	vector <int> vUserNumbers;

	//vNumbers.push_back(10);
	//vNumbers.push_back(20);
	//vNumbers.push_back(30);
	//vNumbers.push_back(40);
	//vNumbers.push_back(50);

	//cout << "Numbers Vector: ";

	//for (int& number : vNumbers)
	//{
	//	cout << number << " ";
	//}

	//cout << endl;

	ReadNumbers(vUserNumbers);
	PrintNumbers(vUserNumbers);

	return 0;
}