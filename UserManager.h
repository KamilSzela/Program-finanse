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
public:
    UserManager(): loggedUserId(0){};
    void registerNewUser();
    bool checkIfUserisLogged();
    void showAllUsers();
};
