#include <iostream>
#include <vector>
#include "../mylibs/headers/date_utils.h"
#include "../mylibs/headers/string_utils.h"

using namespace std;
using date_utils::stDate;

bool validateDate(const stDate& date)
{
	return date.month < 1 || date.month > 12 ? false : date.day <= date_utils::numberOfDaysInAMonth(date.year, date.month);
}

string readDate()
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

void printDateStructDate(const stDate& date)
{
	if (!validateDate(date))
	{
		cout << "The date you entered is not valid!" << endl;
		return;
	}

	cout << "Day: " << date.day << endl;
	cout << "Month: " << date.month << endl;
	cout << "Year: " << date.year << endl;
}

string dateToString(const stDate& date)
{
	if (!validateDate(date))
	{
		cout << "The date you entered is not valid!" << endl;
		return "";
	}
	
	vector<string> vDateStr;

	vDateStr.push_back(to_string(date.day));
	vDateStr.push_back(to_string(date.month));
	vDateStr.push_back(to_string(date.year));

	return string_utils::joinString(vDateStr, "/");
}

int main()
{
	string dateString = readDate();
	stDate date = stringToDate(dateString);

	cout << endl;
	printDateStructDate(date);

	string dateStringNew = dateToString(date);

	if (dateStringNew != "")
		cout << "\nYou entered: " << dateStringNew << endl;

	return 0;
}