#include <iostream>
#include "clsMyQueue.h"

using namespace std;

int main()
{
	clsMyQueue<int> myQueue;

	myQueue.push(10);
	myQueue.push(20);
	myQueue.push(30);
	myQueue.push(40);
	myQueue.push(50);

	myQueue.print();

	cout << "Front = " << myQueue.front() << endl;
	cout << "Back = " << myQueue.back() << endl;

	return 0;
}