#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

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

int main()
{
    vector<string> vFileContent{ "Ali", "Mahmoud", "Anas", "Lama" };
    string fileName = "MyFile.txt";

    SaveVectorToFile(fileName, vFileContent);

    return 0;
}
