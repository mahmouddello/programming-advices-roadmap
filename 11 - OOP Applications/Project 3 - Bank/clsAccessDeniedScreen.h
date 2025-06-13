#pragma once
#include "clsScreen.h"
class clsAccessDeniedScreen : protected clsScreen
{
public:
	static void showAccessDeniedScreen()
	{
		system("cls");
		_drawScreenHeader("\t Access Denied!");
		cout << "If you think there is a mistake, contact your admin!" << endl;
	}
};

