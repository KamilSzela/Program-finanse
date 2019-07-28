#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <time.h>
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
    int todaysDayOfAMonth;
    string currentDate;
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
    string getCurrentDateFromUnixTime();
    string convertIntToString(int number);
    char loadSingleChar();
    void displayIncome(Income income);
    void displayExpence(Expence expence);
public:
    UserManager(): fileWithSavedUsers("Users.xml"), fileWithSavedExpences("Expences.xml"), fileWithSavedIncomes("Incomes.xml"){
     loggedUserId = 0;
     todaysDayOfAMonth = 0;
     users = fileWithSavedUsers.loadUsersFromAFile();
     currentDate = getCurrentDateFromUnixTime();
    };
    void setUserId(int newId);
    void logUserIn();
    void logUserOut();
    void registerNewUser();
    bool checkIfUserisLogged();
    void showAllUsers();
    void addNewIncome();
    void addNewExpence();
    void displaySummaryOfLastMonth();
    void displaySummaryOfPreviousMonth();
    void displaySummaryOfGivenTime();
    void displayAllIncomes();
    void displayAllExpences();
};
#endif
