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
     int number = AuxiliaryMethods::convertStringToInt(temporaryString);
     return number;
}
bool UserManager::checkIfDateIsCorrect( string &date )
{
    string year, month, day;
    string temporary;
    int instance = 0;
    for(int i = 0; i < date.length(); i++)
    {
        if(!isdigit(date[i])&&date[i]!='-'&&date[i]!=','&&date[i]!='.') {
                cout << "Podales niepoprawny format daty.";
                Sleep(1000);
                return false;
        }
    }
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
                    if(AuxiliaryMethods::convertStringToInt(year) < 2000)
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
                    if(AuxiliaryMethods::convertStringToInt(month) < 0 || AuxiliaryMethods::convertStringToInt(month) > 12)
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
                    int maxNumberDays = checkMaxNumberOfDaysInAMonth(AuxiliaryMethods::convertStringToInt(year), AuxiliaryMethods::convertStringToInt(month));
                    if(AuxiliaryMethods::convertStringToInt(day)>maxNumberDays || AuxiliaryMethods::convertStringToInt(day)<0)
                    {
                        cout<<"Niepoprawna liczba dni";
                        return false;
                    }
                }
    }
    date = year + month + day;
    return true;
}
string UserManager::getCurrentDateFromUnixTime()
{
    string year, month, day, currentDate;
    struct tm *dateFromComputer;
    time_t timeInSeconds;
    time(&timeInSeconds);
    dateFromComputer = localtime(&timeInSeconds);
    year = AuxiliaryMethods::convertIntToString(dateFromComputer->tm_year+1900);
    month = AuxiliaryMethods::convertIntToString(dateFromComputer->tm_mon+1);

    if(month.length() == 1) month = '0' + AuxiliaryMethods::convertIntToString(dateFromComputer->tm_mon+1);
    day = AuxiliaryMethods::convertIntToString(dateFromComputer->tm_mday);

    if(day.length() == 1) day = '0' + AuxiliaryMethods::convertIntToString(dateFromComputer->tm_mday);
    todaysDayOfAMonth = dateFromComputer->tm_mday;
    currentDate = year + month + day;
    return currentDate;
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
                newDate = currentDate;
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
        }while(checkIfDateIsCorrect(newDate)==false);
    }

    newdateAfterConversion = convertStringDateToIntDate(newDate);

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
                newDate = currentDate;
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
        }while(checkIfDateIsCorrect(newDate)==false);
    }

    newdateAfterConversion = convertStringDateToIntDate(newDate);

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
string UserManager::changeIntDateToDateWithDashes(int intDate)
{
    ostringstream ss;
    ss << intDate;
    string str = ss.str();
    string stringDate;
    for (int i=0; i<str.length(); i++)
    {
        stringDate += str[i];
        if(i==3||i==5)
        {
            stringDate += '-';
        }
    }
    return stringDate;
}
void UserManager::displaySummaryOfLastMonth()
{
    float sumOfMoney = 0, sumOfIncomes = 0, sumOfExpences = 0;
    int beginOfCurrentMonth = AuxiliaryMethods::convertStringToInt(currentDate) - todaysDayOfAMonth;
    cout << "Przychody z obecnego miesiaca: " << endl;
    cout << "-------------------------------" << endl;
       for (int i=0; i < incomes.size(); i++)
   {
       if(incomes[i].getDate() >= beginOfCurrentMonth)
       {
           displayIncome(incomes[i]);
           sumOfIncomes += incomes[i].getAmount();
           cout<<"----------------------" << endl;
       }
   }

   cout << "-------------------------------" << endl;
   cout << "Wydatki z obecnego miesiaca: " << endl;
   cout << "-------------------------------" << endl;
       for (int i=0; i < expences.size(); i++)
   {
       if(expences[i].getDate() >= beginOfCurrentMonth)
       {
           displayExpence(expences[i]);
           sumOfExpences += expences[i].getAmount();
           cout<<"----------------------" << endl;
       }
   }
   sumOfMoney = sumOfIncomes - sumOfExpences;
    if (sumOfIncomes == 0) cout << "Brak dochodow w tym miesiacu." << endl;
    else cout << "Suma przychodow z obecnego miesiaca: " << sumOfIncomes << endl;
    if (sumOfExpences == 0) cout << "Brak wydatkow w tym miesiacu." << endl;
    else cout << "Suma wydatkow z obecnego miesiaca: " << sumOfExpences << endl;
    if(sumOfExpences != 0 && sumOfIncomes != 0)
    cout << "Bilans w obecnym miesiacu: " << sumOfMoney << endl;
    system("pause");
}
void UserManager::displaySummaryOfPreviousMonth()
{
    float sumOfMoney = 0, sumOfIncomes = 0, sumOfExpences = 0;
    int beginOfCurrentMonth = AuxiliaryMethods::convertStringToInt(currentDate) - todaysDayOfAMonth;
    int previousMonthBegin = AuxiliaryMethods::convertStringToInt(currentDate) - todaysDayOfAMonth - 100;
    cout << "Przychody z poprzedniego miesiaca: " << endl;
    cout << "-------------------------------" << endl;

       for (int i=0; i < incomes.size(); i++)
   {
       if(incomes[i].getDate() <= beginOfCurrentMonth && incomes[i].getDate() >= previousMonthBegin)
       {
           displayIncome(incomes[i]);
           sumOfIncomes += incomes[i].getAmount();
           cout<<"----------------------" << endl;
       }
   }

   cout << "-------------------------------" << endl;
   cout << "Wydatki z poprzedniego miesiaca: " << endl;
   cout << "-------------------------------" << endl;

       for (int i=0; i < expences.size(); i++)
   {
       if(expences[i].getDate() <= beginOfCurrentMonth && expences[i].getDate() >= previousMonthBegin)
       {
           displayExpence(expences[i]);
           sumOfExpences += expences[i].getAmount();
           cout<<"----------------------" << endl;
       }
   }

    sumOfMoney = sumOfIncomes - sumOfExpences;
    if (sumOfIncomes == 0) cout << "Brak dochodow w poprzednim miesiacu." << endl;
    else cout << "Suma przychodow z poprzedniego miesiaca: " << sumOfIncomes << endl;
    if (sumOfExpences == 0) cout << "Brak wydatkow w poprzednim miesiacu." << endl;
    else cout << "Suma wydatkow z poprzedniego miesiaca: " << sumOfExpences << endl;
    if(sumOfExpences !=0 && sumOfIncomes != 0)
    cout << "Bilans w poprzednim miesiacu: " << sumOfMoney << endl;
    system("pause");
}
void UserManager::displaySummaryOfGivenTime()
{
    string firstDate , secondDate;
    int firstDateAfterConversion, secondDateAfterConversion;
    float sumOfMoney = 0, sumOfIncomes = 0, sumOfExpences = 0;
        do
        {
            cout << endl << "Podaj date poczatku okresu z ktorego obliczyc bilans(format rr-mm-dd): ";
            cin >> firstDate;
        }while(checkIfDateIsCorrect(firstDate)==false);

      do
        {
            cout << endl << "Podaj date konca okresu z ktorego obliczyc bilans(format rr-mm-dd): ";
            cin >> secondDate;
        }while(checkIfDateIsCorrect(secondDate)==false);

      firstDateAfterConversion = convertStringDateToIntDate(firstDate);
      secondDateAfterConversion = convertStringDateToIntDate(secondDate);

    cout << "Przychody z podanego okresu: " << endl;
    cout << "-------------------------------" << endl;

       for (int i=0; i < incomes.size(); i++)
   {
       if(incomes[i].getDate() <= secondDateAfterConversion && incomes[i].getDate() >= firstDateAfterConversion)
       {
           displayIncome(incomes[i]);
           sumOfIncomes += incomes[i].getAmount();
           cout<<"----------------------" << endl;
       }
   }

   cout << "-------------------------------" << endl;
   cout << "Wydatki z podanego okresu: " << endl;
   cout << "-------------------------------" << endl;

       for (int i=0; i < expences.size(); i++)
   {
       if(expences[i].getDate() <= secondDateAfterConversion && expences[i].getDate() >= firstDateAfterConversion)
       {
           displayExpence(expences[i]);
           sumOfExpences += expences[i].getAmount();
           cout<<"----------------------" << endl;
       }
   }

    sumOfMoney = sumOfIncomes - sumOfExpences;
    if (sumOfIncomes == 0) cout << "Brak dochodow w podanym okresie." << endl;
    else cout << "Suma przychodow z podanego okresu: " << sumOfIncomes << endl;
    if (sumOfExpences == 0) cout << "Brak wydatkow w podanym okresie." << endl;
    else cout << "Suma wydatkow z podanego okresu: " << sumOfExpences << endl;
    if(sumOfExpences != 0 && sumOfIncomes != 0)
    cout << "Bilans w podanym okresie: " << sumOfMoney << endl;
    system("pause");
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
void UserManager::displayIncome(Income income)
{
       cout<<"Id uzytkownika: " << income.getUserId()<<endl;
       cout<<"Id przychodu: " << income.getMoneyId()<<endl;
       string date = changeIntDateToDateWithDashes(income.getDate());
       cout<<"Data przychodu: " << date <<endl;
       cout<<"Zrodlo przychodu: " << income.getItem()<<endl;
       cout<<"wartosc przychodu: " << income.getAmount()<<endl;
}
void UserManager::displayExpence(Expence expence)
{
       cout<<"Id uzytkownika: " << expence.getUserId()<<endl;
       cout<<"Id wydatku: " << expence.getMoneyId()<<endl;
       string date = changeIntDateToDateWithDashes(expence.getDate());
       cout<<"Data wydatku: " << date <<endl;
       cout<<"Zrodlo wydatku: " << expence.getItem()<<endl;
       cout<<"wartosc wydatku: " << expence.getAmount()<<endl;
}
void UserManager::displayAllIncomes()
{
      for (int i=0; i < incomes.size(); i++)
   {
       displayIncome(incomes[i]);
       cout<<"----------------------" << endl;
   }
   system("pause");
}
void UserManager::displayAllExpences()
{
      for (int i=0; i < expences.size(); i++)
   {
       displayExpence(expences[i]);
       cout<<"----------------------" << endl;
   }
   system("pause");
}
