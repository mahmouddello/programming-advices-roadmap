#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "D:/MyCPP_Libs/stringUtils.h";

using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

stClient converLineToRecord(string Line, string Seperator = "#//#")
{
    stClient Client;
    vector<string> vClientData;
    vClientData = stringUtils::splitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // cast string to double 

    return Client;
}

vector<stClient> LoadCleintsDataFromFile(string filePath)
{
    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(filePath, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = converLineToRecord(Line);
            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

stClient findClientByAccountNumber(const vector<stClient>& vData, string inputAccNum)
{

    for (stClient client : vData)
    {
        if (client.AccountNumber == inputAccNum)
            return client;
    }

    // Return a "not found" dummy client
    return { "", "", "", "", 0.0 };
}

int main()
{
    vector<stClient> vAllData = LoadCleintsDataFromFile("./records.txt");
    string accNumber = stringUtils::readString("Please enter accout number: ");

    stClient client = findClientByAccountNumber(vAllData, accNumber);

    if (client.AccountNumber != "")
    {
        cout << "\nThe following client details:\n";

        cout << "Account Number: " << client.AccountNumber << endl;
        cout << "Pin Code: " << client.PinCode << endl;
        cout << "Name: " << client.Name << endl;
        cout << "Phone Number: " << client.Phone << endl;
        cout << "Account Balance: " << client.AccountBalance << endl;
    }

    else
    {
        cout << "\nClient with accout number (" << accNumber << ") not found!" << endl;
    } 

    return 0;
}