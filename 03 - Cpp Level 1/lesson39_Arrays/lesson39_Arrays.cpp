#include <iostream>

using namespace std;

void PrintDivider() {
	cout << "----------------------------------------------------" << endl;
}

void IntroToArrays()
{

	// array of integers
	int x1[5] = { 22, 18, 2, 5, 520 };

	cout << x1[0] << endl;
	cout << x1[1] << endl;
	cout << x1[2] << endl;
	cout << x1[3] << endl;
	cout << x1[4] << endl;

	PrintDivider();

	
	// Another way to define an array
	int x2[5];

	x2[0] = 20;
	x2[1] = 40;

	// we can do operations on this variables
	cout << x2[0] + x2[1] << endl;
}

// ---------------- HOMEWORK ----------------

void ReadUserGrades()
{
	
	float grades[3], avg;

	cout << "Enter Grade 1: ";
	cin >> grades[0];

	cout << "Enter Grade 2: ";
	cin >> grades[1];

	cout << "Enter Grade 3: ";
	cin >> grades[2];

	cout << "*******************" << endl;

	avg = (grades[0] + grades[1] + grades[2]) / 3;

	cout << "The Average of grades is: " << avg << endl;

}


int main()
{
	ReadUserGrades();
	return 0;
}
