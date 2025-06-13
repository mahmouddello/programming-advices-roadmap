#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTotalBalancesScreen : protected clsScreen
{
private:
    static void _printClientRecordBalanceLine(clsBankClient client)
    {

        cout << "| " << setw(15) << left << client.getAccountNumber();
        cout << "| " << setw(40) << left << client.getFullName();
        cout << "| " << setw(12) << left << client.accountBalance;
    }

    static void _drawTableUI()
    {
        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }

    static void _showTotalBalances()
    {

        vector<clsBankClient> vClients = clsBankClient::getClientsList();

       
        string title = "\t Client List Screen";
        string subtitle = "\t   (" + to_string(vClients.size()) + ") Client(s)";
        
        _drawScreenHeader(title, subtitle);

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!\n";
        else
        {
            _drawTableUI();
            double TotalBalances = clsBankClient::getTotalBalance();

            for (clsBankClient Client : vClients)
            {
                _printClientRecordBalanceLine(Client);
                cout << endl;
            }

            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;
            cout << "Total Balances = " << TotalBalances << endl;
            cout << "( " << clsUtil::NumberToText(TotalBalances) << ")" << endl;
        }
    }
public:
    static void showTotalBalancesScreen()
    {
        _showTotalBalances();
    }
};

