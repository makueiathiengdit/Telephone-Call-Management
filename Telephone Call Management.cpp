/*
* name: Call Management System in C++
* author: Awet Thon
* date : 16-01-23
*/

#include <iostream>
#include <thread>
#include <vector>
#include "Call.h"
#include "User.h"


using namespace std;
void MakeCall(vector<User>&, vector<Call>&);

void ActivateUSer(vector<User>&);
void DeActivateUSer(vector<User>&);
void GenerateUSer(vector<User>&);
void PrintCalls(vector<Call>);
void PrintCallsByUsers(vector<User>);
int main()
{
    std::cout << "Hello World!\n";
   

    vector<User>users;
    vector<Call>calls;
    for (int i = rand() % 10+2; i >= 0; i--)
        GenerateUSer(users);
    
    int stop = 89;
    GenerateUSer(users);
    GenerateUSer(users);
    GenerateUSer(users);
    GenerateUSer(users);
    GenerateUSer(users);

    while (stop>0)
    {
      
        //GenerateUSer(users);
        MakeCall(users, calls);
        cout << "\n";

        ActivateUSer(users);
      
        DeActivateUSer(users);
      
        --stop; 
    }
    
    PrintCallsByUsers(users);
    cout << "\n\nTotal users: " << users.size() << "\n";
    cout << "Total calls: " << calls.size() << "\n";

}

void MakeCall(vector<User> &users, vector<Call>&calls)
{
   
    int caller_index = rand() % users.size();
    int called_index = rand() % users.size();
    users[rand() % users.size()].TurnOn();
    while (users[caller_index].GetStatus() == false || called_index == caller_index)
        caller_index = rand() % users.size();

    users[caller_index].AddToOutgoingCalls(users[called_index].GetId());
    users[called_index].AddToIncomingCalls(users[caller_index].GetId());
    std::cout << "Status: " << (users[called_index].GetStatus() ? "SUCCESSFUL" : "UNSUCCESSFUL") << "\n";
    calls.push_back(Call(users[caller_index].GetId(), users[called_index].GetId()));
   
}


void ActivateUSer(vector<User>& users)
{
    int off_id = rand() % users.size();
    while (users[off_id].GetStatus() == false)
        off_id = rand() % users.size();
    users[off_id].TurnOff();

}
void DeActivateUSer(vector<User>& users)
{
    int on_id = rand() % users.size();
    while (users[on_id].GetStatus() == true)
        on_id = rand() % users.size();
    users[on_id].TurnOn();
}

void GenerateUSer(vector<User>& users)
{
    users.push_back(User());
}


void PrintCalls(vector<Call> calls)
{
    std::cout << "Call ID\tCallerID\tCalledID\n";
    for (auto& call : calls)
    {
        std::cout << call.GetCallID() << "\t" << call.GetCallerID() << "\t\t" << call.GetCalledID() << "\n";
    }
}
void PrintCallsByUsers(vector<User> users)
{
    std::cout << "\n==========CALLS BY USER==========\n";
    for (auto& user : users)
    {
        std::cout << "\nUser Id: " << user.GetId() << "\n";
        user.LogIncomingCalls();
        user.LogOutgoingCalls();
    }
}