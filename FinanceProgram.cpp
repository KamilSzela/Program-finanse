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
void FinanceProgram::displayUserMenu()
{
        system("cls");
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
}
bool FinanceProgram::checkIfUserIsLogged()
{
    if (userId == 0) return false;
    else return true;
}
FinanceProgram::FinanceProgram(int id)
{
    userId = id;
}
