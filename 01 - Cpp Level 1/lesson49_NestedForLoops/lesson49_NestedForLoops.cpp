#include <iostream>

using namespace std;

void PrintDivider()
{
    cout << "-----------------------------------\n" << endl;
}

void NestedLoop_Example1()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << "i = " << i << endl;

        for (int j = 1; j <= 10; j++)
        {
            cout << i << " * " << j << " = " << i * j << endl;
        }

        cout << "------------------" << endl;
    }
}

void NestedLoop_Example2()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << "*";
        }

        cout << "\n";
    }
}

void NestedLoop_Example3()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " * ";
        }

        cout << "\n";
    }
}

// --------------------- HOMEWORK ---------------------

void Question1()
{
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            cout << char(i) << char(j) << endl;
        }

        cout << "--" << endl;
    }
}

void Question2()
{
    for (int i = 10; i >= 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " * ";
        }

        cout << "\n";
    }
}

void Question3()
{
    for (int i = 10; i >= 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " " << j;
        }

        cout << "\n";
    }
}

void Question4()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " " << j;
        }

        cout << "\n";
    }
}

void Question5()
{
    for (int i = 65; i <= 70; i++)
    {
        for (int j = 65; j <= i; j++)
        {
            cout << " " << char(j);
        }

        cout << "\n";
    }
}

void Question6()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = i; j <= 10; j++)
        {
            cout << j << " ";
        }

        cout << "\n";
    }
}

// --------- Exercises ---------

void ex1()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = i; j <= 5; j++)
        {
            cout << j << " ";
        }

        cout << "\n";
    }

    
}

int main()
{
    ex1();
    return 0;
}