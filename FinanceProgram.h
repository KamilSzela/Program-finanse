#include <iostream>
#include <windows.h>
#include "UserManager.h"

using namespace std;

class FinanceProgram
{
    UserManager userManager;
public:
    void displayMainMenu();
    void displayUserMenu();
    bool checkIfUserIsLogged();
    //FinanceProgram();
    void registerNewUser();
    void showAllUsers();
};
