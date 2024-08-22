#include <iostream>
#include <string>

using namespace std;

void Introduction()
{
	string MyString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << "The length of the MyString is: " << MyString.length() << endl;
	cout << MyString[2] << endl; // will print C

	string S1 = "10";
	string S2 = "20";

	string S3 = S1 + S2; // string concatenation

	cout << S3 << endl;

	int Sum = stoi(S1) + stoi(S2);
	cout << Sum << endl; // will print 30
}

void GetLineFunctionExplination()
{
	/*
		When using `cin`, we can't input a string that have spaces, if so, the cin will truncate that string.
		Example: cin >> name; Mahmoud Dello
		cout << name << endl; whould be just "Mahmoud"

		To solve this we use `getline(cin, name)` function.

	*/

	string name;
	getline(cin, name);

	cout << name << endl;


}

// --------------- HOMEWORK ---------------

void Homework()
{

	string fullName;
	cout << "Please enter full name? ";
	getline(cin, fullName);

	cout << fullName << "\n" << endl;

	string String2; 
	cout << "Please enter String2: ";
	cin >> String2;

	string String3;
	cout << "Please enter String3: ";
	cin >> String3;

	cout << "*****************" << endl;

	cout << "The length of fullName is: " << fullName.length() << endl;
	cout << "Characters of fullName at 0, 2, 4, 7: ";
	cout << fullName[0] << ", " << fullName[2] << ", " << fullName[4] << ", " << fullName[7] << endl;

	cout << "Concatenating String2 and String3: " << String2 + String3 << endl;

	int num1 = stoi(String2);
	int num2 = stoi(String3);

	cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;

}

int main() {

	//Introduction();
	// GetLineFunctionExplanation();
	Homework();

	return 0;
}
