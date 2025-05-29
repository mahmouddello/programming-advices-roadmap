#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "../cpplibs/clsInputValidate.h"

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenuOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eExit = 8
	};

	static short _readMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
		short choice = clsInputValidate::readShortNumberBetween(1, 8, "Enter Number between 1 to 8? ");
		return choice;
	}

    static  void _goBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\nPress any key to go back to Main Menu...\n";

        system("pause>0");
        showMainMenu();
    }

    static void _showAllClientsScreen()
    {
        clsClientListScreen::showClientsList();
    }

    static void _showAddNewClientsScreen()
    {
        clsAddNewClientScreen::showAddNewClientScreen();
    }

    static void _showDeleteClientScreen()
    {
        clsDeleteClientScreen::showDeleteClientScreen();
    }

    static void _showUpdateClientScreen()
    {
        clsUpdateClientScreen::showUpdateClientScreen();
    }

    static void _showFindClientScreen()
    {
        clsFindClientScreen::showFindClientScreen();
    }

    static void _showTransactionsMenue()
    {
        clsTransactionsScreen::showTransactionsMenu();
    }

    static void _showManageUsersMenue()
    {
        cout << "\nUsers Menue Will be here...\n";

    }

    static void _showEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }

    static void _perfromMainMenueOption(enMainMenuOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenuOptions::eListClients:
        {
            system("cls");
            _showAllClientsScreen();
            _goBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
            system("cls");
            _showAddNewClientsScreen();
            _goBackToMainMenu();
            break;

        case enMainMenuOptions::eDeleteClient:
            system("cls");
            _showDeleteClientScreen();
            _goBackToMainMenu();
            break;

        case enMainMenuOptions::eUpdateClient:
            system("cls");
            _showUpdateClientScreen();
            _goBackToMainMenu();
            break;

        case enMainMenuOptions::eFindClient:
            system("cls");
            _showFindClientScreen();
            _goBackToMainMenu();
            break;

        case enMainMenuOptions::eShowTransactionsMenue:
            system("cls");
            _showTransactionsMenue();
            showMainMenu();
            break;

        case enMainMenuOptions::eManageUsers:
            system("cls");
            _showManageUsersMenue();
            break;

        case enMainMenuOptions::eExit:
            system("cls");
            _showEndScreen();
            //Login();

            break;
        }

    }

public:
    static void showMainMenu()
    {
        system("cls");
        _drawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _perfromMainMenueOption((enMainMenuOptions)_readMainMenuOption());
    }

};