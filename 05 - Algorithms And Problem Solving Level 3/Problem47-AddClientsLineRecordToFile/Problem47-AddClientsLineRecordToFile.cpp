#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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

bool readMore()
{
	char c;

	cout << "Do you want to add more clients? 'y' or 'n': " << endl;
	cin >> c;

	cin.ignore(1, '\n');
	
	return tolower(c) == 'y';
}

void clearScreen()
{
	system("cls");
}

string convertRecordToLine(stClientData Client, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.accountNumber + Seperator;
	stClientRecord += Client.pinCode + Seperator;
	stClientRecord += Client.name + Seperator;
	stClientRecord += Client.phoneNumber + Seperator;
	stClientRecord += to_string(Client.accountBalance);

	return stClientRecord;
}

vector<stClientData> readClients()
{
	stClientData client;
	vector<stClientData> vData;
	
	do {

		
		clearScreen();
		cout << "Adding new Data\n\n" << endl;
		
		client = readClientData();

		vData.push_back(client);

	} while (readMore());

	return vData;
}

void saveDataToFile(const vector<stClientData> vData, string delim)
{
	string tempStr = "";
	fstream file;
	file.open("records.txt", ios::app | ios::out);

	if (file.is_open())
	{
		for (const stClientData& vInnerVector : vData)
		{
			tempStr = convertRecordToLine(vInnerVector);

			file << tempStr << endl;
			tempStr = "";
		}
	}
	
	file.close();
}

int main()
{
	vector<stClientData> vData = readClients();

	saveDataToFile(vData, "#//#");

	return 0;
}