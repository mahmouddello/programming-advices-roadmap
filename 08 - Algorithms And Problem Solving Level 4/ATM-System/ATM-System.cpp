#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "../mylibs/headers/string_utils.h";

using namespace std;

const string filePath = "./clients.txt";

struct stClient
{
	string accountNumber = "";
	string pinCode = "";
	string name = "";
	string phone = "";
	double accountBalance = 0.0;
	bool markForDelete = false;
};

const enum enATMMenuOptions
{
	eQuickWithdraw = 1,
	eNormalWithdraw = 2,
	eDeposit = 3,
	eCheckBalance = 4,
	eLogout = 5
};

const enum enQuickWithdrawOptions
{
	e20 = 1,
	e50 = 2,
	e100 = 3,
	e200 = 4,
	e400 = 5,
	e600 = 6,
	e800 = 7,
	e1000 = 8,
	eExit = 9
};

vector<stClient> loadClientsData(const string&);
stClient convertLineToRecord(const string&, const string&);
string convertRecordToLine(const stClient&, const string&);
void showLoginScreen();
string readAccountNumber();
string readPinCode();
bool findClientByAccountNumberAndPinCode(const string&, const string&, stClient&);
void saveClientsDataToFile(const string&, const vector<stClient>&);
bool loadClientAccount(const string&, const string&);
void showATMMainMenu();
short readUserOption(const short&, const short&);
void goToATMMenu();
void peformATMMenuOption(const enATMMenuOptions&);
void checkBalanceScreen();
double getClientBalance();
void showQuickWithdrawMenu();
void performQuickWithdrawMenuOption(const enQuickWithdrawOptions&);
bool isBalanceSufficient(const double&);
void quickWithdrawAmount(const double&);
void showNormalWithdrawAmountScreen();
void withdrawAmount(double, bool = false);
bool confirmAction();
bool isAmountMutiplyOfFive(const int& amount);
void depositAmountScreen();
void depositAmount(const double&);


// global variables
vector<stClient> vClients = loadClientsData(filePath);
stClient currentClient;

vector<stClient> loadClientsData(const string& filePath)
{
	vector<stClient> vClientsData;
	string line;

	fstream file;
	file.open(filePath, ios::in);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			vClientsData.push_back(convertLineToRecord(line, "#//#"));
		}

		file.close();
	}

	return vClientsData;
}

stClient convertLineToRecord(const string& line, const string& delimiter)
{
	vector<string> vTemp = string_utils::splitString(line, delimiter);
	stClient client;

	client.accountNumber = vTemp[0];
	client.pinCode = vTemp[1];
	client.name = vTemp[2];
	client.phone = vTemp[3];
	client.accountBalance = stod(vTemp[4]);

	return client;
}

string convertRecordToLine(const stClient& client, const string& delimiter)
{
	string strClientRecord = "";

	strClientRecord += client.accountNumber + delimiter;
	strClientRecord += client.pinCode + delimiter;
	strClientRecord += client.name + delimiter;
	strClientRecord += client.phone + delimiter;
	strClientRecord += to_string(client.accountBalance);

	return strClientRecord;
}

string readAccountNumber()
{
	string accountNumber = "";

	cout << "Enter your account number: ";
	getline(cin >> ws, accountNumber);

	return accountNumber;
}

string readPinCode()
{
	string pinCode = "";

	cout << "Enter your pincode: ";
	getline(cin >> ws, pinCode);

	return pinCode;
}

void showLoginScreen()
{
	bool loginFailed = false;
	string accountNumber, pinCode;

	do
	{
		system("cls");

		cout << "=====================================\n";
		cout << "       " << "Login Screen\n";
		cout << "=====================================\n";

		if (loginFailed)
			cout << "Invalid Account Number / Pincode!" << endl;

		accountNumber = readAccountNumber();
		pinCode = readPinCode();

		loginFailed = !loadClientAccount(accountNumber, pinCode);

	} while (loginFailed);

	showATMMainMenu();
}

bool findClientByAccountNumberAndPinCode(const string& accountNumber, const string& pinCode, stClient& client)
{
	for (const stClient& c : vClients)
	{
		if (c.accountNumber == accountNumber && c.pinCode == pinCode)
		{
			client = c;
			return true;
		}
	}

	return false;
}

