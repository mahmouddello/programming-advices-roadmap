#pragma once
#include <iostream>
#include "globals.h"
#include "../cpplibs/clsDate.h"

using namespace std;

class clsScreen
{
protected:
	static void _drawScreenHeader(string title, string subTitle = "")
	{
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << title;
        if (subTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << subTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\tUser: " << currentUser.getUsername() << endl;
        cout << "\t\t\t\t\tDate: " << clsDate::getSystemDate() << endl;
	}
};

