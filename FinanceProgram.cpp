#include "FinanceProgram.h"

void FinanceProgram::displayMainMenu()
{
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
}
FinanceProgram::FinanceProgram()
{
    displayMainMenu();
}
