#include <iostream>
#include <fstream>
#include <string>

#include "D:/MyCPP_Libs/FileLib.h"

using namespace std;

void PrintFileContent(string FileName)
{
	fstream MyFile;

	MyFile.open(FileName, ios::in); // read mode

	if (MyFile.is_open())
	{
		string line;
		
		// getting each line got returns, assigns it to line
		// we used this function previously 
		while (getline(MyFile, line))
		{
			cout << line << endl;
		}

		MyFile.close();
	}
}

int main() {

	FileLib::printFileContent("MyFileAppend.txt");

	return 0;
}