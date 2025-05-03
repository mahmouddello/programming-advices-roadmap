#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "D:/MyCPP_Libs/headers/string_utils.h";


using namespace std;

// global constants
const string clientsFileName = "bankClients.txt";
const string usersFileName = "users.txt";

const enum enMainMenuOption {
	eShowAllClients = 1,
	eAddNewClient = 2,
	eDeleteClient = 3,
	eUpdateClient = 4,
	eFindClient = 5,
	eTransactionsMenu = 6,
	eManageUsersMenu = 7,
	eLogout = 8,
};

const enum enTransactionMenuOption
{
	eDeposit = 1,
	eWithdraw = 2,
	eTotalBalance = 3,
	eBackToMainMenu = 4
};

const enum enManageUsersMenuOption
{
	eMShowAllUsers = 1,
	eMAddNewUser = 2,
	eMDeleteUser = 3,
	eMUpdateUser = 4,
	eMFindUser = 5,
	eMMainMenu = 6
};

const short permissionsArr[] = {1, 2, 4, 8, 16, 32, 64};

struct stClient
{
	string accountNumber = "";
	string pinCode = "";
	string name = "";
	string phone = "";
	double accountBalance = 0.0;
	bool markForDelete = false;
};

struct stUser
{
	string username = "";
	string password = "";
	short permission = 0;
	bool markForDelete = false;
};

// declaration

// Bank V1
void showMainMenu();
void goBackToMainMenu();
unsigned short readUserOption(const short&, const short&);
vector<stClient> loadClientsData(const string&);
stClient convertLineToClientRecord(const string&, const string&);
string convertClientRecordToLine(const stClient&, const string&);
string readAccountNumber();
bool findClientByAccountNumber(const string&, stClient& client);
void findClientScreen();
void printClientDetails(const stClient&);
void addClientScreen();
void addNewClient();
void saveClientsDataToFile(const string&, const vector<stClient>&);
void deleteClientScreen();
void deleteClientByAccountNumber(const string&);
void updateClientScreen();
void updateClientData(const stClient& client);

// Extension V2
void showTransactionMenu();
void performTransactionMenuOption(const enTransactionMenuOption&);
void goBackToTransactionsMenu();
void depositAmountScreen();
void depositAmountToClient(const stClient& client);
void withdrawAmountScreen();
void withdrawAmountFromClient(const stClient& client);

// Extension V3
vector<stUser> loadUsersData(const string&);
stUser convertLineToUserRecord(const string&, const string&);
string convertUserRecordToLine(const stUser&, const string&);
void showLoginScreen();
string readUsername();
string readPassword();
bool authenticateLogin(const string&, const string&, stUser&);
void showManageUsersMenu();
void performManageUsersMenuOption(const enManageUsersMenuOption&);
void showAllUsers();
void goBackToManageUsersMenu();
bool userHasPermission(const short&, const short&);
void printUserDetails(const stUser&);
void findUserScreen();
bool findUserByUsername(const string&, stUser&);
stUser readUserDetails();
void addUserScreen();
void addNewUser();
short askUserPermissions();
void saveUserDataToFile(const string&, const vector<stUser>&);
void accessDeniedInfo();
void deleteUserScreen();
void deleteUserByUsername(const stUser&);
void updateUserScreen();
void updateUserByUsername(const stUser&);
void updateUserDetails(stUser&);

// global variables
vector<stClient> g_vClients = loadClientsData(clientsFileName);
vector<stUser> g_vUsers = loadUsersData(usersFileName);
stUser g_currentUser;

