#pragma once
class Call
{
	int id, caller_id, called_id;
public:
	Call(int, int);
	int GetCallID(void);
	int GetCallerID(void);
	int GetCalledID(void);
};

