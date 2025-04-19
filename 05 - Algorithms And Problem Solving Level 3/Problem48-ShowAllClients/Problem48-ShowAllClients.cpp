#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
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

vector<string> loadDataToVector(string filePath)
{
	fstream file;
	vector<string> vClientsData;
	string line;

	file.open(filePath, ios::in);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			vClientsData.push_back(line);
		}

		file.close();
	}

	return vClientsData;
}

void PrintClientData(vector<string> vData)
{
	cout << "                           Client list (" << vData.size() << ") client(s).                   " << endl;
	cout << "--------------------------------------------------"
		<< "---------------------------------------------------"
		<< endl;

	cout << left
		<< "| " << setw(15) << "Account Number "
		<< "| " << setw(10) << "Pin Code "
		<< "| " << setw(30) << "Client Name "
		<< "| " << setw(20) << "Phone Number "
		<< "| " << setw(15) << "Balance " << "|" 
		<< endl;

	cout << "--------------------------------------------------"
		<< "---------------------------------------------------"
		<< endl;


	stClientData client;
	
	for (const string& clientData : vData)
	{
		client = convertLinetoRecord(clientData, "#//#");
		cout << left
			<< "| " << setw(15) << client.accountNumber
			<< "| " << setw(10) << client.pinCode
			<< "| " << setw(30) << client.name
			<< "| " << setw(20) << client.phoneNumber
			<< "| " << setw(15) << client.accountBalance
			<< "| " << endl;
	}
}

int main()
{

	vector<string> vClients = loadDataToVector("./records.txt");

	PrintClientData(vClients);

	return 0;
}