void saveClientsDataToFile(const string& filePath, const vector<stClient>& vClients)
{
	fstream myFile;
	myFile.open(filePath, ios::out);//overwrite
	string dataLine;

	if (myFile.is_open())
	{
		for (stClient c : vClients)
		{
			if (c.markForDelete == false)
			{
				//we only write records that are not marked for delete.
				dataLine = convertRecordToLine(c, "#//#");
				myFile << dataLine << endl;
			}
		}

		myFile.close();
	}
}

bool loadClientAccount(const string& accountNumber, const string& pinCode)
{
	if (findClientByAccountNumberAndPinCode(accountNumber, pinCode, currentClient))
		return true;
	
	return false;
}

void showATMMainMenu()
{
	system("cls");
	
	cout << "=====================================\n";
	cout << "       " << "ATM Main Menu Screen\n";
	cout << "=====================================\n";

	cout << "     " << "[1] Quick Withdraw\n";
	cout << "     " << "[2] Normal Withdraw\n";
	cout << "     " << "[3] Deposit\n";
	cout << "     " << "[4] Check Balance\n";
	cout << "     " << "[5] Logout\n";
	cout << "=====================================\n";

	short userOption = readUserOption(1, 5);
	peformATMMenuOption(enATMMenuOptions(userOption));
}

short readUserOption(const short& from, const short& to)
{
	short option;
	cout << "Choose what you want to do [" << from << "-" << to << "]: ";
	cin >> option;

	return option;
}

void goToATMMenu()
{
	cout << "\nPress any key to return to ATM Main Menu...";
	system("pause > 0");
	showATMMainMenu();
}

void peformATMMenuOption(const enATMMenuOptions& userOption)
{
	switch (userOption)
	{
	case enATMMenuOptions::eQuickWithdraw:
	{
		system("cls");
		showQuickWithdrawMenu();
		goToATMMenu();
		break;
	}
	case enATMMenuOptions::eNormalWithdraw:
	{
		system("cls");
		showNormalWithdrawAmountScreen();
		goToATMMenu();
		break;
	}
	case enATMMenuOptions::eDeposit:
	{
		system("cls");
		depositAmountScreen();
		goToATMMenu();
		break;
	}
	case enATMMenuOptions::eCheckBalance:
	{
		system("cls");
		checkBalanceScreen();
		goToATMMenu();
		break;
	}
	case enATMMenuOptions::eLogout:
	{
		showLoginScreen();
		break;
	}
	default:
		showATMMainMenu();
		break;
	}
}

void checkBalanceScreen()
{
	cout << "=====================================\n";
	cout << "       " << "Check Balance Screen\n";
	cout << "=====================================\n";

	cout << "\nYour account balance is: " << getClientBalance() << endl;
}

double getClientBalance()
{
	return currentClient.accountBalance;
}

void showQuickWithdrawMenu()
{
	cout << "=====================================\n";
	cout << "       " << "Quick Withdraw Menu\n";
	cout << "=====================================\n";

	cout << "     " << "[1] 20";
	cout << "      " << "[2] 50\n";
	cout << "     " << "[3] 100";
	cout << "     " << "[4] 200\n";
	cout << "     " << "[5] 400";
	cout << "     " << "[6] 600\n";
	cout << "     " << "[7] 800";
	cout << "     " << "[8] 1000\n";
	cout << "     " << "[9] Exit\n";
	cout << "=====================================\n";

	cout << "Your account balance is: " << getClientBalance() << endl;

	short userOption = readUserOption(1, 9);
	performQuickWithdrawMenuOption(enQuickWithdrawOptions(userOption));
}

