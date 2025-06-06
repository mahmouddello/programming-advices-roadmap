#pragma once
#include <iostream>
#include <limits>
#include "../cpplibs/clsDate.h"
#include "../cpplibs/clsUtil.h"
#include "../cpplibs/clsPeriod.h"

using std::string;
using std::to_string;

class clsInputValidate
{
public:
	// Templated numeric methods
	template <typename T>
	static bool isNumberBetween(T number, T from, T to)
	{
		return number >= from && number <= to;
	}

	template <typename T>
	static T readNumber(const string& message = "Please enter a number: ")
	{
		T number;
		std::cout << message << std::endl;
		std::cin >> number;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << message << std::endl;
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
		const string errorMessage = "\nInput either not a number or out of range!\n";

		do
		{
			if (flag)
				std::cout << errorMessage << std::endl;

			number = readNumber<T>(message);
			flag = true;
		} while (!isNumberBetween(number, from, to));

		return number;
	}

	// Non-template methods
	static std::string readString(const string& message = "Enter a string: ")
	{
		std::string input;
		std::cout << message;
		std::getline(std::cin >> std::ws, input);
		return input;
	}

	static bool isDateBetween(clsDate date1, clsDate startDate, clsDate endDate)
	{
		if (clsDate::isDateBeforeDate(endDate, startDate))
			clsUtil::swap(startDate, endDate);

		return clsPeriod::isDateInPeriod(clsPeriod(startDate, endDate), date1);
	}

	static bool isDateValid(clsDate date)
	{
		return clsDate::isDateValid(date);
	}
};
