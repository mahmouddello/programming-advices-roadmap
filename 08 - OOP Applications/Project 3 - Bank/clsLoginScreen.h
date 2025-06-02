#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "../cpplibs/clsInputValidate.h"
#include "clsMainScreen.h"
#include "globals.h"

class clsLoginScreen : protected clsScreen
{
private:
	static void _login()
	{
		string username = "", password = "";
		bool loginFailed = false;

		do
		{
			system("cls");
			_drawScreenHeader("\t Login Screen");

			if (loginFailed)
				cout << "Login Failed! Invalid Username or Password!\n" << endl;

			username = clsInputValidate::readString("Enter username: ");
			password = clsInputValidate::readString("Enter password: ");

			currentUser = clsUser::find(username, password);
			loginFailed = currentUser.isEmpty();

		} while (loginFailed);
	}
public:

	static void showLoginScreen()
	{
		_login();
		clsMainScreen::showMainMenu();
	}
};

