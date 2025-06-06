#pragma once
#include "../cpplibs/clsDate.h"
#include "../cpplibs/clsUtil.h"
#include "../cpplibs/clsPeriod.h"

class clsInputValidate
{
public:
	template <typename T>
	static bool isNumberBetween(T number, T from, T to)
	{
		return number >= from && number <= to;
	}

	template <typename T>
	static T readNumber(const std::string &message = "Please enter a number: ")
	{
		T number;
		std::cout << message;
		std::cin >> number;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. " << message;
			std::cin >> number;
		}
		return number;
	}

	template <typename T>
	static T readNumberBetween(T from, T to)
	{
		T number;
		bool flag = false;
		const string message = "\nPlease enter a number between " + to_string(from) + " - " + to_string(to) + ": ";
		const string errorMessage = "\nInput either not a number or out of range!";
		do
		{
			if (flag)
				std::cout << errorMessage << std::endl;
			number = readNumber(message);
			flag = true;
		} while (!(isNumberBetween(number, from, to)));
		return number;
	}

	static bool isDateBetween(clsDate date1, clsDate startDate, clsDate endDate)
	{
		if (clsDate::isDateBeforeDate(endDate, startDate))
			clsUtil::swap(startDate, endDate);

		return clsPeriod::isDateInPeriod(clsPeriod(startDate, endDate), date1);
	}

	static std::string readString(const std::string &message = "Enter a string: ")
	{
		std::string input;

		std::cout << message;
		std::getline(std::cin >> std::ws, input);

		return input;
	}

	static bool isDateValid(clsDate date)
	{
		return clsDate::isDateValid(date);
	}
};
