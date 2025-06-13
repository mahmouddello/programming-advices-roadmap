#include < iostream>
#include <string>
using namespace std;

void myFunction()
{

	cout << "This is my first function, it got executed :-) " << endl;

}

// --------------- HOMEWORK ---------------

void DisplayCardDetails()
{
	string name = "Mahmoud Dello", city = "Mersin", country = "Turkey";
	short age = 21;


	cout << "*************************" << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "City: " << city << endl;
	cout << "Country: " << country << endl;
	cout << "*************************" << endl;

}

void SquareOfStars()
{

	cout << "*********" << endl;
	cout << "*********" << endl;
	cout << "*********" << endl;
	cout << "*********" << endl;
	cout << "*********" << endl;
	cout << "*********" << endl;
	
}

void Latter()
{
	cout << "I like programming!\n\n";
	cout << "I promise to be the best developer\n\n";
	cout << "I know it will take sometime to practice, but I will achieve my goal.\n\n";
	cout << "Best Regards\n" << "Mahmoud Dello\n\n\n";
}

void PrintLetterH()
{

	cout << "*     *\n*     *\n* * * *" << endl;
	cout << "*     *\n*     *" << endl;

}

int main()
{
	PrintLetterH();
	return 0;
}