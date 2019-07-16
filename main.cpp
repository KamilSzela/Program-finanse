#include <iostream>
#include "FinanceProgram.h"

using namespace std;

int main()
{
    FinanceProgram program(1);

    if(program.checkIfUserIsLogged() == false) program.displayMainMenu();
    else program.displayUserMenu();
    return 0;
}
