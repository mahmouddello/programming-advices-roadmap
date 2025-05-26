#pragma once
#include <iostream>

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
	}
};

