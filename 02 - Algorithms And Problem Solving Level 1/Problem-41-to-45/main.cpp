#include <iostream>

using namespace std;

// Problem Solving in order from #41 to #45

// --------- Problem #41 - Weeks and Days ---------


float ReadNumberOfHours()
{
	float hours;

	do {
		cout << "Enter number of hours: ";
		cin >> hours;
	} while (hours <= 0);
	

	return hours;
}

float CalculateHoursInDays(float hours)
{
	float hoursInDay = 24;
	return hours / hoursInDay;
}

float CalculateHoursInWeeks(float hours)
{
	float hoursInWeek = 24 * 7;

	return hours / hoursInWeek;
}

// --------- Problem #42 - Task Duration In Seconds ---------

enum enSecondsFormats {
	secondsInMinute = 60,
	secondsInHours = secondsInMinute * 60,
	secondsInDays = secondsInHours * 24
};

struct stTaskDuration
{
	int days;
	int hours;
	int minutes;
	int seconds;
};

stTaskDuration ReadTaskDuration()
{
	stTaskDuration taskDuration;

	cout << "Days: ";
	cin >> taskDuration.days;

	cout << "Hours: ";
	cin >> taskDuration.hours;

	cout << "Minutes: ";
	cin >> taskDuration.minutes;

	cout << "Seconds: ";
	cin >> taskDuration.seconds;

	return taskDuration;
}

int CalculateTaskDurationInSeconds(stTaskDuration taskDuration)
{

	int minutesToSeconds = taskDuration.minutes * enSecondsFormats::secondsInMinute;
	int hoursToSeconds = taskDuration.hours * enSecondsFormats::secondsInHours;
	int daysToSeconds = taskDuration.days * enSecondsFormats::secondsInDays;
	int seconds = taskDuration.seconds;

	return seconds + minutesToSeconds + hoursToSeconds + daysToSeconds;

}

void PrintTotalSeconds(float totalSeconds)
{
	cout << totalSeconds << " Seconds" << endl;
}

// --------- Problem #43 - Seconds to Days Hours Minutes Seconds ---------

int ReadTotalSeconds(string message)
{
	int seconds;

	do {
		cout << message;
		cin >> seconds;
	} while(seconds <= 0);

	return seconds;
}

stTaskDuration SecondsToOtherFormats(int totalSeconds)
{
	int remainder;
	stTaskDuration taskDuration;

	taskDuration.days = totalSeconds / enSecondsFormats::secondsInDays;
	remainder = totalSeconds % enSecondsFormats::secondsInDays; // the remainder is the hours in days format

	taskDuration.hours = remainder / enSecondsFormats::secondsInHours;
	remainder = totalSeconds % enSecondsFormats::secondsInHours;

	taskDuration.minutes = remainder / enSecondsFormats::secondsInMinute;
	remainder = totalSeconds % enSecondsFormats::secondsInMinute;

	taskDuration.seconds = totalSeconds % 60;

	return taskDuration;
}

void PrintTotalSecondsInFormat(stTaskDuration taskDuration)
{
	cout << taskDuration.days << ":" << taskDuration.hours << ":" << taskDuration.minutes << ":" << taskDuration.seconds << endl;
}

// --------- Problem #44 - Day Of Week --------- 

enum enDayOfWeek
{
	Sunday = 1,
	Monday = 2,
	Tuesday = 3,
	Wednesday = 4,
	Thursday = 5,
	Friday = 6,
	Saturday = 7
};

enDayOfWeek ReadDayNumber()
{
	int dayNumber;

	do {
		cout << "Enter day number between (1 - 7): ";
		cin >> dayNumber;
	} while (!(dayNumber > 0 && dayNumber < 8));

	return enDayOfWeek(dayNumber);
}

string FetchDayOfWeek(enDayOfWeek dayNumber)
{
	switch (dayNumber)
	{
	case Sunday:
		return "Sunday";
	case Monday:
		return "Monday";
	case Tuesday:
		return "Tuesday";
	case Wednesday:
		return "Wednesday";
	case Thursday:
		return "Thursday";
	case Friday:
		return "Friday";
	case Saturday:
		return "Saturday";
	default:
		break;
	}
}

// --------- Problem #45 - Month of year (Same as #44 logic) --------- 

int main()
{
	cout << "It's " << FetchDayOfWeek(ReadDayNumber()) << endl;
	return 0;
}
