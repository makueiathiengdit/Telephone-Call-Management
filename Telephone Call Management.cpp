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
    
    int stop = 50;
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
    
   // PrintCallsByUsers(users);
   // PrintCalls(calls);
    cout << "\n\nTotal users: " << users.size() << "\n";
    cout << "Total calls: " << calls.size() << "\n";

}

void MakeCall(vector<User> &users, vector<Call>&calls)
{
   // randomly pick a caller and recipient, caller must be active to make a call
    int caller_index = rand() % users.size();
    int called_index = rand() % users.size();
    users[rand() % users.size()].TurnOn();
    while (users[caller_index].GetStatus() == false || called_index == caller_index)
        caller_index = rand() % users.size();

    users[caller_index].AddToOutgoingCalls(users[called_index].GetId());
    users[called_index].AddToIncomingCalls(users[caller_index].GetId());

    int call_status = users[called_index].GetStatus();
   // std::cout << "Call status: " << (call_status ? "SUCCESSFUL" : "UNSUCCESSFUL") << "\n";
    calls.push_back(Call(users[caller_index].GetId(), users[called_index].GetId(), call_status));
   
}


void ActivateUSer(vector<User>& users)
{
    // if there is any user that is off,
    if (std::any_of(users.begin(), users.end(), [](User user) {return user.GetStatus() == false; }))
    {
        // then try to pick a random user
       int off_id = rand() % users.size();
        while (users[off_id].GetStatus() == true)
            off_id = rand() % users.size();
        users[off_id].TurnOn();
    }
    else {
        // otherwise turn off atleast one user 
        DeActivateUSer(users);
    }

}
void DeActivateUSer(vector<User>& users)
{
    // if there is atleast one active user
    if (std::any_of(users.begin(), users.end(), [](User user) {return user.GetStatus() == true; }))
    {
        // try to pick it
        int on_id = rand() % users.size();
        while (users[on_id].GetStatus() == false)
            on_id = rand() % users.size();
        users[on_id].TurnOff();
    }
    else
    {
        // otherwise make atleast one user active
        ActivateUSer(users);
    }
}

void GenerateUSer(vector<User>& users)
{
    users.push_back(User());
}


void PrintCalls(vector<Call> calls)
{
    std::cout << "\n============ ALL CALLS ==============\n";
    std::cout << "Call ID\tCallerID\tCalledID\tStatus\n";
    for (auto& call : calls)
    {
        std::cout << call.GetCallID() << "\t"
                  << call.GetCallerID() << "\t\t" 
                  << call.GetCalledID() << "\t\t"
                  << call.GetCallStatus() << "\n";
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