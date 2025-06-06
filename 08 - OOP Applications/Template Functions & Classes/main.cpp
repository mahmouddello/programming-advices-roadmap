#include <iostream>
#include "clsInputValidate.h"

using namespace std;

/*
    Template functions reduce code duplication by allowing a single function
    to work with multiple data types. Without templates, you would need to
    create separate overloaded functions for each data type.

    Example: A max function without templates would require separate versions
    for int, float, double, etc. With templates, one function can find the
    maximum of any two comparable values.
*/

template <typename T> T myMax(T number1, T number2)
{
    return (number1 > number2) ? number1 : number2;
}

/*
    Template classes reduce code duplication by allowing a single class
    to work with multiple data types. Without templates, you would need to
    create separate class definitions for each data type.

    Example: A Calculator class without templates would require separate
    versions for int, float, double, etc. With templates, one Calculator
    class can perform arithmetic operations on any numeric type.
*/

template <class T>
class calculator
{
private:
    T _number1;
    T _number2;
public:
    calculator(T number1, T number2)
    {
        _number1 = number1;
        _number2 = number2;
    }

    void printResults()
    {
        cout << "Numbers: " << _number1 << " And " << _number2 << endl;
        cout << _number1 << " + " << _number2 << " = " << add() << endl;
        cout << _number1 << " - " << _number2 << " = " << substract() << endl;
        cout << _number1 << " * " << _number2 << " = " << multiply() << endl;
        cout << _number1 << " / " << _number2 << " = " << divide() << endl;
    }

    T add()
    {
        return _number1 + _number2;
    }

    T substract()
    {
        return _number1 - _number2;
    }

    T multiply()
    {
        return _number1 * _number2;
    }

    T divide()
    {
        return _number1 / _number2;
    }
};

int main()
{
    cout << myMax<int>(3, 7) << endl; // if we pass a double or float, it will be implicitly converted to an int
    cout << myMax<double>(5.3, 9.2) << endl; // myMax for double
    cout << myMax<char>('a', 'z') << endl; // myMax for char (a = 97, z = 122)
    cout << "\n--------------------------\n";

    // Template Class

    calculator<int> intCalc(1, 3);
    calculator<float> floatCalc(5.2, 8.1);

    cout << "INT RESULTS:\n"; 
    intCalc.printResults();

    cout << "\nFLOAT RESULTS:\n"; 
    floatCalc.printResults();
    cout << "\n--------------------------\n";

    int x = clsInputValidate::readNumberBetween<int>(1, 5);
    cout << x << endl;

    return 0;
}