void performQuickWithdrawMenuOption(const enQuickWithdrawOptions& userOption)
{
	switch (userOption)
	{
	case enQuickWithdrawOptions::e20:
	{
		quickWithdrawAmount(20);
		goToATMMenu();
		break;
	}
	case enQuickWithdrawOptions::e50:
	{
		quickWithdrawAmount(50);
		goToATMMenu();
		break;
	}
	case enQuickWithdrawOptions::e100:
	{
		quickWithdrawAmount(100);
		goToATMMenu();
		break;
	}
	case enQuickWithdrawOptions::e200:
	{
		quickWithdrawAmount(200);
		goToATMMenu();
		break;
	}
	case enQuickWithdrawOptions::e400:
	{
		quickWithdrawAmount(400);
		goToATMMenu();
		break;
	}
	case enQuickWithdrawOptions::e600:
	{
		quickWithdrawAmount(600);
		goToATMMenu();
		break;
	}
	case enQuickWithdrawOptions::e800:
	{
		quickWithdrawAmount(800);
		goToATMMenu();
		break;
	}
	case enQuickWithdrawOptions::e1000:
	{
		quickWithdrawAmount(1000);
		goToATMMenu();
		break;
	}
	case enQuickWithdrawOptions::eExit:
	{
		showATMMainMenu();
		break;
	}
	default:
		showATMMainMenu();
		break;
	}
}

bool isBalanceSufficient(const double& amount)
{
	return getClientBalance() >= amount;
}

void quickWithdrawAmount(const double& amount)
{
	withdrawAmount(amount, true);
}

void showNormalWithdrawAmountScreen()
{
	double amount = 0.0;
	bool isSufficient = false;
	bool isMultipleOfFive = false;

	do
	{
		system("cls");

		cout << "=====================================\n";
		cout << "       " << "Withdraw Menu\n";
		cout << "=====================================\n";

		cout << "\nYour account balance is: " << getClientBalance() << endl;
		cout << "\nEnter an amount of multiple of 5's: ";
		cin >> amount;

		isSufficient = isBalanceSufficient(amount);
		isMultipleOfFive = isAmountMutiplyOfFive(amount);

		if (!isMultipleOfFive)
			cout << "\nEntered amount is not mutiple of 5!" << endl;

		if (!isSufficient)
			cout << "\nInsufficient balance, try another amount!\n" << endl;

		if (!isSufficient || !isMultipleOfFive)
			system("pause");

	} while (!isSufficient || !isMultipleOfFive);

	withdrawAmount(amount);
}

void withdrawAmount(double amount, bool isQuickWithdraw)
{
	
	if (!isBalanceSufficient(amount))
	{
		cout << "Insufficient balance, try another option!" << endl;
		return;
	}

	for (stClient& c : vClients)
	{
		if (c.accountNumber == currentClient.accountNumber)
		{
			cout << "\nAre you sure you want to withdraw this amount? y / n: ";

			if (confirmAction())
			{
				c.accountBalance -= amount;
				saveClientsDataToFile(filePath, vClients);

				loadClientAccount(c.accountNumber, c.pinCode); // refresh
				cout << "\nDone..., New balance is: " << getClientBalance() << endl;
			}

			break; // for loop
		}
	}
}

bool confirmAction()
{
	char c = 'n';
	cin >> c;

	return tolower(c) == 'y';
}

bool isAmountMutiplyOfFive(const int& amount)
{
	return amount % 5 == 0;
}

void depositAmountScreen()
{
	double amount = 0.0;
	bool isMultipleOfFive = true;

	do {
		system("cls");

		cout << "=====================================\n";
		cout << "       " << "Deposit Amount Screen\n";
		cout << "=====================================\n";

		cout << "\nYour account balance is: " << getClientBalance() << endl;
		cout << "\nEnter an amount of multiple of 5's: ";
		cin >> amount;

		isMultipleOfFive = isAmountMutiplyOfFive(amount);

		if (!isMultipleOfFive)
		{
			cout << "The amount you entered is not acceptable by ATM! Only amounts that are multiple of 5 is allowed.";
			system("pause > 0");
		}
		

	} while (!isMultipleOfFive);

	depositAmount(amount);
}

void depositAmount(const double& amount)
{
	for (stClient& c : vClients)
	{
		if (c.accountNumber == currentClient.accountNumber)
		{
			cout << "\nAre you sure you want to deposit this amount? y / n: ";

			if (confirmAction())
			{
				c.accountBalance += amount;
				saveClientsDataToFile(filePath, vClients);

				loadClientAccount(c.accountNumber, c.pinCode); // refresh
				cout << "\nDone..., New balance is: " << getClientBalance() << endl;
			}

			break; // for loop
		}
	}
}

int main()
{
	showLoginScreen();
	return 0;
}