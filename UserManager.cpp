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
    incomes.clear();

    cout << endl << "Wylogowales sie. ";
    Sleep(1000);
}
int UserManager::checkMaxNumberOfDaysInAMonth(int year, int month)
{
      switch (month)
    {
case (1):
case(3):
case(5):
case(7):
case(8):
case(10):
case(12):
    return 31;
    break;
case(4):
case(6):
case(9):
case(11):
    return 30;
    break;
case(2):
    if ((year%4==0&&year%100!=0)||(year%400==0))
       {
           return 29;
       }
    else
       {
           return 28;
       }
}
}
int UserManager::convertStringToInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}
int UserManager::convertStringDateToIntDate(string date)
{
    string temporaryString = "";
     for(int i = 0; i < date.length(); i++)
     {
         if(isdigit(date[i]))
            {
              temporaryString+=date[i];
            }
     }
     int number = convertStringToInt(temporaryString);
     return number;
}
bool UserManager::checkIfDateIsCorrect( string &date )
{
    string year, month, day;
    string temporary;
    int instance = 0;
    for(int i = 0; i < date.length(); i++)
    {
        if(date[i]=='-'||date[i]==','||date[i]=='.')
            {
                i++ ;
                instance++;

                if(instance == 1)
                {
                    year = temporary;
                    temporary = "";
                    if(convertStringToInt(year) < 2000)
                        {
                            cout<< "Niepoprawny rok";
                            return false;
                        }
                }
                if(instance == 2)
                {
                    if (temporary.length() == 1) {month = '0'+ temporary;}
                    else {month = temporary;}
                    temporary = "";
                    if(convertStringToInt(month) < 0 || convertStringToInt(month) > 12)
                    {
                        cout<<"Niepoprawny miesiac";
                        return false;
                    }
                }
            }

            temporary += date[i];

              if(i == date.length()-1)
                {
                     if (temporary.length() == 1) {day = '0'+ temporary;}
                    else {day = temporary;}
                    int maxNumberDays = checkMaxNumberOfDaysInAMonth(convertStringToInt(year), convertStringToInt(month));
                    if(convertStringToInt(day)>maxNumberDays || convertStringToInt(day)<0)
                    {
                        cout<<"Niepoprawna liczba dni";
                        return false;
                    }
                }
                cout << temporary << endl;
    }
    date = year + month + day;
    return true;
}

void UserManager::addNewIncome()
{
    Income newIncome;
    int newIncomeId, newAmount, newdateAfterConversion;

    newIncomeId = fileWithSavedIncomes.getLastIncomeId()+1;

    string newDate, newItem;
    cout << "Dodawanie nowego przychodu pieniedzy" << endl;
    cout << "---------------------------------" << endl;
    do{
        cout << endl << "Podaj date otrzymania przychodu(format rr-mm-dd): ";
       cin >> newDate;
    }while(checkIfDateIsCorrect(newDate)==false);

    newdateAfterConversion = convertStringDateToIntDate(newDate);
    cout << "Podaj zrodlo otrzymania przychodu: ";
    cin.sync();
    getline(cin,newItem);
    cout << "Podaj ilosc otrzymanego przychodu: ";
    cin >> newAmount;
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
    int newExpenceId, newAmount, newdateAfterConversion;

    newExpenceId = fileWithSavedExpences.getLastExpenceId()+1;

    string newDate, newItem;
    cout << "Dodawanie nowego wydatku" << endl;
    cout << "---------------------------------" << endl;
    do{
        cout << endl << "Podaj date otrzymania przychodu(format rr-mm-dd): ";
       cin >> newDate;
    }while(checkIfDateIsCorrect(newDate)==false);

    newdateAfterConversion = convertStringDateToIntDate(newDate);
    cout << "Podaj zrodlo wydatku: ";
    cin.sync();
    getline(cin,newItem);
    cout << "Podaj rozmiar wydatku: ";
    cin >> newAmount;
    newExpence.setMoneyId( newExpenceId );
    newExpence.setUserId( loggedUserId );
    newExpence.setDate( newdateAfterConversion );
    newExpence.setItem( newItem );
    newExpence.setAmount( newAmount );
    expences.push_back(newExpence);
    fileWithSavedExpences.addNewExpenceToAFile(newExpence);

}
void UserManager::displayAllIncomes()
{
      for (int i=0; i < incomes.size(); i++)
   {
       cout<<"Id uzytkownika: " << incomes[i].getUserId()<<endl;
       cout<<"Id przychodu: " << incomes[i].getMoneyId()<<endl;
       cout<<"Data przychodu: " << incomes[i].getDate()<<endl;
       cout<<"Zrodlo przychodu: " << incomes[i].getItem()<<endl;
       cout<<"wartosc przychodu: " << incomes[i].getAmount()<<endl;
   }
   system("pause");
}
void UserManager::displayAllExpences()
{
      for (int i=0; i < expences.size(); i++)
   {
       cout<<"Id uzytkownika: " << expences[i].getUserId()<<endl;
       cout<<"Id wydatku: " << expences[i].getMoneyId()<<endl;
       cout<<"Data wydatku: " << expences[i].getDate()<<endl;
       cout<<"Zrodlo wydatku: " << expences[i].getItem()<<endl;
       cout<<"wartosc wydatku: " << expences[i].getAmount()<<endl;
   }
   system("pause");
}
