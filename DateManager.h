#ifndef DATEMANAGER_H
#define DATEMANAGER_H
#include <iostream>
#include "AuxiliaryMethods.h"
#include <vector>
#include <time.h>
#include <windows.h>

class DateManager
{
    string currentDate;
    int todaysDayOfAMonth;
    int checkMaxNumberOfDaysInAMonth(int year,int month);
public:
    DateManager(){
    currentDate = getCurrentDateFromUnixTime(); };
    int convertStringDateToIntDate(string date);
    string getCurrentDateFromUnixTime();
    string getCurrentDate();
    int getTodaysDayOfAMonth();
    bool checkIfDateIsCorrect(string &date);
};

#endif
