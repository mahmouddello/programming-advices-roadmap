#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

void LoadDataFromFileToVector(string filePath, vector<string>& vFileContent)
{
	fstream file;
	file.open(filePath, ios::in); // read mode

	if (!file)
	{
		cout << "Invalid path or file doesn't exist!";
		return;
	}

	string line;

	while (getline(file, line))
	{
		vFileContent.push_back(line);
	}

	file.close();
}

void SaveVectorToFile(string fileName, vector<string> vFileContent)
{
	fstream file;
	file.open(fileName, ios::out); // write mode

	if (file.is_open())
	{
		for (string& line : vFileContent)
		{
			if (line != "")
			{
				file << line << endl;
			}
		}
	}
	file.close();
}

void DeleteRecordFromFile(string fileName, string record)
{
	vector<string> vFileContent;
	LoadDataFromFileToVector("PlayFile.txt", vFileContent);

	for (string& line : vFileContent)
	{
		if (line == record)
		{
			line = "";
		}
	}

	SaveVectorToFile("PlayFile.txt", vFileContent);
}

int main() {
	
	cout << "FILE CONTENT:\n" << endl;
	PrintFileContent("PlayFile.txt");

	DeleteRecordFromFile("PlayFilet.txt", "Ali");

	cout << "\nUPDATED FILE CONTENT:\n" << endl;
	PrintFileContent("PlayFile.txt");

	return 0;
}