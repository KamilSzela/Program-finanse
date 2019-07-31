#ifndef FILEWITHSAVEDINCOMES_H
#define FILEWITHSAVEDINCOMES_H
#include <iostream>
#include "Income.h"
#include "AuxiliaryMethods.h"
#include <vector>
#include <windows.h>
#include "XMLFile.h"

class FileWithSavedIncomes : public XmlFile
{
    int lastIncomeId;
    string changeIntDateToDateWithDashes(int intDate);
    string changeDateWithDashesToNumbersOnlyDate(string dateWithDashes);
  public:
      FileWithSavedIncomes(string fileWithIncomes): XmlFile(fileWithIncomes){ lastIncomeId = 0;};
      void addNewIncomeToAFile(Income newIncome);
      vector <Income> loadIncomesFromAFile(int loggedUserId);
      int getLastIncomeId();
};
#endif
