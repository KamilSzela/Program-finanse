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
#include "FileWithSavedExpences.h"
#include "FileWithSavedIncomes.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    vector <Income> incomes;
    vector <Expence> expences;
    FileWithSavedUsers fileWithSavedUsers;
    FileWithSavedExpences fileWithSavedExpences;
    FileWithSavedIncomes fileWithSavedIncomes;

    int returnLastUserId();
    User loadNewUserData();
    bool checkIfLoginAlreadyExists(string newLogin);
    bool checkIfDateIsCorrect(string &date);
    int checkMaxNumberOfDaysInAMonth(int year,int month);
    int convertStringDateToIntDate(string date);
    int convertStringToInt(string number);
    string changeIntDateToDateWithDashes(int intDate);
public:
    UserManager(): fileWithSavedUsers("Users.xml"), fileWithSavedExpences("Expences.xml"), fileWithSavedIncomes("Incomes.xml"){
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
    void addNewExpence();
    void displayAllIncomes();
    void displayAllExpences();
};
#endif
