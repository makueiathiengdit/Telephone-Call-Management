#pragma once
#include<queue>
class User
{
	int id;
	bool status;
	std::queue<int>incoming_calls;
	std::queue<int>outgoing_calls;
	std::queue<int>unsuccessful_incoming_calls;


public:
	User(void);
	User(int);
	User(int, bool);
	void GenerateRandomStatus(void);
	void SetId(int);
	void TurnOn(void);
	void TurnOff(void);
	int GetId(void);
	void MakeCall(void);
	bool GetStatus(void);
	
	void AddToIncomingCalls(int caller_id);
	void AddToOutgoingCalls(int called_id);
	void LogIncomingCalls(void);
	void LogOutgoingCalls(void);
	void GenerateID(void);
	void SortCallsByCallerID(std::queue<int> list);
};

