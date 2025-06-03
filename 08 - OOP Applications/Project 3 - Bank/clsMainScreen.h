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
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "globals.h"
#include "../cpplibs/clsInputValidate.h"

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenuOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegster = 8, eExit = 9
    };

    static short _readMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]: ";
        short choice = clsInputValidate::readShortNumberBetween(1, 9, "Enter Number between 1 to 9: ");
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
        clsManageUsersScreen::showManageUsersMenu();
    }

    static void _showLoginRegisterScreen()
    {
        clsLoginRegisterScreen::showLoginRegisterScreen();
    }

    static void _logout()
    {
        currentUser = clsUser::find("", "");
    }

    static void _perfromMainMenueOption(enMainMenuOptions MainMenueOption)
    {
        system("cls");
        
        if (MainMenueOption != enMainMenuOptions::eExit)
        {
            if (!currentUser.checkAccessPermission(clsUser::enPermessions(MainMenueOption)))
            {
                clsAccessDeniedScreen::showAccessDeniedScreen();
                _goBackToMainMenu();
                return;
            }
        }

        switch (MainMenueOption)
        {
            case enMainMenuOptions::eListClients:
            {
                _showAllClientsScreen();
                break;
            }
            case enMainMenuOptions::eAddNewClient:
            {
                _showAddNewClientsScreen();
                break;
            }
            case enMainMenuOptions::eDeleteClient:
            {
                _showDeleteClientScreen();
                break;
            }
            case enMainMenuOptions::eUpdateClient:
            {
                _showUpdateClientScreen();
                break;
            }
            case enMainMenuOptions::eFindClient:
            {
                _showFindClientScreen();
                break;
            }
            case enMainMenuOptions::eShowTransactionsMenue:
            {
                _showTransactionsMenue();
                break;
            }
            case enMainMenuOptions::eManageUsers:
            {
                _showManageUsersMenue();
                break;
            }
            case enMainMenuOptions::eLoginRegster:
            {
                _showLoginRegisterScreen();
                break;
            }
            case enMainMenuOptions::eExit:
            {
                _logout();
                break;
            }
            default: 
                break;
        }

        if (MainMenueOption != enMainMenuOptions::eExit)
            _goBackToMainMenu();
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
        cout << setw(37) << left << "" << "\t[8] Login Register Logs.\n";
        cout << setw(37) << left << "" << "\t[9] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _perfromMainMenueOption((enMainMenuOptions)_readMainMenuOption());
    }

};