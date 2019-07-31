#ifndef FILEWITHSAVEDEXPENCES_H
#define FILEWITHSAVEDEXPENCES_H
#include <iostream>
#include <sstream>
#include "Expence.h"
#include "AuxiliaryMethods.h"
#include <vector>
#include <windows.h>
#include "XMLFile.h"

class FileWithSavedExpences : public XmlFile
{
    int lastExpenceId;
    string changeIntDateToDateWithDashes(int intDate);
    string changeDateWithDashesToNumbersOnlyDate(string dateWithDashes);
  public:
      FileWithSavedExpences(string fileWithExpences): XmlFile(fileWithExpences){lastExpenceId = 0;};
      void addNewExpenceToAFile(Expence newExpence);
      vector <Expence> loadExpencesFromAFile(int loggedUserId);
      int getLastExpenceId();
};
#endif
