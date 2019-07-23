#ifndef FILEWITHSAVEDEXPENCES_H
#define FILEWITHSAVEDEXPENCES_H
#include <iostream>
#include "Expence.h"
#include <vector>
#include <windows.h>
#include "XMLFile.h"

class FileWithSavedExpences : public XmlFile
{
    int lastExpenceId;
  public:
      FileWithSavedExpences(string fileWithExpences): XmlFile(fileWithExpences){lastExpenceId = 0;};
      void addNewExpenceToAFile(Expence newExpence);
      vector <Expence> loadExpencesFromAFile(int loggedUserId);
      int getLastExpenceId();
};
#endif
