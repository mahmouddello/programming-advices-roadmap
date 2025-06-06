#pragma once

#include "clsUser.h"
#include "clsScreen.h"
#include "../cpplibs/clsInputValidate.h"
#include "clsMainScreen.h"
#include "globals.h"
#include "../cpplibs/clsString.h"

class clsLoginScreen : protected clsScreen
{
private:
	static void _login()
	{
		short loginAttmpts = 3;
		string username = "", password = "";
		bool loginFailed = false;

		do
		{
			system("cls");
			_drawScreenHeader("\t Login Screen");

			if (loginFailed)
			{
				loginAttmpts--;
				cout << "\nLogin Failed! Invalid Username or Password, You have " << loginAttmpts << " left!" << endl;
			}

			username = clsInputValidate::readString("\nEnter username: ");
			password = clsInputValidate::readString("\nEnter password: ");

			currentUser = clsUser::find(username, password);
			loginFailed = currentUser.isEmpty();

		} while (loginAttmpts > 1 && loginFailed);

		if (loginFailed)
		{
			cout << "\nSystem is locked after 3 failed attempts!" << endl;
			programFlag = false;
		}
		else
		{
			currentUser.registerLogin();
			clsMainScreen::showMainMenu();
		}
	}
public:

	static void showLoginScreen()
	{
		_login();
	}
};

