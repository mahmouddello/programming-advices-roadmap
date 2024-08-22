#include <iostream>

using namespace std;

/*
    Syntax:

    for( initialization; condition; update or step)
    {
        code
    }

*/

void PrintDivider()
{
    cout << "---------------------" << endl;
}

void ForLoopExample1()
{

    for (int i = 1; i <= 5; i++)
    {
        cout << i << endl;
    }

}

void ForLoopExample2()
{

    for (int i = 1; i <= 10; i++)
    {
        cout << "Sob7an Allah" << endl;
    }

}

void ForLoopExample3()
{
    for (int i = 5; i >= 1; i--)
    {
        cout << i << endl;
    }
}

void ForLoopExample4()
{
    for (int i = 0; i <= 10; i += 2)
    {
        // 2 step at a time
        cout << i << endl;
    }
}

// ------------- HOMEWORK -------------

void Problem26(int number)
{
    // Problem #26 - Print Numbers from 1 to N

    for (int i = 1; i <= number; i++)
    {
        cout << i << endl;
    }
}

void Problem27(int number)
{
    // Problem #27 - Print Numbers from N to 1

    for (int i = number; i >= 1; i--)
    {
        cout << i << endl;
    }

}

int Problem28(int number)
{
    // Problem #28 - Print Sum Odd Numbers from 1 to N
    int sum = 0;

    for (int i = 1; i <= number; i++)

    {
        if (i % 2 == 1)
        {
            sum += i;
        }
    }

    return sum;
}

int Problem29(int number)
{
    // Problem #29 - Print Sum Even Numbers from 1 to N

    int sum = 0;

    for (int i = 1; i <= number; i++)

    {
        if (i % 2 == 0)
        {
            sum += i;
        }
    }

    return sum;

}

void Problem31(int number)
{
    // Problem #31 Power of 2,3,4

    for (int i = 2; i <= 4; i++)
    {
        cout << pow(number, i) << endl;
    }

}

int Problem32(int number, int exponent)
{

    int result = 1;

    for (int i = 1; i <= exponent; i++)
    {
        result *= number;
    }

    return result;

}

void Problem46()
{
    // Problem #46 - Print Letters from A to Z
    for (int i = 65; i <= 90; i++)
    {
        cout << char(i) << endl;
    }
}


int main()
{
    Problem46();
    return 0;
}
