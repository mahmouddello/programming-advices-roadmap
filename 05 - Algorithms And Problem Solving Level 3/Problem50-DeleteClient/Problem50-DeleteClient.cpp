#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "D:/MyCPP_Libs/headers/string_utils.h"

using namespace std;

const string fileName = "records.txt";

struct stClient
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
};

string readAccountNumber()
{
    string accNum = "";

    cout << "Please enter the account number of client: ";
    cin >> accNum;

    return accNum;
}

string convertRecordToLine(stClient client, string seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += client.accountNumber + seperator;
    stClientRecord += client.pinCode + seperator;
    stClientRecord += client.name + seperator;
    stClientRecord += client.phone + seperator;
    stClientRecord += to_string(client.accountBalance);

    return stClientRecord;
}

vector<string> convertAllRecordsToLine(vector<stClient> vRecords)
{
    vector<string> vClientsString;
    
    for (stClient record : vRecords)
    {
        vClientsString.push_back(convertRecordToLine(record));
    }

    return vClientsString;
}

stClient converLineToRecord(string line, string seperator = "#//#")
{
    stClient client;
    vector<string> vClientData;

    vClientData = string_utils::splitString(line, seperator);
    client.accountNumber = vClientData[0];
    client.pinCode = vClientData[1];
    client.name = vClientData[2];
    client.phone = vClientData[3];
    client.accountBalance = stod(vClientData[4]); // cast string to double 

    return client;
}

vector<stClient> loadCleintsDataFromFile(string filePath)
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

stClient findClientByAccountNumber(const vector<stClient>& vData, const string& inputAccNum)
{

    for (stClient client : vData)
    {
        if (client.accountNumber == inputAccNum)
            return client;
    }

    // Return a "not found" dummy client
    return { "", "", "", "", 0.0 };
}

void printClientCard(const stClient& client)
{
    cout << "\nThe following client details:\n";

    cout << "Account Number: " << client.accountNumber << endl;
    cout << "Pin Code: " << client.pinCode << endl;
    cout << "Name: " << client.name << endl;
    cout << "Phone Number: " << client.phone << endl;
    cout << "Account Balance: " << client.accountBalance << endl;

}

void saveVectorToFile(vector<string> vectorToSave)
{
    fstream file;
    file.open(fileName, ios::out);

    if (file.is_open())
    {
        for (string line : vectorToSave)
        {
            if (line != "")
                file << line << endl;
        }

        file.close();
    }
}

void deleteClient(const vector<stClient>& vClients, const stClient& client)
{
    vector<string> vClientsString = convertAllRecordsToLine(vClients);

    for (string& line : vClientsString)
        if (line == convertRecordToLine(client))
        {
            line.clear();
        }

    saveVectorToFile(vClientsString);
    
}

int main()
{
    vector<stClient> vClients = loadCleintsDataFromFile(fileName);
    string accNum = readAccountNumber();
    
    stClient client = findClientByAccountNumber(vClients, accNum);
    char choice;

    if (client.accountNumber != "")
    {
        printClientCard(client);

        cout << "Are you sure you want to delete this client? 'y' or 'n'";
        cin >> choice;

        if (tolower(choice) == 'y')
            deleteClient(vClients, client);
    }

    else
    {
        cout << "\nA client with account number of (" << accNum << ") is not found!" << endl;
    }

    return 0;
}