// defintions
void showAllClients()
{
	system("cls");

	cout << "                                   ";
	cout << "Clients List (" << g_vClients.size() << ") Client(s)." << endl;
	cout << "---------------------------------------------------";
	cout << "--------------------------------------------------" << endl;

	cout << left
		<< "| " << setw(15) << "Account Number "
		<< "| " << setw(10) << "Pin Code "
		<< "| " << setw(30) << "Client Name "
		<< "| " << setw(20) << "Phone Number "
		<< "| " << setw(15) << "Balance " << "|"
		<< endl;

	cout << "---------------------------------------------------";
	cout << "--------------------------------------------------" << endl;

	if (g_vClients.size() == 0)
	{
		cout << "There are no records of clients in this file!\n" << endl;
		goBackToMainMenu();
	}

	for (const stClient& client : g_vClients)
	{
		cout << left
			<< "| " << setw(15) << client.accountNumber
			<< "| " << setw(10) << client.pinCode
			<< "| " << setw(30) << client.name
			<< "| " << setw(20) << client.phone
			<< "| " << setw(15) << client.accountBalance
			<< "| " << endl;
	}

	cout << "---------------------------------------------------";
	cout << "--------------------------------------------------" << endl;
}

vector<stClient> loadClientsData(const string& clientsFileName)
{
	vector<stClient> vClientsData;
	string line;
	
	fstream file;
	file.open(clientsFileName, ios::in);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			vClientsData.push_back(convertLineToClientRecord(line, "#//#"));
		}

		file.close();
	}

	return vClientsData;
}

stClient convertLineToClientRecord(const string& line, const string& delimiter)
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

string convertClientRecordToLine(const stClient& client, const string& delimiter)
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
	string accNum = "";

	cout << "Please enter the account number of the client: ";
	cin >> accNum;

	return accNum;
}

bool findClientByAccountNumber(const string& accountNumber, stClient& client)
{
	for (const stClient& c : g_vClients)
	{
		if (c.accountNumber == accountNumber)
		{
			client = c;
			return true;
		}
	}

	return false;
}

void findClientScreen()
{
	cout << "=====================================\n";
	cout << "     Find Client Screen" << endl;
	cout << "=====================================\n" << endl;

	string accountNumber = readAccountNumber();
	stClient client;

	if (findClientByAccountNumber(accountNumber, client))
		printClientDetails(client);
	else
		cout << "Client with account number (" << accountNumber << ") not found!" << endl;
}

stClient readClientData()
{
	stClient client;

	cout << "\nPlease enter client data:\n" << endl;
	cin.ignore(1, '\n');

	while (true)
	{
		cout << "Enter account number: ";
		getline(cin >> ws, client.accountNumber);

		if (findClientByAccountNumber(client.accountNumber, client))
		{
			cout << "\nClient with [" << client.accountNumber << "] already exits. Try different one" << endl;
		}
		else
			break;
	}

	cout << "Enter pin code: ";
	getline(cin >> ws, client.pinCode);

	cout << "Enter name: ";
	getline(cin, client.name);

	cout << "Enter phone number: ";
	getline(cin, client.phone);

	cout << "Enter account balance: ";
	cin >> client.accountBalance;

	return client;
}

bool confirmAction()
{
	char c = 'n';
	cin >> c;

	return tolower(c) == 'y';
}

short askUserPermissions()
{
	cout << "Do you want to give this user full access? y / n: ";
	if (confirmAction())
		return -1;

	short permissions = 0;

	cout << "\nView client list? y / n: ";
	if (confirmAction())
		permissions += permissionsArr[0];

	cout << "\nAdd new client? y / n: ";
	if (confirmAction())
		permissions += permissionsArr[1];

	cout << "\nDelete client? y / n: ";
	if (confirmAction())
		permissions += permissionsArr[2];

	cout << "\nUpdate client? y / n: ";
	if (confirmAction())
		permissions += permissionsArr[3];

	cout << "\nFind client? y / n: ";
	if (confirmAction())
		permissions += permissionsArr[4];

	cout << "\nTransactions? y / n: ";
	if (confirmAction())
		permissions += permissionsArr[5];

	cout << "\nManage users? y / n: ";
	if (confirmAction())
		permissions += permissionsArr[6];

	return permissions;
}

