#include <iostream>
#include <limits>

using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please enter a number?" << endl;
	cin >> Number;

	while (cin.fail())
	{
		// user didn't input a number
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Number, Enter a valid one:" << endl;
		cin >> Number;
	}

	return Number;
}
int main()
{

	cout << "Your Number is:" << ReadNumber();

	return 0;
}