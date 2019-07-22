#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <sstream>
#include <vector>
#include <windows.h>
#include <string>
#include "User.h"
#include "Income.h"
#include "XMLFile.h"
#include "FileWithSavedUsers.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    vector <Income> incomes;
    FileWithSavedUsers fileWithSavedUsers;

    int returnLastUserId();
    User loadNewUserData();
    bool checkIfLoginAlreadyExists(string newLogin);
    bool checkIfDateIsCorrect(string &date);
    int checkMaxNumberOfDaysInAMonth(int year,int month);
    int convertStringDateToIntDate(string date);
    int convertStringToInt(string liczba);
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
    void addNewIncome();
    void displayAllIncomes();
};
#endif
