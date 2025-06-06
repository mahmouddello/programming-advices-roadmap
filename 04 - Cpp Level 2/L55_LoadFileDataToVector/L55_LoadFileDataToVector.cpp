#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void LoadDataFromFileToVector(string filePath, vector<string>&  vFileContent)
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

int main()
{
    vector<string> vFileContent;
    string filePath = "C:/Users/Showtime/Desktop/Playground/PlayFile.txt";

    LoadDataFromFileToVector(filePath, vFileContent);

    for (string& line : vFileContent)
    {
        cout << line << endl;
    }

    return 0;
}
