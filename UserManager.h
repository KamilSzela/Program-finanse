#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include "User.h"
#include "XMLFile.h"
#include "FileWithSavedUsers.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    FileWithSavedUsers fileWithSavedUsers;

    int returnLastUserId();
    User loadNewUserData();
    bool checkIfLoginAlreadyExists(string newLogin);
public:
    UserManager(): fileWithSavedUsers("Users.xml"){
     loggedUserId = 0;
     users = fileWithSavedUsers.loadUsersFromAFile();
    };
    void setUserId(int newId);
    void logUserIn();
    void logUserOut();
    void registerNewUser();
    bool checkIfUserisLogged();
    void showAllUsers();
};
#endif
