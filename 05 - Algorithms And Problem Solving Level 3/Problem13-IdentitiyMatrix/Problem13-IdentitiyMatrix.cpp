#include <iostream>
#include <iomanip>

using namespace std;

bool IsIdentitiyMatrix(int array[3][3], short rows, short columns) {
	
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			// check for diagona elements
			if (i == j && array[i][j] != 1)
				return false;
			// check for rest elements
			else if (array[i][j] != 0)
				return false;
		}
	}
	return true;
}

int main() {

	int identityMatrix[3][3] =
	{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};

	int notIdentityMatrix[3][3] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	if (IsIdentitiyMatrix(identityMatrix, 3, 3))
		cout << "Yes, it's an identitiy matrix." << endl;
	else
		cout << "No, it's not an identity matrix." << endl;

	if (IsIdentitiyMatrix(notIdentityMatrix, 3, 3))
		cout << "\nYes, it's an identitiy matrix." << endl;
	else
		cout << "\nNo, it's not an identity matrix." << endl;

	return 0;
}