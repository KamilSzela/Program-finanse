#include "DisplayMoneyManager.h"

string DisplayMoneyManager::changeIntDateToDateWithDashes(int intDate)
{

    string stringDate , str;
    str = AuxiliaryMethods::convertIntToString(intDate);
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
void DisplayMoneyManager::displayIncome(Income income)
{
       cout<<"Id uzytkownika: " << income.getUserId()<<endl;
       cout<<"Id przychodu: " << income.getMoneyId()<<endl;
       string date = changeIntDateToDateWithDashes(income.getDate());
       cout<<"Data przychodu: " << date <<endl;
       cout<<"Zrodlo przychodu: " << income.getItem()<<endl;
       cout<<"wartosc przychodu: " << income.getAmount()<<endl;
}
void DisplayMoneyManager::displayExpence(Expence expence)
{
       cout<<"Id uzytkownika: " << expence.getUserId()<<endl;
       cout<<"Id wydatku: " << expence.getMoneyId()<<endl;
       string date = changeIntDateToDateWithDashes(expence.getDate());
       cout<<"Data wydatku: " << date <<endl;
       cout<<"Zrodlo wydatku: " << expence.getItem()<<endl;
       cout<<"wartosc wydatku: " << expence.getAmount()<<endl;
}
void DisplayMoneyManager::displaySummaryOfLastMonth(vector <Income> incomes, vector <Expence> expences)
{
    float sumOfMoney = 0, sumOfIncomes = 0, sumOfExpences = 0;
    int beginOfCurrentMonth = AuxiliaryMethods::convertStringToInt(dateManager.getCurrentDate()) - dateManager.getTodaysDayOfAMonth();
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
void DisplayMoneyManager::displaySummaryOfPreviousMonth(vector <Income> incomes, vector <Expence> expences)
{
    float sumOfMoney = 0, sumOfIncomes = 0, sumOfExpences = 0;
    int beginOfCurrentMonth = AuxiliaryMethods::convertStringToInt(dateManager.getCurrentDate()) - dateManager.getTodaysDayOfAMonth();
    int previousMonthBegin = AuxiliaryMethods::convertStringToInt(dateManager.getCurrentDate()) - dateManager.getTodaysDayOfAMonth() - 100;
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
void DisplayMoneyManager::displaySummaryOfGivenTime(vector <Income> incomes, vector <Expence> expences)
{
    string firstDate , secondDate;
    int firstDateAfterConversion, secondDateAfterConversion;
    float sumOfMoney = 0, sumOfIncomes = 0, sumOfExpences = 0;
        do
        {
            cout << endl << "Podaj date poczatku okresu z ktorego obliczyc bilans(format rrrr-mm-dd): ";
            cin >> firstDate;
        }while(dateManager.checkIfDateIsCorrect(firstDate)==false);

      do
        {
            cout << endl << "Podaj date konca okresu z ktorego obliczyc bilans(format rrrr-mm-dd): ";
            cin >> secondDate;
        }while(dateManager.checkIfDateIsCorrect(secondDate)==false);

      firstDateAfterConversion = dateManager.convertStringDateToIntDate(firstDate);
      secondDateAfterConversion = dateManager.convertStringDateToIntDate(secondDate);

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
void DisplayMoneyManager::displayAllIncomes(vector <Income> incomes)
{
      for (int i=0; i < incomes.size(); i++)
   {
       displayIncome(incomes[i]);
       cout<<"----------------------" << endl;
   }
   system("pause");
}
void DisplayMoneyManager::displayAllExpences( vector <Expence> expences)
{
      for (int i=0; i < expences.size(); i++)
   {
       displayExpence(expences[i]);
       cout<<"----------------------" << endl;
   }
   system("pause");
}
