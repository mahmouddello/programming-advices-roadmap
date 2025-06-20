#include <iostream>
#include "clsMyStack.h"

using namespace std;

int main()
{
	clsMyStack<int> myStk;

	myStk.push(10);
	myStk.push(20);
	myStk.push(30);
	myStk.push(40);
	myStk.push(50);

	myStk.print();

	cout << "\n\nStack after pop:\n";
	myStk.pop();
	myStk.print();

	cout << "\nStack Top = " << myStk.top();
	cout << "\nStack Bottom = " << myStk.bottom();

	    //Extension #1
    cout << "\n\n Item(2) : " << myStk.getItem(2);
    
    //Extension #2
    myStk.reverse();
    cout << "\n\nStack after reverse() : \n";
    myStk.print();

    //Extension #3
    myStk.updateItem(2, 600);
    cout << "\n\nStack after updating Item(2) to 600 : \n";
    myStk.print();

    //Extension #4
    myStk.insertAfter(2, 800);
    cout << "\n\nStack after Inserting 800 after Item(2) : \n";
    myStk.print();


    //Extension #5
    myStk.insertAtFront(1000);
    cout << "\n\nStack after Inserting 1000 at top: \n";
    myStk.print();

    //Extension #6
    myStk.insertAtBack(2000);
    cout << "\n\nStack after Inserting 2000 at bottom: \n";
    myStk.print();

    //Extension #7
    myStk.clear();
    cout << "\n\nStack after Clear(): \n";
    myStk.print();

	return 0;
}
