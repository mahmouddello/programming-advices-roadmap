#include <iostream>
using namespace std;

enum enWeekDay { Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thu = 5, Fri = 6, Sat = 7 };


void ShowWeekDayMenu()
{
	cout << "************************" << endl;
	cout << "       Week Days        " << endl;
	cout << "************************" << endl;
	cout << "1: Sunday" << endl;
	cout << "2: Monday" << endl;
	cout << "3: Tuesday" << endl;
	cout << "4: Wednesday" << endl;
	cout << "5: Thursday" << endl;
	cout << "6: Friday" << endl;
	cout << "7: Saturday" << endl;
	cout << "************************" << endl;
	cout << "Please enter the number of day?" << endl;

}

enWeekDay ReadWeekDay()
{

	int wd;
	cin >> wd;
	return (enWeekDay)wd;
}

string GetWeekDayName(enWeekDay WeekDay)
{

	switch (WeekDay) {

	case enWeekDay::Sun:
		return "Sunday";
		break;
	case enWeekDay::Mon:
		return "Monday";
		break;
	case enWeekDay::Tue:
		return "Tuesday";
		break;
	case enWeekDay::Wed:
		return "Wednesday";
		break;
	case enWeekDay::Thu:
		return "Thursday";
		break;
	case enWeekDay::Fri:
		return "Friday";
		break;
	case enWeekDay::Sat:
		return "Saturday";
		break;
	default:
		return "Not a week day!\n";
	}

}

// ------------- HOMEWORK -------------

// Problem 45 - Month of the Year

enum enMonthName {
    Jan = 1,
    Feb = 2,
    Mar = 3,
    Apr = 4,
    May = 5,
    Jun = 6,
    Jul = 7,
    Aug = 8,
    Sep = 9,
    Oct = 10,
    Nov = 11,
    Dec = 12
};

void ShowMonthMenu() {
    cout << "************************" << endl;
    cout << "       Months           " << endl;
    cout << "************************" << endl;
    cout << "1: January" << endl;
    cout << "2: February" << endl;
    cout << "3: March" << endl;
    cout << "4: April" << endl;
    cout << "5: May" << endl;
    cout << "6: June" << endl;
    cout << "7: July" << endl;
    cout << "8: August" << endl;
    cout << "9: September" << endl;
    cout << "10: October" << endl;
    cout << "11: November" << endl;
    cout << "12: December" << endl;
    cout << "************************" << endl;
    cout << "Please enter the number of the month: ";
}

enMonthName ReadMonthNumber() {
    int number;
    cin >> number;
    return static_cast<enMonthName>(number);
}

string GetMonthName(enMonthName monthNumber) {
    switch (monthNumber) {
    case enMonthName::Jan: return "January";
    case enMonthName::Feb: return "February";
    case enMonthName::Mar: return "March";
    case enMonthName::Apr: return "April";
    case enMonthName::May: return "May";
    case enMonthName::Jun: return "June";
    case enMonthName::Jul: return "July";
    case enMonthName::Aug: return "August";
    case enMonthName::Sep: return "September";
    case enMonthName::Oct: return "October";
    case enMonthName::Nov: return "November";
    case enMonthName::Dec: return "December";
    default: return "Not a valid month!";
    }
}

// Problem 36 - Simple Calculator

enum enOperation { Add = '+', Substract = '-', Mutilply = '*',  Divide = '/' };

void ShowOperationsList()
{
    cout << "************************" << endl;
    cout << "       Operations       " << endl;
    cout << "************************" << endl;
    cout << "+: Add" << endl;
    cout << "-: Substract" << endl;
    cout << "*: Multiply" << endl;
    cout << "/: Divide" << endl;
    cout << "************************" << endl;
    cout << "Please enter the operation: ";
}

void ReadNumbers(float& num1, float& num2)
{

    cout << "Enter first Number: ";
    cin >> num1;

    cout << "Enter Second Number: ";
    cin >> num2;


}

enOperation SelectOperation()
{
    char c;
    cin >> c;

    return enOperation(c);
}

float performCalculation(enOperation operation, float num1, float num2)
{
    switch (operation)
    {

        case enOperation::Add: return num1 + num2;
        case enOperation::Substract: return num1 - num2;
        case enOperation::Mutilply: return num1 * num2;
        case enOperation::Divide: return num1 / num2;
        default: "Wrong Operation!";

    }
}

int main() {

    float num1, num2;

    ShowOperationsList();
    enOperation operation = SelectOperation();

    ReadNumbers(num1, num2);

    cout << num1 << " " << char(operation) << " " << num2 << " = " << performCalculation(operation, num1, num2);

}
