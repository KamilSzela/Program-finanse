#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int userId;
    string login, password, name, surname;

public:
    int getUserId();
    void setUserId(int newId);
    string getUserLogin();
    void setUserLogin(string newLogin);
    string getUserPassword();
    void setUserPassword(string newPassword);
    string getUserName();
    void setUserName(string newUserName);
    string getUserSurname();
    void setUserSurname(string newUserSurname);
};

#endif
