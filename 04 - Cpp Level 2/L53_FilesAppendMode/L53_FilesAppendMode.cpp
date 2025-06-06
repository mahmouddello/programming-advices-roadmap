#include <iostream>
#include <fstream>

using namespace std;

int main() {

	fstream MyFile;

	/*
		Append Mode: Keeps our old data in the file, and adds new data
		to the end of the file.
	*/

	/*
		Here our code says, open MyFile.txt in append mode, 
		if not exists create and open for write mode. In next time,
		the file will open in append mode, append always has priority over write
	*/


	MyFile.open("MyFileAppend.txt", ios::out | ios::app ); // write mode

	if (MyFile.is_open())
	{
		MyFile << "Mahmoud\n";
		MyFile << "Fadi\n";
		MyFile << "Lama\n";
		MyFile.close(); // it is necessary to close files
	}

	return 0;
}