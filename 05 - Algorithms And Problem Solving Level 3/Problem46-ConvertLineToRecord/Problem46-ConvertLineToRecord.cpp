#include <iostream>
#include <vector>
#include <string>
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

stClientData convertLinetoRecord(string s1, string delimiter)
{
	vector<string> vTemp = string_utils::splitString(s1, delimiter);

	stClientData data;

	data.accountNumber = vTemp[0];
	data.pinCode = vTemp[1];
	data.name = vTemp[2];
	data.phoneNumber = vTemp[3];
	data.accountBalance = stod(vTemp[4]);
	
	return data;
}

void printDataRecord(const stClientData& data)
{
	cout << "\nThe following is extracted client data:\n";

	cout << "Account number: " << data.accountNumber << endl;
	cout << "Pin code: " << data.pinCode << endl;
	cout << "Name: " << data.name << endl;
	cout << "Phone number:" << data.phoneNumber << endl;
	cout << "Account balance: " << data.accountBalance << endl;
}

int main()
{
	string lineData = "A150#//#1234#//#Mahmoud Dello#//#561729872#//#15000.000000";

	cout << "Line record is:\n" << lineData << endl;

	stClientData clientData = convertLinetoRecord(lineData, "#//#");

	printDataRecord(clientData);

	return 0;
}