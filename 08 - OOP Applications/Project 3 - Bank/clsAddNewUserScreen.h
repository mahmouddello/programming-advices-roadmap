#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "../cpplibs/clsInputValidate.h"

class clsAddNewUserScreen : protected clsScreen
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
	static void showAddNewUserScreen()
	{

		_drawScreenHeader("\t Add New User Screen");

		string username = "";

		string message = "Please enter username: ";
		username = clsInputValidate::readString(message);

		// While client already exist
		while (clsUser::isUserExist(username))
		{
			cout << "\nusername is associated to another user, choose another one: ";
			username = clsInputValidate::readString("");
		}

		clsUser newUser = clsUser::getAddNewUserObject(username);

		_readUserInfo(newUser);
		newUser.permessions = _askUserPermissions();

		clsUser::enSaveResults saveResult = newUser.save();

		switch (saveResult)
		{
		case  clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser Created Successfully :-)\n";
			_printUser(newUser);
			break;
		}
		case clsUser::enSaveResults::svFailedBecauseUserExist:
		{
			cout << "\nError user was not saved because username is used!\n";
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
};