void saveClientsDataToFile(const string& clientsFileName, const vector<stClient>& vClients)
{
	fstream myFile;
	myFile.open(clientsFileName, ios::out);//overwrite
	string dataLine;

	if (myFile.is_open())
	{
		for (stClient c : vClients)
		{
			if (c.markForDelete == false)
			{
				//we only write records that are not marked for delete.
				dataLine = convertClientRecordToLine(c, "#//#");
				myFile << dataLine << endl;
			}
		}

		myFile.close();
	}
}

void addNewClient()
{
	cout << "\nAdding new client:" << endl;
	cout << "------------------------" << endl;

	stClient newClient;
	newClient = readClientData();

	g_vClients.push_back(newClient);
	saveClientsDataToFile(clientsFileName, g_vClients);

	cout << "\nClient added sucessfully!" << endl;

	g_vClients = loadClientsData(clientsFileName); // refresh clients
}

void addClientScreen()
{	
	
	system("cls");
	
	cout << "=====================================\n";
	cout << "     Add New Client Screen" << endl;
	cout << "=====================================\n";

	char addMore = 'n';

	do {
		
		addNewClient();
		cout << "\nDo you want to add another client? y / n: ";
		cin >> addMore;

	} while (tolower(addMore) == 'y');
}

void deleteClientByAccountNumber(const string& accountNumber)
{
	for (stClient& c : g_vClients)
	{
		if (c.accountNumber == accountNumber)
		{
			c.markForDelete = true;
			break;
		}
	}

	saveClientsDataToFile(clientsFileName, g_vClients);
	cout << "\nClient deleted sucessfully!" << endl;

	g_vClients = loadClientsData(clientsFileName); // refresh
}

void deleteClientScreen()
{
	
	cout << "=====================================\n";
	cout << "     Delete Client Screen" << endl;
	cout << "=====================================\n" << endl;

	string accountNumber = readAccountNumber();
	stClient client;
	char deleteConfirmation = 'n';

	if (findClientByAccountNumber(accountNumber, client))
	{
		printClientDetails(client);
		
		cout << "\nAre you sure you want to delete this client? y / n: ";
		cin >> deleteConfirmation;

		if (tolower(deleteConfirmation) != 'y')
			return;

		deleteClientByAccountNumber(client.accountNumber);
	}
	else
		cout << "Client with account number [" << accountNumber << "] not found!" << endl;
}

void updateClientData(const stClient& client)
{
	for (stClient& c : g_vClients)
	{
		if (c.accountNumber == client.accountNumber)
		{
			cout << "Enter pin code: ";
			getline(cin >> ws, c.pinCode);

			cout << "Enter name: ";
			getline(cin, c.name);

			cout << "Enter phone number: ";
			getline(cin, c.phone);

			cout << "Enter account balance: ";
			cin >> c.accountBalance;

			break;
		}
	}

	saveClientsDataToFile(clientsFileName, g_vClients);
	cout << "\nClient data updated sucessfully!" << endl;

	g_vClients = loadClientsData(clientsFileName); // refresh
}

void updateClientScreen()
{	
	system("cls");
	cout << "=====================================\n";
	cout << "     Update Client Screen" << endl;
	cout << "=====================================\n" << endl;

	string accountNumber = readAccountNumber();
	stClient client;
	char updateConfirmation = 'n';

	if (findClientByAccountNumber(accountNumber, client))
	{
		printClientDetails(client);

		cout << "\nAre you sure you want to update the info of this client? y / n: ";
		cin >> updateConfirmation;

		if (tolower(updateConfirmation) != 'y')
			return;

		updateClientData(client);
	}
	else
		cout << "\nClient with account number [" << accountNumber << "] not found!" << endl;
}

void printClientDetails(const stClient& client)
{
	cout << "\nThe following client details:\n";

	cout << "---------------------------------" << endl;
	cout << "Account Number: " << client.accountNumber << endl;
	cout << "Pin Code: " << client.pinCode << endl;
	cout << "Name: " << client.name << endl;
	cout << "Phone Number: " << client.phone << endl;
	cout << "Account Balance: " << client.accountBalance << endl;
	cout << "---------------------------------" << endl;

	cout << endl;
}

