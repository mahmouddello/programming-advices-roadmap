#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "../cpplibs/clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{
private:
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


public:
	static void showDeleteUserScreen()
	{

		_drawScreenHeader("\t Delete User Screen");

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

		char confirmation = 'n';
		cout << "\nAre you sure you want to delete this client? y / n: ";
		cin >> confirmation;

		if (tolower(confirmation) == 'y')
		{
			if (user.deleteUser())
			{
				cout << "\nUser deleted successfully!" << endl;
				_printUser(user);
			}
			else
			{
				cout << "User wasn't deleted, error occured!" << endl;
			}
		}
	}
};
