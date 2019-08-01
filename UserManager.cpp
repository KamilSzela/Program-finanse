# include "UserManager.h"

bool UserManager::checkIfUserisLogged()
{
    if (loggedUserId == 0) return false;
    else return true;
}
int UserManager::returnLastUserId(){
    if(users.empty() == true) return 1;
    else return users.back().getUserId()+1;
}
bool UserManager::checkIfLoginAlreadyExists(string login)
{
     for(int i=0; i < users.size(); i++)
    {
        if(login == users[i].getUserLogin())
        {
            cout << endl << "Podany login juz istnieje. Prosze wpisac inny login." << endl;
            return true;
        }
    }
    return false;
}
User UserManager::loadNewUserData()
{
    User newUser;
    string login, password, name, surname;
    do
    {
    cout << "Podaj swoj login: ";
    cin >> login;
    }while(checkIfLoginAlreadyExists(login) == true);
    cout << "Podaj haslo: ";
    cin >> password;
    cout << "Podaj swoje imie: ";
    cin >> name;
    cout << "Podaj swoje nazwisko: ";
    cin >> surname;
    newUser.setUserId(returnLastUserId());
    newUser.setUserLogin(login);
    newUser.setUserPassword(password);
    newUser.setUserName(name);
    newUser.setUserSurname(surname);
    return newUser;
}
void UserManager::registerNewUser()
{
    User newUser;
    newUser = loadNewUserData();
    users.push_back(newUser);
    fileWithSavedUsers.addNewUserToAFile(newUser);
    cout << endl << "Konto zalozone pomyslnie" << endl << endl;
    Sleep(1500);
}
void UserManager::showAllUsers()
{
   for (int i=0; i < users.size(); i++)
   {
       cout<<users[i].getUserId()<<endl;
       cout<<users[i].getUserName()<<endl;
       cout<<users[i].getUserSurname()<<endl;
       cout<<users[i].getUserLogin()<<endl;
       cout<<users[i].getUserPassword()<<endl;
   }
   system("pause");
}
void UserManager::logUserIn()
{
    string login, password;
    cout << "Prosze podac login: ";
    cin >> login;
    for(vector <User>:: iterator i = users.begin(); i!=users.end(); i++)
    {
        if(login == i -> getUserLogin())
        {
            for(int check = 3; check > 0; check--)
            {
                cout << "Prosze podac haslo: ";
                cin >> password;
                if(password == i -> getUserPassword())
                {
                    cout << "Zalogowales sie.";
                    loggedUserId = i -> getUserId();
                    incomes = fileWithSavedIncomes.loadIncomesFromAFile(loggedUserId);
                    expences = fileWithSavedExpences.loadExpencesFromAFile(loggedUserId);
                    sort(incomes.begin(), incomes.end());
                    sort(expences.begin(), expences.end());
                    return;
                }
                else {
                  cout << "Bledne haslo. Zostaly Ci: " << check - 1 << " proby." << endl;
                  Sleep(1000);
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            loggedUserId = 0;
            return;
        }
    }
    cout << "Nie znaleziono uzytkownika o podanym loginie." << endl;
    system("pause");
    loggedUserId = 0;
}
void UserManager::logUserOut()
{
    loggedUserId = 0;
    cout << endl << "Wylogowales sie. ";
    Sleep(1000);
}

string UserManager::changeCommasToDots(string stringAmount)
{
    string temporary;
    for (int i=0; i<stringAmount.length(); i++)
    {
        if(stringAmount[i] == ',')
        {
            temporary += '.';
        }
        else temporary += stringAmount[i];
    }
    return temporary;
}

void UserManager::addNewIncome()
{
    Income newIncome;
    int newIncomeId, newdateAfterConversion;
    float newAmount;

    newIncomeId = fileWithSavedIncomes.getLastIncomeId()+1;

    string newDate, newItem, newStringAmount;
    cout << "Dodawanie nowego przychodu pieniedzy" << endl;
    cout << "---------------------------------" << endl;
    cout << "Czy dodac przychod z dzisiejsza data(t/n)? " << endl;
    char choice;

    do{
         choice = AuxiliaryMethods::loadSingleChar();
        if (choice == 't')
            {
                newDate = dateManager.getCurrentDate();
                break;
            }
        else if (choice != 'n' && choice != 't')
            cout << "Podales niepoprawny znak, sprobuj ponownie: ";

    }while (choice != 'n');

    if (choice == 'n')
    {
        do{
           cout << endl << "Podaj date otrzymania przychodu(format rrrr-mm-dd): ";
           cin >> newDate;
        }while(dateManager.checkIfDateIsCorrect(newDate)==false);
    }

    newdateAfterConversion = dateManager.convertStringDateToIntDate(newDate);

    cout << "Podaj zrodlo otrzymania przychodu: ";
    cin.sync();
    getline(cin,newItem);
    cout << "Podaj ilosc otrzymanego przychodu: ";
    cin >> newStringAmount;
    newStringAmount = changeCommasToDots(newStringAmount);
    newAmount = AuxiliaryMethods::convertStringToFloat(newStringAmount);

    newIncome.setMoneyId( newIncomeId );
    newIncome.setUserId( loggedUserId );
    newIncome.setDate( newdateAfterConversion );
    newIncome.setItem( newItem );
    newIncome.setAmount( newAmount );
    incomes.push_back(newIncome);
    fileWithSavedIncomes.addNewIncomeToAFile(newIncome);

}
void UserManager::addNewExpence()
{
    Expence newExpence;
    int newExpenceId, newdateAfterConversion;
    float newAmount;

    newExpenceId = fileWithSavedExpences.getLastExpenceId()+1;

    string newDate, newItem, newStringAmount;
    cout << "Dodawanie nowego wydatku" << endl;
    cout << "---------------------------------" << endl;
    cout << "Czy dodac wydatek z dzisiejsza data(t/n)? " << endl;
     char choice;

    do{
         choice = AuxiliaryMethods::loadSingleChar();
        if (choice == 't')
            {
                newDate = dateManager.getCurrentDate();
                break;
            }
        else if (choice != 'n' && choice != 't')
            cout << "Podales niepoprawny znak, sprobuj ponownie: ";

    }while (choice != 'n');

    if(choice == 'n')
    {
        do{
            cout << endl << "Podaj date wydatku(format rrrr-mm-dd): ";
           cin >> newDate;
        }while(dateManager.checkIfDateIsCorrect(newDate)==false);
    }

    newdateAfterConversion = dateManager.convertStringDateToIntDate(newDate);

    cout << "Podaj zrodlo wydatku: ";
    cin.sync();
    getline(cin,newItem);
    cout << "Podaj rozmiar wydatku: ";
    cin >> newStringAmount;
    newStringAmount = changeCommasToDots(newStringAmount);
    newAmount = AuxiliaryMethods::convertStringToFloat(newStringAmount);

    newExpence.setMoneyId( newExpenceId );
    newExpence.setUserId( loggedUserId );
    newExpence.setDate( newdateAfterConversion );
    newExpence.setItem( newItem );
    newExpence.setAmount( newAmount );
    expences.push_back(newExpence);
    fileWithSavedExpences.addNewExpenceToAFile(newExpence);

}
void UserManager::displaySummaryOfLastMonth()
{
   displayMoneyManager.displaySummaryOfLastMonth(incomes, expences);
}
void UserManager::displaySummaryOfPreviousMonth()
{
  displayMoneyManager.displaySummaryOfPreviousMonth(incomes, expences);
}
void UserManager::displaySummaryOfGivenTime()
{
   displayMoneyManager.displaySummaryOfGivenTime(incomes, expences);
}
void UserManager::displayAllIncomes()
{
  displayMoneyManager.displayAllIncomes(incomes);
}
void UserManager::displayAllExpences()
{
  displayMoneyManager.displayAllExpences(expences);
}
void UserManager::changePasswordOfLoggedUser()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserId() == loggedUserId)
        {
            itr -> setUserPassword(newPassword);
            fileWithSavedUsers.changePassword(loggedUserId, newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
}
