#include "Call.h"
int call_count = 0;


Call::Call(int caller_id, int called_id)
{
	id = ++call_count;
	this->caller_id = caller_id;
	this->called_id = called_id;
	
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
