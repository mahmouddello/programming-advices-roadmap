#include <iostream>
using namespace std;

void HomeworkPart1()
{
	// Represnt logical expressions in C++

	cout << (12 >= 12) << endl;
	cout << (12 > 7) << endl;
	cout << (8 < 6) << endl;
	cout << (8 == 8) << endl; 
	cout << (12 <= 12) << endl;
	cout << (7 == 5) << endl;
	cout << "-----------------\n" << endl;

	cout << !(12 >= 12) << endl;
	cout << !(12 > 7) << endl;
	cout << !(8 < 6) << endl;
	cout << !(8 == 8) << endl;
	cout << !(12 <= 12) << endl;
	cout << !(7 == 5) << endl;
	cout << "-----------------\n" << endl;

	cout << (1 && 1) << endl;
	cout << (1 && 0) << endl;
	cout << (0 || 1) << endl; 
	cout << (0 || 0) << endl;
	cout << !(0) << endl;
	cout << !(1 || 0) << endl;
	cout << "-----------------\n" << endl;

	cout << ((7 == 7) && (7 > 5)) << endl;
	cout << ((7 == 7) && (7 < 5)) << endl;
	cout << ((7 == 7) || (7 < 5)) << endl;
	cout << ((7 < 7) || (7 > 5)) << endl;
	cout << (!(7 == 7) && (7 > 5)) << endl;
	cout << ((7 == 7) && !(7 < 5)) << endl;

}
void HomeworkPart2()
{

	cout << (((5 > 6) && (7 == 7)) || (1 || 1)) << endl;
	cout << (!((5 > 6) && (7 == 7)) || (1 || 1)) << endl;
	cout << (!((5 > 6) && (7 == 7)) || !(1 || 1)) << endl;
	cout << (!((5 > 6) || (7 == 7)) || !(1 || 1)) << endl;
	cout << ((((5 > 6) && (7 <= 8)) || (((8 > 1) || (4 <= 3)))) && true) << endl;


}

int main()
{
	//bool a = 1, b = 0;

	//cout << (a && b) << endl; // 1 AND 0 -> 0
	//cout << (a || b) << endl; // 1 OR 0 -> 1

	//cout << !a << endl; // NOT 1 -> 0
	//cout << !b << endl; // NOT 0 -> 1

	//cout << !(a && b) << endl; // NOT (1 AND 0) -> NOT (0) -> 1
	//cout << !(a || b) << endl; // NOT (1 OR 0) -> NOT (1) -> 0

	HomeworkPart2();

	return 0;
}
