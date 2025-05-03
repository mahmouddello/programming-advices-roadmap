#include <iostream>
#include <vector>
#include "D:/MyCPP_Libs/headers/date_utils.h"
#include "D:/MyCPP_Libs/headers/string_utils.h"

using namespace std;
using date_utils::stDate;

bool validateDate(const stDate& date)
{
	return date.month < 1 || date.month > 12 ? false : date.day <= date_utils::numberOfDaysInAMonth(date.year, date.month);
}

string readDateString()
{
	string dateStr;

	cout << "Please enter date in form (dd/mm/yyyy): ";
	getline(cin >> ws, dateStr);

	return dateStr;
}

stDate stringToDate(const string& dateStr)
{
	vector<string> vDateStr = string_utils::splitString(dateStr, "/");
	stDate date;

	date.day = stoi(vDateStr[0]);
	date.month = stoi(vDateStr[1]);
	date.year = stoi(vDateStr[2]);

	return date;
}

string fetchSeperatorFromFormat(string dateFormat)
{
	string seperator = "/";

	for (int i = 0; i <= dateFormat.length(); i++)
	{
		if (!isalpha(dateFormat[i]))
		{
			seperator = dateFormat[i];
			break;
		}
	}

	return seperator;
}

string formatDate(const stDate& date, string dateFormat)
{
	dateFormat = string_utils::replaceAll(dateFormat, "dd", to_string(date.day));
	dateFormat = string_utils::replaceAll(dateFormat, "mm", to_string(date.month));
	dateFormat = string_utils::replaceAll(dateFormat, "yyyy", to_string(date.year));

	return dateFormat;
}

int main()
{
	
	stDate date = stringToDate(readDateString());

	if (!validateDate(date))
	{
		cout << "\nDate is not valid!" << endl;
	}
	else
	{
		cout << "\n" << formatDate(date, "dd/mm/yyyy") << endl;
		cout << "\n" << formatDate(date, "yyyy/dd/mm") << endl;
		cout << "\n" << formatDate(date, "mm/dd/yyyy") << endl;
		cout << "\n" << formatDate(date, "mm-dd-yyyy") << endl;
		cout << "\n" << formatDate(date, "dd-mm-yyyy") << endl;
		cout << "\n" << formatDate(date, "yyyy-dd-mm") << endl;
		cout << "\n" << formatDate(date, "Day: dd, Month: mm, Year: yyyy") << endl;
	}

	return 0;
}