#include <iostream>

using namespace std;

short findNumber1(int array[10], int number)
{
    int n = 10;
    int pos = -1;

    for (int i = 0; i < n; i++)
    {
        if (array[i] == number)
            pos = i;
    }

    return pos;
}

short findNumber2(int array[10], int number)
{
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        if (array[i] == number)
            return i;
    }

    return -1;
}

int main()
{
    int array[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

    cout << findNumber1(array, 30) << endl;
    cout << findNumber2(array, 30) << endl;

    return 0;
}
