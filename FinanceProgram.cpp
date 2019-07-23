#include "FinanceProgram.h"

char FinanceProgram::displayMainMenu()
{
    char choice;
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> choice;
    return choice;
}
char FinanceProgram::displayUserMenu()
{
    system("cls");
    char choice;
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Wyswietl bilans z biezacego miesiaca" << endl;
    cout << "4. Wyswietl bilans z poprzedniego miesiaca" << endl;
    cout << "5. Wyswietl bilans z podanego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> choice;
    return choice;
}
bool FinanceProgram::checkIfUserIsLogged()
{
    bool check = userManager.checkIfUserisLogged();
    return check;
}
void FinanceProgram::logUserIn()
{
    userManager.logUserIn();
}
void FinanceProgram::logUserOut()
{
    userManager.logUserOut();
}
void FinanceProgram::registerNewUser()
{
    userManager.registerNewUser();
}
void FinanceProgram::showAllUsers()
{
    userManager.showAllUsers();
}
void FinanceProgram::addNewIncome()
{
    userManager.addNewIncome();
}
void FinanceProgram::addNewExpence()
{
    userManager.addNewExpence();
}
void FinanceProgram::displayAllIncomes()
{
    userManager.displayAllIncomes();
}
void FinanceProgram::displayAllExpences()
{
    userManager.displayAllExpences();
}
