#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "D:/MyCPP_Libs/headers/string_utils.h"

using namespace std;

struct stClientData
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	double accountBalance;
};

stClientData readClientData()
{
	stClientData data;
	
	cout << "Please enter client data:\n" << endl;

	cout << "Enter account number: ";
	getline(cin, data.accountNumber);	
	
	cout << "Enter pin code: ";
	getline(cin, data.pinCode);

	cout << "Enter name: ";
	getline(cin, data.name);
		
	cout << "Enter phone number: ";
	getline(cin, data.phoneNumber);

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

	return data;
}

vector<string> loadDataToVector(const stClientData& data)
{
	vector<string> vTemp;

	vTemp.push_back(data.accountNumber);
	vTemp.push_back(data.pinCode);
	vTemp.push_back(data.name);
	vTemp.push_back(data.phoneNumber);
	vTemp.push_back(to_string(data.accountBalance));

	return vTemp;
}

string ConvertRecordToLine(stClientData Client, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.accountNumber + Seperator;
	stClientRecord += Client.pinCode + Seperator;
	stClientRecord += Client.name + Seperator;
	stClientRecord += Client.phoneNumber + Seperator;
	stClientRecord += to_string(Client.accountBalance);

	return stClientRecord;
}

int main()
{
	stClientData clientData = readClientData();

	vector<string> vData = loadDataToVector(clientData);

	cout << "\n\nClient record for saving is:\n"; 
	cout << string_utils::joinString(vData, "#//#") << endl;

	return 0;
}
