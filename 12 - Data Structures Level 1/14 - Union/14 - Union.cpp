#include <iostream>

using namespace std;

union MyUnion
{
	int intValue;
	float floatValue;
	char charValue;
};

int main()
{
	MyUnion myUnion;

    myUnion.intValue = 42;
    cout << "Integer value: " << myUnion.intValue;
    cout << ", Address in memory = " << &myUnion.intValue << endl;

    myUnion.floatValue = 3.14f;
    cout << "Float value: " << myUnion.floatValue;
    cout << ", Address in memory = " << &myUnion.floatValue << endl;

    myUnion.charValue = 'A';
    cout << "Char value: " << myUnion.charValue;
    printf(", Address in memory = %p\n", (void*)&myUnion.charValue);

    return 0;
}