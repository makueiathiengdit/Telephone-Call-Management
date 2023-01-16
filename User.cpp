#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include "User.h"

std::vector<int>ids;

User::User(void)
{
    this->GenerateID();
    this->GenerateRandomStatus();
    std::cout << "\nCreating user...: " << id << " with status: " << status << "\n";
}
User::User(int id)
{
    this->id = id;
    this->GenerateRandomStatus();
}

User::User(int id, bool status)
{
    this->id = id;
    this->status = status;
}

void User::GenerateRandomStatus(void)
{
    int s = rand();
  
    if ( rand() > rand())
       TurnOff();
    else
        TurnOn();

}

void User::SetId(int id)
{
    this->id = id;
}

void User::TurnOn(void)
{
    status = true;

    if (!unsuccessful_incoming_calls.empty())
    {
        std::cout << "\n-----------------------\n";
        std::cout << "==== MESSAGE FOR USER: " << id << "\n";
        std::cout << "-----------------------\n";
        std::cout << "Following people tried to call you when you were off:\n";
        SortCallsByCallerID(unsuccessful_incoming_calls);
    }
   
}

void User::TurnOff(void)
{
    status = false;
}



int User::GetId(void)
{
    return id;
}

void User::MakeCall(void)
{
    int user = rand() % ids.size();
    while(user == id)
       user =  rand() % ids.size();

    std::cout << id << "\t\t" << user << "\n";
}

bool User::GetStatus(void)
{
    return status;
}

void User::AddToIncomingCalls(int caller_id)
{
    if (!status)
    {
        unsuccessful_incoming_calls.push(caller_id);
    }
    /*else
    {
        std::cout << "\nUser ID: " << id << "\n";
        std::cout << "Incoming call FROM " << caller_id << "\n";
    }*/
   
    incoming_calls.push(caller_id);
}

void User::AddToOutgoingCalls(int called_id)
{
   /* std::cout << "\nUser ID: " << id << "\n";
    std::cout << "Outgoing call TO: " << called_id << "\n";*/
    outgoing_calls.push(called_id);
}

void User::LogIncomingCalls(void)
{
    if (incoming_calls.empty())
        std::cout << "No incoming calls\n";
    else
    {
        int total = incoming_calls.size();
        std::cout << "\n";
        std::cout << total << " incoming calls\n";
        SortCallsByCallerID(incoming_calls);
    }
   
}

void User::LogOutgoingCalls(void)
{
    if (outgoing_calls.empty())
        std::cout << "No outgoing calls\n";
    else
    {
        int total = outgoing_calls.size();
        std::cout << "\n";
        std::cout << total << " outgoing calls\n";
        SortCallsByCallerID(outgoing_calls);
    }
    
}

void User::GenerateID(void)
{
    int uid = rand();
    std::sort(ids.begin(), ids.end());
    while (std::binary_search(ids.begin(), ids.end(), uid))
        uid = rand();
    id = uid;

}

void User::SortCallsByCallerID(std::queue<int> que)
{
    std::unordered_map<int, int>calls_by_caller;
    while (!que.empty())
    {
        int caller_id = que.front();
        calls_by_caller[caller_id]++;
        que.pop();
    }

    for (auto &item : calls_by_caller)
    {
        std::cout << "Caller ID " << item.first << "(" << item.second << ")\n";
    }
}


