#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> stkNumbers;

	stkNumbers.push(10);
	stkNumbers.push(20);
	stkNumbers.push(30);
	stkNumbers.push(40);
	stkNumbers.push(50);

	cout << "Count = " << stkNumbers.size() << endl;

	// We can acceess elements by getting the top, and popping until the stack is empty
	cout << "Numbers are:\n";
	while (!stkNumbers.empty())
	{
		// print top element
		cout << stkNumbers.top() << endl;

		// pop the top element
		stkNumbers.pop();
	}

    cout << "_________________" << endl;

    // stack container declaration
    stack<int> MyStack2;
    stack<int> MyStack3;

    // pushing elements into first stack
    MyStack2.push(10);
    MyStack2.push(20);
    MyStack2.push(30);
    MyStack2.push(40);

    // pushing elements into 2nd stack
    MyStack3.push(50);
    MyStack3.push(60);
    MyStack3.push(70);
    MyStack3.push(80);

    // using swap() function to swap elements of stacks
    MyStack2.swap(MyStack3);

    // printing the first stack
    cout << "MyStack1 = ";
    while (!MyStack2.empty()) {
        cout << MyStack2.top() << " ";
        MyStack2.pop();
    }

    // printing the second stack
    cout << endl << "MyStack2 = ";
    while (!MyStack3.empty()) {
        cout << MyStack3.top() << " ";
        MyStack3.pop();
    }

    system("pause>0");

	return 0;
}