void depositAmountToClient(const stClient& client)
{
	double amount = 0.0;
	
	for (stClient& c : g_vClients)
	{
		if (c.accountNumber == client.accountNumber)
		{
			cout << "\nEnter amount you want to add: ";
			cin >> amount;

			char confirm = 'n';
			cout << "\nAre you sure you want to deposit this ammount? Y / N: ";
			cin >> confirm;

			if (tolower(confirm) != 'y')
				return;

			c.accountBalance += amount;
			break;
		}
	}

	saveClientsDataToFile(clientsFileName, g_vClients);
	cout << "\nClient's balance updated successfully!" << endl;

	g_vClients = loadClientsData(clientsFileName); // refresh
}

void depositAmountScreen()
{
	cout << "=====================================\n";
	cout << "     Deposit Screen" << endl;
	cout << "=====================================\n" << endl;

	string accountNumber = readAccountNumber();
	stClient client;

	if (findClientByAccountNumber(accountNumber, client))
	{
		printClientDetails(client);
		depositAmountToClient(client);
	}
	else
		cout << "\nClient with account number [" << accountNumber << "] not found!" << endl;
}

void withdrawAmountFromClient(const stClient& client)
{
	double amount = 0.0;
	for (stClient& c : g_vClients)
	{
		if (c.accountNumber == client.accountNumber)
		{
			cout << "\nEnter amount you want to add: ";
			cin >> amount;
			
			while (c.accountBalance < amount)
			{
				cout << "Insufficent balance, try another amount!\n";
				cout << "\nEnter amount you want to add: ";
				cin >> amount;
			}

			c.accountBalance -= amount;
			break;
		}
	}

	saveClientsDataToFile(clientsFileName, g_vClients);
	cout << "\nClient's balance updated successfully!" << endl;

	g_vClients = loadClientsData(clientsFileName); // refresh

}

void withdrawAmountScreen()
{
	cout << "=====================================\n";
	cout << "     Deposit Screen" << endl;
	cout << "=====================================\n" << endl;

	string accountNumber = readAccountNumber();
	stClient client;

	if (findClientByAccountNumber(accountNumber, client))
	{
		printClientDetails(client);
		withdrawAmountFromClient(client);
	}
	else
		cout << "\nClient with account number [" << accountNumber << "] not found!" << endl;
}

double calculateTotalBalance(const vector<stClient>& vClients)
{
	double sum = 0;

	for (const stClient c : vClients)
	{
		sum += c.accountBalance;
	}

	return sum;
}

void showTotalBalance()
{
	showAllClients();
	cout << "\n\nTotal Balance: " << calculateTotalBalance(g_vClients) << endl;
}

void performTransactionMenuOption(const enTransactionMenuOption& menuOption)
{
	switch (menuOption)
	{
		case enTransactionMenuOption::eDeposit:
		{
			system("cls");
			depositAmountScreen();
			goBackToTransactionsMenu();
			break;
		}
		case enTransactionMenuOption::eWithdraw:
		{
			system("cls");
			withdrawAmountScreen();
			goBackToTransactionsMenu();
			break;
		}
		case enTransactionMenuOption::eTotalBalance:
		{
			showTotalBalance();
			goBackToTransactionsMenu();
			break;
		}
		case enTransactionMenuOption::eBackToMainMenu:
		{
			showMainMenu();
			break;
		}
		default:
			break;
	}
}

void goBackToTransactionsMenu()
{
	cout << "Press any key to go back to transactions menu..." << endl;
	system("pause > 0");

	showTransactionMenu();
}

void showTransactionMenu()
{
	system("cls");

	cout << "=====================================\n";
	cout << "       " << "Transactions Screen\n";
	cout << "=====================================\n";
	cout << "     " << "[1] Deposit\n";
	cout << "     " << "[2] Withdraw\n";
	cout << "     " << "[3] Total Balances\n";
	cout << "     " << "[4] Main Menu\n";
	cout << "=====================================\n";

	short option = readUserOption(1, 4);

	performTransactionMenuOption(enTransactionMenuOption(option));

}

