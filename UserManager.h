#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include "User.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    int returnLastUserId();
    User loadNewUserData();
    bool checkIfLoginAlreadyExists(string newLogin);
public:
    UserManager(): loggedUserId(0){

    };
    void setUserId(int newId);
    void logUserIn();
    void logUserOut();
    void registerNewUser();
    bool checkIfUserisLogged();
    void showAllUsers();
};
#endif
