#pragma once
#include "../cpplibs/clsDate.h"
#include "../cpplibs/clsUtil.h"
#include "../cpplibs/clsPeriod.h"

class clsInputValidate
{
public:
	static bool isNumberBetween(int number, int from, int to)
	{
		return number >= from && number <= to;
	}

	static bool isNumberBetween(double number, double from, double to)
	{
		return number >= from && number <= to;
	}

	static bool isDateBetween(clsDate date1, clsDate startDate, clsDate endDate)
	{
		if (clsDate::isDateBeforeDate(endDate, startDate))
			clsUtil::swap(startDate, endDate);

		return clsPeriod::isDateInPeriod(clsPeriod(startDate, endDate), date1);
	}

	static int readIntNumber(const std::string &message)
	{
		int number = 0;

		std::cout << "Please enter a number?" << std::endl;
		std::cin >> number;

		while (std::cin.fail())
		{
			// user didn't input a number
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << message << std::endl;
			std::cin >> number;
		}

		return number;
	}

	static std::string readString(const std::string &message = "Enter a string: ")
	{
		std::string input;

		std::cout << message;
		std::getline(std::cin >> std::ws, input);

		return input;
	}

	static int readIntNumberBetween(short from, short to, std::string message)
	{
		int number = 0;
		bool flag = false;
		do
		{
			if (flag)
				std::cout << message << std::endl;

			number = readIntNumber("Invalid number, enter another one: ");
			flag = true;
		} while (!(isNumberBetween(number, from, to)));

		return number;
	}

	static double readDoubleNumber(const std::string &message)
	{
		double number = 0;

		std::cout << message;
		std::cin >> number;

		while (std::cin.fail())
		{
			// user didn't input a number
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << message << std::endl;
			std::cin >> number;
		}

		return number;
	}

	static double readDoubleNumberBetween(double from, double to, std::string message)
	{
		double number = 0;
		bool flag = false;
		do
		{
			if (flag)
				std::cout << message << std::endl;

			number = readDoubleNumber("Invalid number, enter another one: ");
			flag = true;
		} while (!(isNumberBetween(number, from, to)));

		return number;
	}

	static bool isDateValid(clsDate date)
	{
		return clsDate::isDateValid(date);
	}
};
