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
            char choice = program.displayMainMenu();

            switch(choice)
            {
            case '1': program.registerNewUser(); break;
            case '2': program.logUserIn(); break;
            case '3': program.showAllUsers(); break;
            case '9':  exit(0);
            default: cout << "Niepoprawna opcja, sprobuj ponownie!"; Sleep(1200);
            }
         }
            else{
                  char choiceUserMenu = program.displayUserMenu();

                  switch(choiceUserMenu)
                  {
                      case '1': program.addNewIncome(); break;
                      case '2': program.addNewExpence(); break;
                      case '3': program.displaySummaryOfLastMonth(); break;
                      case '7': program.logUserOut(); break;
                      case '8': program.displayAllIncomes(); break;
                      case '9': program.displayAllExpences(); break;
                      default: cout << "Niepoprawna opcja, sprobuj ponownie!"; Sleep(1200);
                  }
              }
    }
    return 0;
}
