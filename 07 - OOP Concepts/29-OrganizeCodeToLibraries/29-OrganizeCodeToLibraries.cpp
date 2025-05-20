#include <iostream>
#include "clsEmployee.h"

using namespace std;

int main()
{
	clsEmployee employee
	(
		10,
		"Mahmoud",
		"Dello",
		"me@gmail.com",
		"+1 123-456-789",
		"Jr. Software Engineer",
		"Software Development",
		15000
	);
	employee.print();

	return 0;
}