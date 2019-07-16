#include <iostream>
#include <windows.h>

using namespace std;

class FinanceProgram
{
    int userId;
public:
    void displayMainMenu();
    void displayUserMenu();
    bool checkIfUserIsLogged();
    FinanceProgram(int id = 0);
};
