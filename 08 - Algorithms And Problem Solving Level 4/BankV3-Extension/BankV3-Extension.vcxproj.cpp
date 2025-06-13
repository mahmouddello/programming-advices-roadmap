//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <string>
//#include <vector>
//#include "D:/MyCPP_Libs/headers/string_utils.h";
//
//using namespace std;
//
//// global variables
//const string clientsFileName = "bankClients.txt";
//const string usersFileName = "users.txt";
//bool bankAppFlag = true;
//
//const enum enOptions {
//	showClients = 1,
//	addNewClient = 2,
//	deleteClient = 3,
//	updateClient = 4,
//	findClient = 5,
//	transactions = 6,
//	manageUsers = 7,
//	exitApp = 8,
//};
//
//const enum enTransactions
//{
//	eDeposit = 1,
//	eWithdraw = 2,
//	eTotalBalance = 3,
//	eBackToMainMenu = 4
//};
//
//struct stClient
//{
//	string accountNumber;
//	string pinCode;
//	string name;
//	string phone;
//	double accountBalance;
//	bool markForDelete = false;
//};
//
//struct stUser
//{
//	string username = "";
//	string password = "";
//	short permission = 0;
//};
//
//// declarations
//void startBankApp(const stUser&);
//void showMainMenuScreen();
//void showAllClients(const vector<stClient>&, const stUser&);
//void redirectToScreen(const enOptions&, vector<stClient>&, const stUser&);
//void addClient(const vector<stClient>&, const stUser&);
//void addClients(vector<stClient>&, const stUser&);
//void addDataLineToFile(const string&, const string&);
//string readAccountNumber();
//short readUserOption(short from, short to);
//vector<stClient> loadClientsData(const string&);
//stClient convertLineToClientRecord(const string&, string = "#//#");
//stClient readClientData(const vector<stClient>&, const stUser&);
//string convertClientRecordToLine(const stClient&, string = "#//#");
//stClient findClientByAccountNumber(const string&, const vector<stClient>&, const stUser&);
//void printClientDetails(const stClient&);
//void deleteClientAccount(vector<stClient>&, const stUser&);
//void updateClientData(stClient&, const stUser&);
//void updateClientAccount(vector<stClient>&, const stUser&);
//void markClientToDelete(const string&, vector<stClient>&);
//void saveClientsDataToFile(const string&, const vector<stClient>&);
//void findClientAccount(const vector<stClient>&, const stUser&);
//void exitBankApp();
//void goBackToTranstionsWindow(vector<stClient>&);
//void transactionsWindow(vector<stClient>&, const stUser&);
//void depositAmount(vector<stClient>&);
//void withdrawAmount(vector<stClient>&);
//void showTotalBalance(const vector<stClient>&);
//int calculateTotalBalance(const vector<stClient>&);
//
//// Login logic
//void showLoginScreen();
//string readUsername();
//string readPassword();
//bool authenticateLogin(const string&, const string&, stUser&);
//vector<stUser> loadUsersDate(const string&);
//stUser convertLineToUserRecord(const string&, const string& delimiter);
//string convertUserRecordToLine(const stUser& user, const string& delimiter);
//void manageUsersData(const stUser&);
//
//
//// defintions
//short readUserOption(short from, short to)
//{
//	unsigned short option;
//	cout << "Choose what you want to do [" << from << "-" << to << "]: ";
//	cin >> option;
//
//	return option;
//}
//
//stClient readClientData(const vector<stClient>& vClients, const stUser& user)
//{
//	stClient data;
//
//	cout << "\nPlease enter client data:\n" << endl;
//
//	cin.ignore(1, '\n');
//	while (true)
//	{
//		cout << "Enter account number: ";
//		getline(cin, data.accountNumber);
//
//		if (findClientByAccountNumber(data.accountNumber, vClients, user).accountNumber != "")
//		{
//			cout << "\nClient with [" << data.accountNumber << "] already exits. Please ";
//		}
//		else
//			break;
//	}
//
//	cout << "Enter pin code: ";
//	getline(cin, data.pinCode);
//
//	cout << "Enter name: ";
//	getline(cin, data.name);
//
//	cout << "Enter phone number: ";
//	getline(cin, data.phone);
//
//	cout << "Enter account balance: ";
//	cin >> data.accountBalance;
//	while (cin.fail())
//	{
//		// user didn't input a number
//		cin.clear();
//		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//		cout << "Please enter a valid value for account balance: " << endl;
//		cin >> data.accountBalance;
//	}
//
//	return data;
//}
//
//stClient findClientByAccountNumber(const string& accountNumber, const vector<stClient>& vClients, const stUser& user)
//{
//	for (stClient client : vClients)
//	{
//		if (client.accountNumber == accountNumber)
//			return client;
//	}
//
//	// Return a "not found" dummy client
//	return { "", "", "", "", 0.0 };
//}
//
//void redirectToScreen(const enOptions& userOption, vector<stClient>& vClients, const stUser& user)
//{
//	switch (userOption)
//	{
//	case enOptions::showClients:
//	{
//		showAllClients(vClients, user);
//		break;
//	}
//	case enOptions::addNewClient:
//	{
//		addClients(vClients, user);
//		break;
//	}
//	case enOptions::deleteClient:
//	{
//		deleteClientAccount(vClients, user);
//		break;
//	}
//	case enOptions::updateClient:
//	{
//		updateClientAccount(vClients, user);
//		break;
//	}
//	case enOptions::findClient:
//	{
//		findClientAccount(vClients, user);
//		break;
//	}
//	case enOptions::transactions:
//	{
//		transactionsWindow(vClients, user);
//		break;
//	}
//	case enOptions::manageUsers:
//	{	
//		break;
//	}
//	case enOptions::exitApp:
//	{
//		showLoginScreen();
//		break;
//	}
//	default:
//		break;
//	}
//
//}
//
//void transactionWindowRedirect(const enTransactions& userOption, vector<stClient>& vClients)
//{
//	switch (userOption)
//	{
//	case enTransactions::eDeposit:
//	{
//		depositAmount(vClients);
//		goBackToTranstionsWindow(vClients);
//		break;
//	}
//	case enTransactions::eWithdraw:
//	{
//		withdrawAmount(vClients);
//		goBackToTranstionsWindow(vClients);
//		break;
//	}
//	case enTransactions::eTotalBalance:
//	{
//		showTotalBalance(vClients);
//		goBackToTranstionsWindow(vClients);
//		break;
//	}
//	case enTransactions::eBackToMainMenu:
//	{
//		showMainMenuScreen();
//		break;
//	}
//	default:
//	{
//		break;
//	}
//	}
//}
//
//void showMainMenuScreen()
//{
//	system("cls");
//
//	cout << "=====================================\n";
//	cout << "           " << "Main Menu Screen\n";
//	cout << "=====================================\n";
//	cout << "     " << "[1] Show Client List\n";
//	cout << "     " << "[2] Add New Client\n";
//	cout << "     " << "[3] Delete Client\n";
//	cout << "     " << "[4] Update Client Info\n";
//	cout << "     " << "[5] Find Client\n";
//	cout << "     " << "[6] Transactions\n";
//	cout << "     " << "[7] Manager Users\n";
//	cout << "     " << "[8] Exit\n";
//	cout << "=====================================\n";
//
//}
//
//void showAllClients(const vector<stClient>& vClients, const stUser& user)
//{
//	system("cls");
//
//	cout << "                                   ";
//	cout << "Clients List (" << vClients.size() << ") Client(s)." << endl;
//	cout << "---------------------------------------------------";
//	cout << "--------------------------------------------------" << endl;
//
//	cout << left
//		<< "| " << setw(15) << "Account Number "
//		<< "| " << setw(10) << "Pin Code "
//		<< "| " << setw(30) << "Client Name "
//		<< "| " << setw(20) << "Phone Number "
//		<< "| " << setw(15) << "Balance " << "|"
//		<< endl;
//
//	cout << "---------------------------------------------------";
//	cout << "--------------------------------------------------" << endl;
//
//	if (vClients.size() == 0)
//	{
//		cout << "There are no records of clients in this file!\n" << endl;
//		system("pause");
//		return;
//	}
//
//	for (const stClient& client : vClients)
//	{
//		cout << left
//			<< "| " << setw(15) << client.accountNumber
//			<< "| " << setw(10) << client.pinCode
//			<< "| " << setw(30) << client.name
//			<< "| " << setw(20) << client.phone
//			<< "| " << setw(15) << client.accountBalance
//			<< "| " << endl;
//	}
//
//	cout << "---------------------------------------------------";
//	cout << "--------------------------------------------------" << endl;
//	system("pause");
//}
//
//void addClient(const vector<stClient>& vClients, const stUser& user)
//{
//	cout << "\nAdding new client:" << endl;
//	cout << "------------------------" << endl;
//
//	stClient newClient;
//	newClient = readClientData(vClients, user);
//
//	addDataLineToFile(clientsFileName, convertClientRecordToLine(newClient));
//}
//
//void addClients(vector<stClient>& vClients, const stUser& user)
//{
//	char addMore = 'y';
//
//	do
//	{
//		system("cls");
//		cout << "=====================================\n";
//		cout << "     Add New Client Screen" << endl;
//		cout << "=====================================\n";
//		addClient(vClients, user);
//		cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
//		cin >> addMore;
//	} while (tolower(addMore) == 'y');
//
//	// refresh clients list
//	vClients = loadClientsData(clientsFileName);
//}
//
//void addDataLineToFile(const string& clientsFileName, const string& dataLine)
//{
//	fstream MyFile;
//	MyFile.open(clientsFileName, ios::out | ios::app);
//	if (MyFile.is_open())
//	{
//		MyFile << dataLine << endl;
//		MyFile.close();
//	}
//}
//
//vector<stClient> loadClientsData(const string& clientsFileName)
//{
//	fstream file;
//	vector<stClient> vClientsData;
//	string line;
//
//	file.open(clientsFileName, ios::in);
//
//	if (file.is_open())
//	{
//		while (getline(file, line))
//		{
//			vClientsData.push_back(convertLineToClientRecord(line));
//		}
//
//		file.close();
//	}
//
//	return vClientsData;
//}
//
//stClient convertLineToClientRecord(const string& line, string delimiter)
//{
//	vector<string> vTemp = string_utils::splitString(line, delimiter);
//
//	stClient data;
//
//	data.accountNumber = vTemp[0];
//	data.pinCode = vTemp[1];
//	data.name = vTemp[2];
//	data.phone = vTemp[3];
//	data.accountBalance = stod(vTemp[4]);
//
//	return data;
//}
//
//string convertClientRecordToLine(const stClient& client, string delimiter)
//{
//	string strClientRecord = "";
//
//	strClientRecord += client.accountNumber + delimiter;
//	strClientRecord += client.pinCode + delimiter;
//	strClientRecord += client.name + delimiter;
//	strClientRecord += client.phone + delimiter;
//	strClientRecord += to_string(client.accountBalance);
//
//	return strClientRecord;
//}
//
//void findClientAccount(const vector<stClient>& vClients, const stUser& user)
//{
//	system("cls");
//
//	cout << "=====================================\n";
//	cout << "     Find Client Screen" << endl;
//	cout << "=====================================\n" << endl;
//
//	string accountNumber = readAccountNumber();
//	stClient targetClient = findClientByAccountNumber(accountNumber, vClients, user);
//
//	if (targetClient.accountNumber != "")
//	{
//		printClientDetails(targetClient);
//		system("pause");
//	}
//	else
//	{
//		cout << "Client with account number (" << accountNumber << ") not found!" << endl;
//		system("pause");
//	}
//}
//
//void saveClientsDataToFile(const string& clientsFileName, const vector<stClient>& vClients)
//{
//	fstream myFile;
//	myFile.open(clientsFileName, ios::out);//overwrite
//	string dataLine;
//
//	if (myFile.is_open())
//	{
//		for (stClient c : vClients)
//		{
//			if (c.markForDelete == false)
//			{
//				//we only write records that are not marked for delete.
//				dataLine = convertClientRecordToLine(c);
//				myFile << dataLine << endl;
//			}
//		}
//
//		myFile.close();
//	}
//}
//
//void showTotalBalance(const vector<stClient>& vClients)
//{
//	showAllClients(vClients);
//
//	cout << "\n     Total Balance: " << calculateTotalBalance(vClients) << endl;
//}
//
//void updateClientData(stClient& data, const stUser& user)
//{
//
//	cin.ignore(1, '\n');
//	cout << "Enter pin code: ";
//	getline(cin, data.pinCode);
//
//	cout << "Enter name: ";
//	getline(cin, data.name);
//
//	cout << "Enter phone number: ";
//	getline(cin, data.phone);
//
//	cout << "Enter account balance: ";
//	cin >> data.accountBalance;
//	while (cin.fail())
//	{
//		// user didn't input a number
//		cin.clear();
//		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//		cout << "Please enter a valid value for account balance: " << endl;
//		cin >> data.accountBalance;
//	}
//}
//
//int calculateTotalBalance(const vector<stClient>& vClients)
//{
//	double sum = 0;
//
//	for (const stClient c : vClients)
//	{
//		sum += c.accountBalance;
//	}
//
//	return sum;
//}
//
//string readAccountNumber()
//{
//	string accNum = "";
//
//	cout << "Please enter the account number of client: ";
//	cin >> accNum;
//
//	return accNum;
//}
//
//void updateClientAccount(vector<stClient>& vClients, const stUser& user)
//{
//	system("cls");
//
//	cout << "=====================================\n";
//	cout << "     Update Client Screen" << endl;
//	cout << "=====================================\n" << endl;
//
//	string accountNumber = readAccountNumber();
//	stClient clientToUpdate = findClientByAccountNumber(accountNumber, vClients, user);
//
//	char updateAnswer = 'n';
//
//	if (clientToUpdate.accountNumber != "")
//	{
//		printClientDetails(clientToUpdate);
//
//		cout << "\nDo you want to update this client? Y / N: ";
//		cin >> updateAnswer;
//
//		if (tolower(updateAnswer) == 'y')
//		{
//
//			for (stClient& client : vClients)
//			{
//				if (client.accountNumber == clientToUpdate.accountNumber)
//				{
//					updateClientData(client);
//					break;
//				}
//			}
//
//			saveClientsDataToFile(clientsFileName, vClients);
//
//			// refresh clients
//			vClients = loadClientsData(clientsFileName);
//			cout << "Client updated successfully!" << endl;
//
//			system("pause");
//		}
//	}
//
//}
//
//void markClientToDelete(const string& accountNumber, vector<stClient>& vClients)
//{
//	for (stClient& c : vClients)
//	{
//		if (c.accountNumber == accountNumber)
//		{
//			c.markForDelete = true;
//			return; // exit the function
//			;
//		}
//	}
//}
//
//void deleteClientAccount(vector<stClient>& vClients, const stUser& user)
//{
//	system("cls");
//
//	cout << "=====================================\n";
//	cout << "     Delete Client Screen" << endl;
//	cout << "=====================================\n" << endl;
//
//	string accountNumber = readAccountNumber();
//	stClient clientToDelete = findClientByAccountNumber(accountNumber, vClients, user);
//
//	char delAnswer = 'n';
//
//	if (clientToDelete.accountNumber != "")
//	{
//		printClientDetails(clientToDelete);
//
//		cout << "\nDo you want to delete this client? Y / N: ";
//		cin >> delAnswer;
//
//		if (tolower(delAnswer) == 'y')
//		{
//			markClientToDelete(accountNumber, vClients);
//			saveClientsDataToFile(clientsFileName, vClients);
//
//			// refresh clients
//			vClients = loadClientsData(clientsFileName);
//			cout << "Client delete successfully!" << endl;
//
//			system("pause");
//		}
//
//		else
//		{
//			cout << "Client with account number (" << accountNumber << ") not found!" << endl;
//			system("pause");
//		}
//	}
//}
//
//void depositAmount(vector<stClient>& vClients, const stUser& user)
//{
//	system("cls");
//
//	cout << "=====================================\n";
//	cout << "     Deposit Screen" << endl;
//	cout << "=====================================\n" << endl;
//
//	string accountNumber = readAccountNumber();
//	stClient client = findClientByAccountNumber(accountNumber, vClients, user);
//
//	if (client.accountNumber != "")
//	{
//		printClientDetails(client);
//
//		double balanceToBeAdded;
//		cout << "\nEnter the ammount you want to deposit: ";
//		cin >> balanceToBeAdded;
//
//		char confirm = 'n';
//		cout << "\nAre you sure you want to deposit this ammount? Y / N: ";
//		cin >> confirm;
//
//		if (tolower(confirm) == 'y')
//		{
//			for (stClient& c : vClients)
//			{
//				if (c.accountNumber == client.accountNumber)
//				{
//					c.accountBalance += balanceToBeAdded;
//					break;
//				}
//			}
//		}
//		saveClientsDataToFile(clientsFileName, vClients);
//
//		cout << "\nClient balance updated successfully!" << endl;
//
//		vClients = loadClientsData(clientsFileName); // refresh
//	}
//}
//
//void withdrawAmount(vector<stClient>& vClients, const stUser& user)
//{
//	system("cls");
//
//	cout << "=====================================\n";
//	cout << "     Withdraw Screen" << endl;
//	cout << "=====================================\n" << endl;
//
//	string accountNumber = readAccountNumber();
//	stClient client = findClientByAccountNumber(accountNumber, vClients, user);
//
//	if (client.accountNumber != "")
//	{
//		printClientDetails(client);
//
//		double balanceToWithdraw = 0.0;
//		char confirm = 'n';
//
//		while (true)
//		{
//			cout << "\nEnter the amount you want to withdraw: ";
//			cin >> balanceToWithdraw;
//
//			if (client.accountBalance < balanceToWithdraw)
//				cout << "Specified amount exceeds balance, try withdrawing another amount" << endl;
//			else
//				break;
//		}
//
//		cout << "\nAre you sure you want to withdraw this amount? y / n: ";
//		cin >> confirm;
//
//		if (tolower(confirm) == 'y')
//		{
//			for (stClient& c : vClients)
//			{
//				if (c.accountNumber == client.accountNumber)
//				{
//					c.accountBalance -= balanceToWithdraw;
//					break;
//				}
//			}
//			saveClientsDataToFile(clientsFileName, vClients);
//
//			cout << "\nClient balance updated successfully!" << endl;
//
//			vClients = loadClientsData(clientsFileName); // refresh
//		}
//	}
//	else
//		cout << "Client with account number [" << accountNumber << "] not found!" << endl;
//}
//
//void printClientDetails(const stClient& client)
//{
//	cout << "\nThe following client details:\n";
//
//	cout << "---------------------------------" << endl;
//	cout << "Account Number: " << client.accountNumber << endl;
//	cout << "Pin Code: " << client.pinCode << endl;
//	cout << "Name: " << client.name << endl;
//	cout << "Phone Number: " << client.phone << endl;
//	cout << "Account Balance: " << client.accountBalance << endl;
//	cout << "---------------------------------" << endl;
//
//	cout << endl;
//}
//
//void goBackToTranstionsWindow(vector<stClient>& vClients)
//{
//	cout << "\nPress any key to return to transations window...";
//	system("pause>0");
//
//	transactionsWindow(vClients, const stUser & user);
//}
//
//void transactionsWindow(vector<stClient>& vClients, const stUser& user)
//{
//	system("cls");
//
//	cout << "=====================================\n";
//	cout << "       " << "Transactions Screen\n";
//	cout << "=====================================\n";
//	cout << "     " << "[1] Deposit\n";
//	cout << "     " << "[2] Withdraw\n";
//	cout << "     " << "[3] Total Balances\n";
//	cout << "     " << "[4] Main Menu\n";
//	cout << "=====================================\n";
//
//	enTransactions userOption;
//
//	userOption = (enTransactions)readUserOption(1, 4);
//
//	transactionWindowRedirect(userOption, vClients);
//}
//
//string readUsername()
//{
//	string username = "";
//
//	cout << "Username: ";
//	getline(cin >> ws, username);
//
//	return username;
//}
//
//string readPassword()
//{
//	string password = "";
//
//	cout << "Password: ";
//	getline(cin >> ws, password);
//
//	return password;
//}
//
//stUser convertLineToUserRecord(const string& line, const string& delimiter)
//{
//	vector<string> vTemp = string_utils::splitString(line, delimiter);
//
//	stUser data;
//
//	data.username = vTemp[0];
//	data.password = vTemp[1];
//	data.permission = stoi(vTemp[2]);
//
//	return data;
//}
//
//string convertUserRecordToLine(const stUser& user, const string& delimiter)
//{
//	string strUserRecord = "";
//
//	strUserRecord += user.username + delimiter;
//	strUserRecord += user.password + delimiter;
//	strUserRecord += to_string(user.permission);
//
//	return strUserRecord;
//}
//
//vector<stUser> loadUsersData(const string& usersFileName)
//{
//	vector<stUser> vUsers;
//	string line;
//	fstream file;
//	file.open(usersFileName, ios::in);
//
//	if (file.is_open())
//	{
//		while (getline(file, line))
//		{
//			vUsers.push_back(convertLineToUserRecord(line, "#//#"));
//		}
//
//		file.close();
//	}
//
//	return vUsers;
//}
//
//bool authenticateLogin(const string& username, const string& password, stUser& user)
//{
//	vector<stUser> vUsers = loadUsersData(usersFileName);
//
//	for (stUser& u : vUsers)
//	{
//		if (u.username == username && u.password == password)
//		{
//			user = u;
//			return true;
//		}
//	}
//
//	return false;
//}
//
//void showLoginScreen()
//{
//	system("cls");
//
//	cout << "=====================================\n";
//	cout << "       " << "Login Screen\n";
//	cout << "=====================================\n";
//
//	string username = readUsername();
//	string password = readPassword();
//	stUser user;
//
//	while (true)
//	{
//		if (authenticateLogin(username, password, user))
//			break;
//		else
//		{
//
//			cout << "Invalid Username/Password!" << endl;
//			string username = readUsername();
//			string password = readPassword();
//		}
//	}
//
//	startBankApp(user);
//
//}
//
//void exitBankApp()
//{
//	system("cls");
//
//	string exitMessage = "Exiting bank app, Have a nice day!";
//
//	bankAppFlag = false;
//
//	cout << exitMessage << endl;
//
//	cout << endl;
//
//}
//
//void startBankApp(const stUser& user)
//{
//	// first load
//	vector<stClient> vClients = loadClientsData(clientsFileName);
//
//	enOptions userOption;
//
//	while (bankAppFlag)
//	{
//		showMainMenuScreen();
//		userOption = enOptions(readUserOption(1, 8));
//
//		redirectToScreen(userOption, vClients, user);
//	}
//}
//
//int main()
//{
//	showLoginScreen();
//	return 0;
//}