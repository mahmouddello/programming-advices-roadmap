#include <iostream>

using namespace std;

void EX1()
{
    for (int i = 1; i <= 10; i++)
    {
        // condition to break
        if (i == 3)
        {
            break;
        }

        cout << i << endl;
    }
}

void FindElement(int arr[10], int number)
{
    for (int i = 0; i <= 10; i++)
    {
        if (arr[i] == 20)
        {
            cout << "Found 20 in the " << i + 1 << ". position in the array." << endl;
            break;
        }
    }
}

int main()
{

    int arr[10] = { 10, 20, 30, 45, 22, 46, 77, 29, 53, 90 };

    FindElement(arr, 20);
}

// arr[10] ( )