void performMainMenuOption(const enMainMenuOption& menuOption)
{
	if (menuOption != 8)
	{
		short requestedAccess = permissionsArr[short(menuOption) - 1];

		if (!userHasPermission(g_currentUser.permission, requestedAccess))
		{
			accessDeniedInfo();
			goBackToMainMenu();
		}
	}

	switch (menuOption)
	{
		case enMainMenuOption::eShowAllClients:
		{
			system("cls");
			showAllClients();
			goBackToMainMenu();
			break;
		}
		case enMainMenuOption::eAddNewClient:
		{
			system("cls");
			addClientScreen();
			goBackToMainMenu();
			break;
		}
		case enMainMenuOption::eDeleteClient:
		{
			system("cls");
			deleteClientScreen();
			goBackToMainMenu();
			break;
		}
		case enMainMenuOption::eUpdateClient:
		{
			system("cls");
			updateClientScreen();
			goBackToMainMenu();
			break;
		}
		case enMainMenuOption::eFindClient:
		{
			system("cls");
			findClientScreen();
			goBackToMainMenu();
			break;
		}
		case enMainMenuOption::eTransactionsMenu:
		{
			system("cls");
			showTransactionMenu();
			break;
		}
		case enMainMenuOption::eManageUsersMenu:
		{	
			system("cls");
			showManageUsersMenu();
			break;
		}
		case enMainMenuOption::eLogout:
		{
			system("cls");
			g_currentUser = { "", "", 0 }; // reset user
			showLoginScreen();
			break;
		}
		default:
			break;
	}

}

unsigned short readUserOption(const short& from, const short& to)
{
	unsigned short option;
	cout << "Choose what you want to do [" << from << "-" << to << "]: ";
	cin >> option;

	return option;
}

vector<stUser> loadUsersData(const string& usersFileName)
{
	fstream file;
	string line;
	vector<stUser> vUsers;
	file.open(usersFileName, ios::in);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			vUsers.push_back(convertLineToUserRecord(line, "#//#"));
		}

		file.close();
	}

	return vUsers;
}

stUser convertLineToUserRecord(const string& line, const string& delimiter)
{
	vector<string> vTemp = string_utils::splitString(line, delimiter);
	stUser user;

	user.username= vTemp[0];
	user.password = vTemp[1];
	user.permission = stod(vTemp[2]);

	return user;
}

string convertUserRecordToLine(const stUser& user, const string& delimiter)
{
	string strUserRecord = "";

	strUserRecord += user.username + delimiter;
	strUserRecord += user.password + delimiter;
	strUserRecord += to_string(user.permission);

	return strUserRecord;
}

void showLoginScreen()
{
	cout << "=====================================\n";
	cout << "       " << "Login Screen\n";
	cout << "=====================================\n";

	string username = readUsername();
	string password = readPassword();

	while (true)
	{
		if (authenticateLogin(username, password, g_currentUser))
			break;
		else
			cout << "\nInvalid Username/Password!" << endl;

		username = readUsername();
		password = readPassword();
	}

	showMainMenu();
}

string readUsername()
{
	string username = "";

	cout << "Please enter your username: ";
	cin >> username;

	return username;
}

string readPassword()
{
	string password = "";

	cout << "Please enter your password: ";
	cin >> password;

	return password;
}

void saveUserDataToFile(const string& usersFileName, const vector<stUser>& vUsers)
{

	fstream myFile;
	myFile.open(usersFileName, ios::out);//overwrite
	string dataLine;

	if (myFile.is_open())
	{
		for (stUser u : vUsers)
		{
			if (u.markForDelete == false)
			{
				//we only write records that are not marked for delete.
				dataLine = convertUserRecordToLine(u, "#//#");
				myFile << dataLine << endl;
			}
		}

		myFile.close();
	}
}

void addNewUser()
{
	stUser user = readUserDetails();
	g_vUsers.push_back(user);

	saveUserDataToFile(usersFileName, g_vUsers);

	cout << "\nUser addedd sucessfully" << endl;
	g_vUsers = loadUsersData(usersFileName);
}

