#include <iostream>
#include <cstdio>

using namespace std;

int main() {

	float PI = 3.14159265;

	//Precision specification
	// the number of digits after the fraction is specified with an argument
	printf("Precision specification of %.*f\n", 1, PI);
	printf("Precision specification of %.*f\n", 2, PI);

	// Instead of displaying 3.141, it shows 3.142  
	// because the last digit (1) is rounded up due to the next digit being 5.
	printf("Precision specification of %.*f\n", 3, PI);
	printf("Precision specification of %.*f\n", 4, PI); // same here, rounded up 5 to 6 becuase the next digit is 9

	// .3f means i want to print the number in format that has 3 digits after the fraction
	float x = 7.0, y = 9.0;
	printf("\nThe float division is : %.3f / %.3f = %.3f \n\n", x,y, x / y);

	// here we wanted to print 3 digit after the fraction, 
	// we already have 2 digits after the fraction so it adds a zero to their right which has no value
	double d = 12.45;
	printf("The double value is : %.3f \n", d);
	printf("The double value is : %.4f \n", d); // same for this, adds 2 zeros to their right

	return 0;
}