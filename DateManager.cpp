#include "DateManager.h"

string DateManager::getCurrentDate()
{
    return currentDate;
}
int DateManager::getTodaysDayOfAMonth()
{
    return todaysDayOfAMonth;
}
string DateManager::getCurrentDateFromUnixTime()
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
int DateManager::convertStringDateToIntDate(string date)
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
int DateManager::checkMaxNumberOfDaysInAMonth(int year, int month)
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
bool DateManager::checkIfDateIsCorrect( string &date )
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