void addUserScreen()
{
	char confirm = 'n';

	do {
		
		system("cls");

		cout << "=====================================\n";
		cout << "       " << "Add User Screen\n";
		cout << "=====================================\n";

		addNewUser();

		cout << "Do you want to add more users? y / n: ";
		cin >> confirm;

	} while (tolower(confirm == 'y'));
}

bool authenticateLogin(const string& username, const string& password, stUser& user)
{
	for (const stUser& u : g_vUsers)
	{
		if (u.username == username && u.password == password)
		{
			user = u;
			return true;
		}
	}

	return false;
}

void goBackToManageUsersMenu()
{
	cout << "Press any key to go back to manage users menu..." << endl;
	system("pause > 0");

	showManageUsersMenu();
}

void accessDeniedInfo()
{
	system("cls");

	cout << "=====================================\n";
	cout << "       " << "Access Denied!\n";
	cout << "=====================================\n";

	cout << "\nYou don't have permission to do this opearation, contact your admin!" << endl;

	goBackToMainMenu();
}

void showAllUsers()
{
	system("cls");

	cout << "                                   ";
	cout << "Users List (" << g_vUsers.size() << ") User(s)." << endl;
	cout << "------------------------";
	cout << "------------------------" << endl;

	cout << left
		<< "| " << setw(15) << "Username "
		<< "| " << setw(10) << "Password "
		<< "| " << setw(16) << "Permissions " << "|"
		<< endl;

	cout << "------------------------";
	cout << "------------------------" << endl;

	if (g_vUsers.size() == 0)
	{
		cout << "There are no records of users in this file!\n" << endl;
		goBackToManageUsersMenu();
	}

	for (const stUser& user : g_vUsers)
	{
		cout << left
			<< "| " << setw(15) << user.username
			<< "| " << setw(10) << user.password
			<< "| " << setw(16) << user.permission
			<< "| " << endl;
	}

	cout << "------------------------";
	cout << "------------------------" << endl;
}

void printUserDetails(const stUser& user)
{
	cout << "\nThe following is the user details:\n";

	cout << "---------------------------------" << endl;
	cout << "Username: " << user.username << endl;
	cout << "Password: " << user.password << endl;
	cout << "permissions: " << user.permission << endl;
	cout << "---------------------------------" << endl;

	cout << endl;
}

bool userHasPermission(const short& permession, const short& option)
{
	if (permession == -1)
		return true;

	if (permession & option)
		return true;

	return false;
}

void performManageUsersMenuOption(const enManageUsersMenuOption& option)
{
	switch (option)
	{
	case enManageUsersMenuOption::eMShowAllUsers:
	{
		system("cls");
		showAllUsers();
		goBackToManageUsersMenu();
		break;
	}
	case enManageUsersMenuOption::eMAddNewUser:
	{
		system("cls");
		addUserScreen();
		goBackToManageUsersMenu();
		break;
	}
	case enManageUsersMenuOption::eMDeleteUser:
	{
		deleteUserScreen();
		goBackToManageUsersMenu();
		break;
	}
	case enManageUsersMenuOption::eMUpdateUser:
	{
		updateUserScreen();
		goBackToManageUsersMenu();
		break;
	}
	case enManageUsersMenuOption::eMFindUser:
	{
		system("cls");
		findUserScreen();
		goBackToManageUsersMenu();
		break;
	}
	case enManageUsersMenuOption::eMMainMenu:
	{
		showMainMenu();
		break;
	}
	default:
		break;
	}
}

void deleteUserByUsername(const stUser& user)
{
	for (stUser& u : g_vUsers)
	{
		if (u.username == user.username)
		{
			if (u.permission != -1)
			{
				u.markForDelete = true;
				break;
			}
			else
			{
				cout << "You can't deleted an admin user!" << endl;
				return;
			}
		}
	}

	saveUserDataToFile(usersFileName, g_vUsers);
	g_vUsers = loadUsersData(usersFileName); // refresh

	cout << "\nUser deleted sucessfully!" << endl;
}

