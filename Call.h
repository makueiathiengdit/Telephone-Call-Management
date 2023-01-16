#pragma once
class Call
{
	int id, caller_id, called_id, status;
public:
	Call(int, int, int);
	int GetCallID(void);
	int GetCallerID(void);
	int GetCalledID(void);
	int GetCallStatus(void);
};

