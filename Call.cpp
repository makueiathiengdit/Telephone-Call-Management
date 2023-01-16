#include <iostream>
#include "Call.h"
int call_count = 0;


Call::Call(int caller_id, int called_id, int status)
{
	id = ++call_count;
	this->caller_id = caller_id;
	this->called_id = called_id;
	this->status = status;

	std::cout << "\n-----------------------\n";
	std::cout << "CALL NO: " << id << "\n";
	std::cout << "-----------------------\n";
	std::cout << "FROM\tTO\tSTATUS\n";
	std::cout << caller_id << "\t" << called_id << "\t" << status << "\n";
}

int Call::GetCallID(void)
{
	return id;
}

int Call::GetCallerID(void)
{
	return caller_id;
}

int Call::GetCalledID(void)
{
	return called_id;
}

int Call::GetCallStatus(void)
{
	return status;
}
