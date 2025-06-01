#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "../cpplibs/clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen
{
private:
	static bool _confirmAction()
	{
		char c = 'n';
		cin >> c;

		return tolower(c) == 'y';
	}

	static short _askUserPermissions()
	{
		cout << "Do you want to give this user full access? y / n: ";
		if (_confirmAction())
			return clsUser::enPermessions::eAll;

		short permissions = 0;

		cout << "\Show client list? y / n: ";
		if (_confirmAction())
			permissions += clsUser::enPermessions::pShowClientsList;

		cout << "\nAdd new client? y / n: ";
		if (_confirmAction())
			permissions += clsUser::enPermessions::pAddNewClient;

		cout << "\nDelete client? y / n: ";
		if (_confirmAction())
			permissions += clsUser::enPermessions::pDeleteClient;

		cout << "\nUpdate client? y / n: ";
		if (_confirmAction())
			permissions += clsUser::enPermessions::pUpdateClient;

		cout << "\nFind client? y / n: ";
		if (_confirmAction())
			permissions += clsUser::enPermessions::pFindClient;

		cout << "\nTransactions? y / n: ";
		if (_confirmAction())
			permissions += clsUser::enPermessions::pTransactions;

		cout << "\nManage users? y / n: ";
		if (_confirmAction())
			permissions += clsUser::enPermessions::pManageUsers;

		return permissions;
	}

	static void _printUser(clsUser user)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << user.firstName;
		cout << "\nLastName    : " << user.lastName;
		cout << "\nFull Name   : " << user.getFullName();
		cout << "\nEmail       : " << user.email;
		cout << "\nPhone       : " << user.phoneNumber;
		cout << "\nUsername : " << user.getUsername();
		cout << "\nPassword    : " << user.password;
		cout << "\nPermissions    : " << user.permessions;
		cout << "\n___________________\n";
	}

	static void _readUserInfo(clsUser& user)
	{
		// seperating UI from object, reads from console and stores in the object
		user.firstName = clsInputValidate::readString("Enter first name: ");
		user.lastName = clsInputValidate::readString("Enter last name: ");
		user.email = clsInputValidate::readString("Enter email: ");
		user.phoneNumber = clsInputValidate::readString("Enter phone number: ");
		user.password = clsInputValidate::readString("Enter password: ");
	}

public:
	static void showUpdateUserScreen()
	{
		_drawScreenHeader("\t Update User Screen");

		string username = "";

		string message = "Please enter username: ";
		username = clsInputValidate::readString(message);

		// While client doesn't exist
		while (!clsUser::isUserExist(username))
		{
			cout << "\nuser doesn't exist, try another username: ";
			username = clsInputValidate::readString("");
		}

		clsUser user = clsUser::find(username);
		_printUser(user);

		cout << endl;

		char confirmation = 'n';
		cout << "\nAre you sure you want to update this user? y / n: ";
		cin >> confirmation;

		if (tolower(confirmation) == 'y')
		{
			_readUserInfo(user);
			user.permessions = _askUserPermissions();

			clsUser::enSaveResults saveResult = user.save();

			switch (saveResult)
			{
			case  clsUser::enSaveResults::svSucceeded:
			{
				cout << "\nUser Updated Successfully :-)\n";
				_printUser(user);
				break;
			}
			case clsUser::enSaveResults::svFailedEmptyObject:
			{
				cout << "\nError user was not saved because it's Empty!\n";
				break;
			}
			default:
				break;
			}
		}
		else
			cout << "Operation was caneled!" << endl;
	}
};