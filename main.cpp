#include <iostream>
#include "FinanceProgram.h"

using namespace std;

int main()
{
    FinanceProgram program;

    while(true)
    {
    if(program.checkIfUserIsLogged() == false)
     {
        program.displayMainMenu();
        int choice;
        cin >> choice;
        switch(choice)
        {
        case 1: program.registerNewUser(); break;
        case 2: program.showAllUsers(); break;
        case 3: return 0;
      }
     }
    else program.displayUserMenu();
    }
    return 0;
}
