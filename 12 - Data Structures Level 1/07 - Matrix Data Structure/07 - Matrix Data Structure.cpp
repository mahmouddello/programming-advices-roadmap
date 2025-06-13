#include <iostream>

using namespace std;

// Matrix is a derived data structre from array.

int main()
{
    int matrix[5][3] =
    {
        {12, -5, 7},
        {0, 23, -8},
        {14, 3, 19},
        {-2, 9, 6},
        {5, -11, 4}
    };

    cout << matrix[0][1] << endl; // accessing element O(1)
    matrix[2][2] = 999; // updating element O(1)

    // traversal access to matrix elements n rows, m columns -> O(n x m)
    for (short i = 0; i < 5; i++)
    {
        for (short j = 0; j < 3; j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }
        
	return 0;
}