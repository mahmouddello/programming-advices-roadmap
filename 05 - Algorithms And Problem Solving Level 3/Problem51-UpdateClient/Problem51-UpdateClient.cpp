#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "D:/MyCPP_Libs/stringUtils.h";

using namespace std;

const string fileName = "records.txt";

struct stClient
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance = 0.0;
    bool markForUpdate = false;
};

void printClientCard(const stClient& client)
{
    cout << "\nThe following client details:\n";

    cout << "Account Number: " << client.accountNumber << endl;
    cout << "Pin Code: " << client.pinCode << endl;
    cout << "Name: " << client.name << endl;
    cout << "Phone Number: " << client.phone << endl;
    cout << "Account Balance: " << client.accountBalance << endl;

}

void updateClientData(stClient& data)
{

    cin.ignore(1, '\n');
    cout << "Enter pin code: ";
    getline(cin, data.pinCode);

    cout << "Enter name: ";
    getline(cin, data.name);

    cout << "Enter phone number: ";
    getline(cin, data.phone);

    cout << "Enter account balance: ";
    cin >> data.accountBalance;
    while (cin.fail())
    {
        // user didn't input a number
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Please enter a valid value for account balance: " << endl;
        cin >> data.accountBalance;
    }
}

string readAccountNumber()
{
    string accNum = "";

    cout << "Please enter the account number of client: ";
    cin >> accNum;

    return accNum;
}

string convertRecordToLine(const stClient& client, string seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += client.accountNumber + seperator;
    stClientRecord += client.pinCode + seperator;
    stClientRecord += client.name + seperator;
    stClientRecord += client.phone + seperator;
    stClientRecord += to_string(client.accountBalance);

    return stClientRecord;
}

stClient converLineToRecord(const string& line, string seperator = "#//#")
{
    stClient client;
    vector<string> vClientData;

    vClientData = stringUtils::splitString(line, seperator);
    client.accountNumber = vClientData[0];
    client.pinCode = vClientData[1];
    client.name = vClientData[2];
    client.phone = vClientData[3];
    client.accountBalance = stod(vClientData[4]); // cast string to double 

    return client;
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

vector<stClient> loadCleintsDataFromFile(const string& filePath)
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

void updateClientByAccountNumber(vector<stClient>& vClients, string accountNumber)
{
    stClient clientToUpdate = findClientByAccountNumber(vClients, accountNumber);
    char answer = 'n';

    if (clientToUpdate.accountNumber != "")
    {
        printClientCard(clientToUpdate);

        cout << "Do you want to update this client? 'y' or 'n': ";
        cin >> answer;

        if (tolower(answer) == 'y')
        {
            for (stClient& client : vClients)
            {
                if (client.accountNumber == clientToUpdate.accountNumber)
                {
                    updateClientData(client);
                    break;
                }
            }

            vector<string> vClientsString = convertAllRecordsToLine(vClients);
            saveVectorToFile(vClientsString);

            cout << "Client updated successfully!" << endl;
        }
    }

    else
    {
        cout << "Client with account number (" << accountNumber << ") hasn't been found!" << endl;
    }
}

int main()
{
    vector<stClient> vCleints = loadCleintsDataFromFile(fileName);
    string accNum = readAccountNumber();

    updateClientByAccountNumber(vCleints, accNum);

    return 0;
}