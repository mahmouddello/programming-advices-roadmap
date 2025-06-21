#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

int main()
{
	clsDynamicArray<int> myDynamicArr(5);

	myDynamicArr.setItem(0, 10);
	myDynamicArr.setItem(1, 20);
	myDynamicArr.setItem(2, 30);
	myDynamicArr.setItem(3, 40);
	myDynamicArr.setItem(4, 50);

	myDynamicArr.print();


	return 0;
}
