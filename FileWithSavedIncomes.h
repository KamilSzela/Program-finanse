#ifndef FILEWITHSAVEDINCOMES_H
#define FILEWITHSAVEDINCOMES_H
#include <iostream>
#include "Income.h"
#include <vector>
#include <windows.h>
#include "XMLFile.h"

class FileWithSavedIncomes : public XmlFile
{
    int lastIncomeId;
  public:
      FileWithSavedIncomes(string fileWithIncomes): XmlFile(fileWithIncomes){ lastIncomeId = 1;};
      void addNewIncomeToAFile(Income newIncome);
      vector <Income> loadIncomesFromAFile(int loggedUserId);
};
#endif
