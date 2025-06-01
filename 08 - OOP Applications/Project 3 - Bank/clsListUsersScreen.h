#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"

class clsListUsersScreen : clsScreen
{
private:
	static void _printUserRecordLine(clsUser user)
	{

		cout << setw(8) << left << "" << "| " << setw(15) << left << user.getUsername();
		cout << "| " << setw(20) << left << user.getFullName();
		cout << "| " << setw(12) << left << user.phoneNumber;
		cout << "| " << setw(20) << left << user.email;
		cout << "| " << setw(10) << left << user.password;
		cout << "| " << setw(10) << left << user.permessions;
	}

	static void _drawTableUI()
	{

		cout << setw(8) << left << "" << "\n\t___________________________________________________________";
		cout << "____________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Username";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permessions";
		cout << setw(8) << left << "" << "\n\t__________________________________________________________";
		cout << "_____________________________________________\n" << endl;
	}
public:
	static void showUsersListScreen()
	{
		vector<clsUser> vUsers = clsUser::getUsersList();

		string title = "\t Users List Screen";
		string subtitle = "\t   (" + to_string(vUsers.size()) + ") Users(s)";

		_drawScreenHeader(title, subtitle);
		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else
		{
			_drawTableUI();
			for (clsUser Client : vUsers)
			{
				_printUserRecordLine(Client);
				cout << endl;
			}
		}
	}
};

