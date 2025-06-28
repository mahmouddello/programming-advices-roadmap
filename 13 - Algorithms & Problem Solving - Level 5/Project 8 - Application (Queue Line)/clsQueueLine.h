#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include "../../cpplibs/clsDate.h"

using namespace std;

class clsQueueLine
{
private:
	class clsTicket
	{
	public:
		string number;
		string date;

		clsTicket(string number)
		{
			this->number = number;
			this->date = clsDate::getSystemDateTime();
		}

		void printInfo()
		{
			printf("\t\t\t\t\t%s\n\t\t\t\t\t%s", this->number.c_str(), this->date.c_str());
		}
	};

	queue<clsTicket> _currentQueue;
	string _prefix;
	unsigned short _serveTime;
	unsigned short _ticketCounter;
	unsigned short _servedCount;
public:
	clsQueueLine(string prefix, unsigned short serveTime)
	{
		this->_prefix = prefix;
		this->_serveTime = serveTime;
		this->_ticketCounter = 0;
		this->_servedCount = 0;
	}

	void printInfo()
	{
		cout << "\n\t\t\t\t\t---------- Queue Info ---------\n";
		cout << "\n\t\t\t\t\tPrefix = " << this->_prefix;
		cout << "\n\t\t\t\t\tTotal Tickets = " << this->_currentQueue.size() + this->_servedCount;
		cout << "\n\t\t\t\t\tServed Clients = " << this->_servedCount;
		cout << "\n\t\t\t\t\tWaiting Clients = " << this->_currentQueue.size();
		cout << "\n\n\t\t\t\t\t-------------------------------\n";

		cout << endl; // flush
	}

	void issueTicket()
	{
		this->_ticketCounter++;
		this->_currentQueue.push(clsTicket(this->_prefix + to_string(this->_ticketCounter)));
	}

	void printTicketsRTL()
	{
		queue<clsTicket> temp = this->_currentQueue; // make a copy
		cout << "\n\t\t\t\t\tTickets RTL: ";
		while (!temp.empty()) {
			cout << temp.front().number << " <-- ";
			temp.pop();
		}
	}

	void printTicketsLTR()
	{
		queue<clsTicket> tempQueue = this->_currentQueue; // make a copy
		stack<clsTicket> tempStack;

		cout << "\n\t\t\t\t\tTickets LTR: ";
		while (!tempQueue.empty()) {
			tempStack.push(tempQueue.front());
			tempQueue.pop();
		}

		while (!tempStack.empty())
		{
			cout << tempStack.top().number << " --> ";
			tempStack.pop();
		}

		cout << "\n" << endl;
	}

	void printAllTickets()
	{
		queue<clsTicket> temp = this->_currentQueue; // make a copy
		short order = 0;

		cout << "\t\t\t\t\t\t--- Tickets ---";

		while (!temp.empty()) {
			cout << "\n\t\t\t\t\t---------------------------\n\n";
			temp.front().printInfo();
			cout << "\n\t\t\t\t\tWaiting Clients = " << order;
			cout << "\n\t\t\t\t\tServe Time In: " << order * this->_serveTime << " Minutes";
			order++;
			temp.pop();
		}

		cout << endl;
	}

	void serveNextClient()
	{
		if (this->_currentQueue.empty())
			cout << "Queue is empty, can't serve any client!" << endl;
		else
		{
			this->_servedCount++;
			this->_currentQueue.pop();
		}
	}
};

