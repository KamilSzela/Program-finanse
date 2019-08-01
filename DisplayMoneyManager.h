#ifndef DISPLAYMONEYMANAGER_H
#define DISPLAYMONEYMANAGER_H
#include <iostream>
#include "AuxiliaryMethods.h"
#include "DateManager.h"
#include "Income.h"
#include "Expence.h"
#include <vector>
#include <windows.h>

class DisplayMoneyManager
{
        DateManager dateManager;
        string changeIntDateToDateWithDashes(int intDate);
        void displayIncome(Income income);
        void displayExpence(Expence expence);

    public:

        void displayAllIncomes(vector <Income> incomes);
        void displayAllExpences(vector <Expence> expences);
        void displaySummaryOfLastMonth(vector <Income> incomes, vector <Expence> expences);
        void displaySummaryOfPreviousMonth(vector <Income> incomes, vector <Expence> expences);
        void displaySummaryOfGivenTime(vector <Income> incomes, vector <Expence> expences);
};

#endif
