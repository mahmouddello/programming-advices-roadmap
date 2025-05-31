#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "../cpplibs/clsInputValidate.h"
#include "clsTotalBalancesScreen.h"

class clsMainMenu;

class clsTransactionsScreen : protected clsScreen
{
private:

    enum _enTransactionMenuOptions {eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eMainMenu = 4};

    static  void _goBackToTransactionsMenu()
    {
        cout << "\nPress any key to go back to Transactinos Menu...\n";

        system("pause>0");
        showTransactionsMenu();
    }

    static void _perfromTransactionsMenuOption(_enTransactionMenuOptions transactionsMenuOption)
    {
        if (transactionsMenuOption == _enTransactionMenuOptions::eMainMenu)
            return;
        
        switch (transactionsMenuOption)
        {
            case _enTransactionMenuOptions::eDeposit:
            {
                system("cls");
                _showDepositScreen();
                break;
            }
            case _enTransactionMenuOptions::eWithdraw:
            {
                system("cls");
                _showWithdrawScreen();
                break;
            }
            case _enTransactionMenuOptions::eTotalBalances:
            {
                system("cls");
                _showTotalBalancesScreen();
                break;
            }
            default:
            {
                break;
            }
        }

        _goBackToTransactionsMenu();
    }

    static short _readTransactionsMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]: ";
        return clsInputValidate::readShortNumberBetween(1, 4, "Enter a number between 1 - 4: ");
    }

    static void _showDepositScreen()
    {
        cout << "Deposit Screen will be here" << endl;
    }

    static void _showWithdrawScreen()
    {
        cout << "Withdraw Screen will be here" << endl;
    }

    static void _showTotalBalancesScreen()
    {
        clsTotalBalancesScreen::showTotalBalancesScreen();
    }

public:
    static void showTransactionsMenu()
    {
        system("cls");
        _drawScreenHeader("\t Transations Menu");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\Transactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";

        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menu.\n";

        cout << setw(37) << left << "" << "===========================================\n";
        _perfromTransactionsMenuOption((_enTransactionMenuOptions)_readTransactionsMenuOption());
    }
};
