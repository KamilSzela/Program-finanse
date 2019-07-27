#ifndef FINANCEPROGRAM_H
#define FINANCEPROGRAM_H
#include <iostream>
#include <windows.h>
#include "UserManager.h"

using namespace std;

class FinanceProgram
{
    UserManager userManager;
public:
    char displayMainMenu();
    char displayUserMenu();
    bool checkIfUserIsLogged();
    //FinanceProgram();
    void registerNewUser();
    void logUserIn();
    void logUserOut();
    void showAllUsers();
    void addNewIncome();
    void addNewExpence();
    void displaySummaryOfLastMonth();
    void displayAllIncomes();
    void displayAllExpences();
};
#endif
