#pragma once
#include <iostream>

class interfaceCommuncation
{
public:
	virtual void sendEmail(std::string title, std::string body = "") = 0;
	virtual void sendFax(std::string title, std::string body = "") = 0;
	virtual void sendSMS(std::string title, std::string body = "") = 0;
};

