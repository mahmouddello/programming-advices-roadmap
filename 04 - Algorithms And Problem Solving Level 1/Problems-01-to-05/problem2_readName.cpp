#include <iostream>
#include <string>
#include "problem2_readName.h"

using namespace std;

string ReadName()
{
	string name;

	cout << "Please enter your name: ";
	getline(cin, name);

	return name;

}
