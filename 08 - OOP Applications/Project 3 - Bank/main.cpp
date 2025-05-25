#include <iostream>
#include "clsBankClient.h"

using namespace std;

int main()
{

	clsBankClient client1 = clsBankClient::find("A101");
	client1.print();

	clsBankClient client2 = clsBankClient::find("A101", "1234");
	client2.print();
	
	clsBankClient client3 = clsBankClient::find("A101", "12345");
	client3.print(); // dummy data, doesn't exist


	return 0;
}