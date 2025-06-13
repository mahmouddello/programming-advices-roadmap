#include <iostream>

using namespace std;

double MySum(double a, double b) {
	return (a + b);
}

int MySum(int a, int b) {
	return (a + b);
}

int MySum(int a, int b, int c) {
	return (a + b + c);
}

int MySum(int a, int b, int c, int d) {
	return (a + b + c + d);
}

// testing parameter order

void mysum(int a, float b) {
	std::cout << "mysum(int, float) called" << std::endl;
}

void mysum(float a, int b) {
	std::cout << "mysum(float, int) called" << std::endl;
}

int main() {

	cout << MySum(10, 20) << endl;
	cout << MySum(10.1, 20.1) << endl;
	cout << MySum(10, 20, 30) << endl;
	cout << MySum(10, 20, 30, 40) << endl;

	mysum(1, 1.1);
	mysum(1.1f, 1);

	return 0;
}