#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> myQueue;
	queue<int> myQueue2;

	myQueue.push(10);
	myQueue.push(20);
	myQueue.push(30);
	myQueue.push(40);

	cout << "Queue Size = " << myQueue.size() << endl;
	cout << "Front = " << myQueue.front() << endl;
	cout << "Back = " << myQueue.back() << endl;

	queue<int> temp = myQueue;

	cout << "\nQueue1 Elements:\n";
	while (!temp.empty())
	{
		cout << temp.front() << " ";
		temp.pop();
	}

	// SWAP QUEUES

	myQueue2.push(100);
	myQueue2.push(200);
	myQueue2.push(300);
	myQueue2.push(400);

	myQueue.swap(myQueue2);

	cout << "\n_________\nSwap Queues";

	cout << "\n\nQueue1 Elements:\n";
	while (!myQueue.empty())
	{
		cout << myQueue.front() << " ";
		myQueue.pop();
	}

	cout << "\n\nQueue2 Elements:\n";
	while (!myQueue2.empty())
	{
		cout << myQueue2.front() << " ";
		myQueue2.pop();
	}

	return 0;
}