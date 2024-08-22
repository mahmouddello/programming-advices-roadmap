#include <iostream>
#include <string>
using namespace std;

void GlitchedGetline()
{

	int Number;
	string Name;
	string Country;

	cout << "Input Employee Number: " << endl;
	cin >> Number;

	cout << "Input Employee Name: " << endl;
	getline(cin, Name); // getline treats the "enter" click as an input

	cout << "Input Employee Country: ";
	cin >> Country;

	cout << "Number: " << Number << ", Name: " << Name << ", Country: " << Country << endl;

}

void FixedGetline()
{

	int Number;
	string Name;
	string Country;

	cout << "Input Employee Number: " << endl;
	cin >> Number;

	cout << "Input Employee Name: " << endl;
	cin.ignore(1, '\n'); // igonre the "enter" click to be recorded in the cin buffer.

	getline(cin, Name); // getline treats the "enter" click as an input

	cout << "Input Employee Country: ";
	cin >> Country;

	cout << "Number: " << Number << ", Name: " << Name << ", Country: " << Country << endl;

}

int main()
{
	FixedGetline();
	return 0;
}