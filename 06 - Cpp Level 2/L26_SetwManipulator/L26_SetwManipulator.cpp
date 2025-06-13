#include <iostream>
#include <iomanip> // setw stored here

using namespace std;

// setw is not a function, it's a manipulator.
// setw(number), reserves a number of white spaces, starts writing from right to left so it leaves blanks on left
// by default it starts allignment from right, we can change it with << right or << left args.

void RoadmapProgress()
{
	cout << "---------------|----------------------------------------------------|---------------|" << endl;
	cout << "  Course Code  |                    Course Name                     |   Progress    |" << endl;
	cout << "---------------|----------------------------------------------------|---------------|" << endl;

	cout << left << setw(15) << "C-01" << "|" << setw(52) << "Basics of programming 1" << "|" << setw(15) << "%100" << "|" << endl;
	cout << left << setw(15) << "C-02" << "|" << setw(52) << "Algoritms & Problem Solving 1" << "|" << setw(15) << "%100" << "|" << endl;
	cout << left << setw(15) << "C-03" << "|" << setw(52) << "Programming using C++ 1" << "|" << setw(15) << "%100" << "|" << endl;
	cout << left << setw(15) << "C-04" << "|" << setw(52) << "Algoritms & Problem Solving 1 Advanced Solutions" << "|" << setw(15) << "%100" << "|" << endl;
	cout << left << setw(15) << "C-05" << "|" << setw(52) << "Algoritms & Problem Solving 2" << "|" << setw(15) << "%100" << "|" << endl;
	cout << left << setw(15) << "C-06" << "|" << setw(52) << "Introduction to programming using C++ 2" << "|" << setw(15) << "%44" << "|" << endl;
}

int main()
{
	//cout << "---------|--------------------------------|---------| " << endl;
	//cout << "  Code   |           Name                 |  Mark   | " << endl;
	//cout << "---------|--------------------------------|---------| " << endl;

	//cout << setw(9) << "C101" << "|" << setw(32) << "introduction to Programming 1" << "|" << setw(9) << "95" << "|" << endl;
	//cout << setw(9) << "C102" << "|" << setw(32) << "Computer Hardware" << "|" << setw(9) << "88" << "|" << endl;
	//cout << setw(9) << "C103" << "|" << setw(32) << "Network" << "|" << setw(9) << "75" << "|" << endl;

	//cout << "---------|--------------------------------|---------| " << endl;

	RoadmapProgress();
	
	return 0;
}