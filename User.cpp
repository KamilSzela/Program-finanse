#include "User.h"

int User::getUserId()
{
    return userId;
}
void User::setUserId(int newId)
{
    userId = newId;
}
string User::getUserLogin()
{
    return login;
}
void User::setUserLogin(string newLogin)
{
    login = newLogin;
}
string User::getUserPassword()
{
    return password;
}
void User::setUserPassword(string newPassword)
{
    password = newPassword;
}
string User::getUserName()
{
    return name;
}
void User::setUserName(string newName)
{
    name = newName;
}
string User::getUserSurname()
{
    return surname;
}
void User::setUserSurname(string newSurname)
{
    surname = newSurname;
}
