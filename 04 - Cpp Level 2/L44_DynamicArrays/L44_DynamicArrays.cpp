#include <iostream>

using namespace std;

int main() {

	int num;
	cout << "Please enter the number of students? ";
	cin >> num;

	cout << endl;

	// dynamic array (memory slots allocated during runtime of num)
	float* ptr = new float[num];

	cout << "Enter Students Grades:" << endl;

	for (int i = 0; i < num; i++)
	{
		cout << "Student " << i + 1 << " Grade: ";
		cin >> *(ptr + i); // access to array elements through pointer
	}

	cout << endl;

	for (int j = 0; j < num; j++)
	{
		cout << "Student " << j + 1 << " Grade: ";
		cout << *(ptr + j) << endl;
	}

	// deallocate memory (array)
	delete[] ptr;

	return 0;
}
