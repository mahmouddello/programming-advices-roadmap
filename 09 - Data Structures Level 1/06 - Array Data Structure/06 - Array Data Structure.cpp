#include <iostream>
#include "../../cpplibs/clsUtil.h"

using namespace std;

short findNumber(int array[5], int number)
{
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        if (array[i] == number)
            return i;
    }

    return -1;
}

int main()
{
	int array[5] = { 10, 20, 30, 40, 50 };

	cout << array[2] << endl; // random (direct) access, O(1)
    array[1] = 15; // update element -> O(1)
    cout << findNumber(array, 30) << endl; // Traversing all array elements, Worst case O(n)

    clsUtil::printArray(array, 5); // printing all array elements using loop, O(n)

    return 0;
}
