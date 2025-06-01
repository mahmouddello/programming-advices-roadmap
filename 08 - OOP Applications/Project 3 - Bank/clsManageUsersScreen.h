#pragma once
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "../cpplibs/clsInputValidate.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
private:
	enum _enManageUsersMenuOptions
	{
		eListUsers = 1,
		eAddNewUser = 2,
		eDeleteUser = 3,
		eUpdateUser = 4,
		eFindUser = 5,
		eMainMenu = 6
	};

	static short _readManageUsersMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]: ";
		return clsInputValidate::readShortNumberBetween(1, 6, "Enter a number between 1 - 6: ");
	}

	static void _goBackToManageUsersMenu()
	{
		cout << "\nPress any key to go back to Manage Users Menu...\n";

		system("pause>0");
		showManageUsersMenu();
	}

	static void _performManageUsersMenuOption(_enManageUsersMenuOptions option)
	{
		if (option == _enManageUsersMenuOptions::eMainMenu)
			return; // exit the function
		system("cls");

		switch (option)
		{
			case _enManageUsersMenuOptions::eListUsers:
			{
				_showListUsersScreen();
				break;
			}
			case _enManageUsersMenuOptions::eAddNewUser:
			{
				_showAddNewUserScreen();
				break;
			}
			case _enManageUsersMenuOptions::eDeleteUser:
			{
				_showDeleteUserScreen();
				break;
			}
			case _enManageUsersMenuOptions::eUpdateUser:
			{
				_showUpdateUserScreen();
				break;
			}
			case _enManageUsersMenuOptions::eFindUser:
			{
				_showFindUserScreen();
				break;
			}
			default:
				break;
		}

		_goBackToManageUsersMenu();
	}

	static void _showListUsersScreen()
	{
		clsListUsersScreen::showUsersListScreen();
	}

	static void _showAddNewUserScreen()
	{
		clsAddNewUserScreen::showAddNewUserScreen();
	}

	static void _showDeleteUserScreen()
	{
		clsDeleteUserScreen::showDeleteUserScreen();
	}

	static void _showUpdateUserScreen()
	{
		clsUpdateUserScreen::showUpdateUserScreen();
	}

	static void _showFindUserScreen()
	{
		clsFindUserScreen::showFindUserScreen();
	}

public:
	static void showManageUsersMenu()
	{

		system("cls");
		_drawScreenHeader("\t Manage Users Screen");


		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Manage Users Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";

		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";

		cout << setw(37) << left << "" << "===========================================\n";
		_performManageUsersMenuOption(_enManageUsersMenuOptions(_readManageUsersMenuOption()));
	}
};