void deleteUserScreen()
{
	system("cls");

	cout << "=====================================\n";
	cout << "       " << "Delete User Screen\n";
	cout << "=====================================\n";
	
	string username = readUsername();
	stUser user;

	if (findUserByUsername(username, user))
	{
		printUserDetails(user);

		cout << "Are you sure you want to delete this user? y / n: ";

		if(confirmAction())
			deleteUserByUsername(user);
	}
	else
		cout << "User with account number (" << username << ") not found!" << endl;
}

void updateUserByUsername(const stUser& user)
{
	for (stUser& u : g_vUsers)
	{
		if (u.username == user.username)
		{
			updateUserDetails(u);
			break;
		}
	}

	saveUserDataToFile(usersFileName, g_vUsers);
	g_vUsers = loadUsersData(usersFileName); // refresh

	cout << "\nUser updated sucessfully!" << endl;
}

void updateUserScreen()
{
	system("cls");

	cout << "=====================================\n";
	cout << "       " << "Update User Screen\n";
	cout << "=====================================\n";

	string username = readUsername();
	stUser user;

	if (findUserByUsername(username, user))
	{
		printUserDetails(user);

		cout << "Are you sure you want to update this user? y / n: ";

		if (confirmAction())
			updateUserByUsername(user);
	}
	else
		cout << "User with account number (" << username << ") not found!" << endl;
}

bool findUserByUsername(const string& username, stUser& user)
{
	for (const stUser& u : g_vUsers)
	{
		if (u.username == username)
		{
			user = u;
			return true;
		}
	}

	return false;
}

void findUserScreen()
{
	cout << "=====================================\n";
	cout << "     Find User Screen" << endl;
	cout << "=====================================\n" << endl;

	string username = readUsername();
	stUser user;

	if (findUserByUsername(username, user))
		printUserDetails(user);
	else
		cout << "User with account number (" << username << ") not found!" << endl;
}

void showManageUsersMenu()
{
	system("cls");
	cout << "=====================================\n";
	cout << "           " << "Manage Users Screen\n";
	cout << "=====================================\n";
	cout << "     " << "[1] Show users list\n";
	cout << "     " << "[2] Add new user\n";
	cout << "     " << "[3] Delete user\n";
	cout << "     " << "[4] Update user\n";
	cout << "     " << "[5] Find user\n";
	cout << "     " << "[6] Main Menu\n";
	cout << "=====================================\n";

	short option = readUserOption(1, 6);

	performManageUsersMenuOption(enManageUsersMenuOption(option));
}

stUser readUserDetails()
{
	stUser user;

	while (true)
	{
		cout << "Enter username: ";
		cin >> user.username;

		if (findUserByUsername(user.username, user))
			cout << "User already exists, try different username!" << endl;
		else
			break;
	}

	cout << "Enter password: ";
	cin >> user.password;

	user.permission = askUserPermissions();

	return user;
}

void updateUserDetails(stUser& user)
{

	cout << "Enter password: ";
	cin >> user.password;

	user.permission = askUserPermissions();
}

void goBackToMainMenu()
{
	cout << "Press any key to go back to main menu..." << endl;
	system("pause > 0");

	showMainMenu();
}

void showMainMenu()
{

	system("cls");
	cout << "=====================================\n";
	cout << "           " << "Main Menu Screen\n";
	cout << "=====================================\n";
	cout << "     " << "[1] Show Client List\n";
	cout << "     " << "[2] Add New Client\n";
	cout << "     " << "[3] Delete Client\n";
	cout << "     " << "[4] Update Client Info\n";
	cout << "     " << "[5] Find Client\n";
	cout << "     " << "[6] Transactions\n";
	cout << "     " << "[7] Manage Users\n";
	cout << "     " << "[8] Logout\n";
	cout << "=====================================\n";

	short option = readUserOption(1, 8);

	performMainMenuOption(enMainMenuOption(option));
}

int main()
{
	showLoginScreen();
	return 0;
}