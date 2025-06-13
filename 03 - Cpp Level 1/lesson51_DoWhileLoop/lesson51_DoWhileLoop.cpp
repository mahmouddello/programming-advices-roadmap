#include <iostream>

using namespace std;

int ReadIntNumberInRangeWhileLoop(int from, int to)
{
    int number;
     
    cout << "Please enter a number in range [" << from << ", " << to << "]: ";
    cin >> number;

    while (number < from || number > to)
    {
        cout << "Wrong Input" << endl;
        cout << "Please re-enter a number in the specified range: ";
        cin >> number;
    }

    return number;

}

int ReadIntNumberInRangeDoWhileLoop(int from, int to)
{
    int number;

    do {
        cout << "Please enter a number in range [" << from << ", " << to << "]: ";
        cin >> number;
    } while (number < from || number > to);

    return number;
}

int main()
{
    cout << "The number you entered is: " << ReadIntNumberInRangeWhileLoop(18, 45) << endl;
    cout << "The number you entered is: " << ReadIntNumberInRangeDoWhileLoop(18, 45) << endl;
    return 0;
}
