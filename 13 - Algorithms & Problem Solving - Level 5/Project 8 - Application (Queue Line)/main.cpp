#include <iostream>
#include "clsQueueLine.h"

using namespace std;

int main()
{
	clsQueueLine payBillsQueue("A0", 10);

	payBillsQueue.issueTicket();
	payBillsQueue.issueTicket();
	payBillsQueue.issueTicket();
	payBillsQueue.issueTicket();
	payBillsQueue.issueTicket();


	cout << "\nPay Bills queue Info:\n";
	payBillsQueue.printInfo();

	payBillsQueue.printTicketsRTL();
	payBillsQueue.printTicketsLTR();

	payBillsQueue.printAllTickets();

	payBillsQueue.serveNextClient();
	cout << "\nQueue Line after serving one Client:\n";
	payBillsQueue.printInfo();

	clsQueueLine subscriptionQueue("B0", 5);
	subscriptionQueue.issueTicket();
	subscriptionQueue.issueTicket();
	subscriptionQueue.issueTicket();
	subscriptionQueue.issueTicket();
	subscriptionQueue.issueTicket();


	cout << "\nSubscription queue Info:\n";
	subscriptionQueue.printInfo();

	subscriptionQueue.printTicketsRTL();
	subscriptionQueue.printTicketsLTR();

	subscriptionQueue.printAllTickets();

	subscriptionQueue.serveNextClient();
	cout << "\nQueue Line after serving one Client:\n";
	subscriptionQueue.printInfo();

	return 0;
}