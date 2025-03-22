#include <iostream>
#include <fstream>

using namespace std;

int main() {

	fstream MyFile;

	/*
		Write Mode: Erases old data in a file and replace them with
		the new lines or data. 
	*/

	MyFile.open("MyFile.txt", ios::out); // write mode

	if (MyFile.is_open())
	{
		MyFile << "Hello, this is the first line\n";
		MyFile << "Hello, this is the second line\n";
		MyFile << "Hello, this is the third line\n";

		MyFile.close(); // it is necessary to close files
	}

	return 0;
}