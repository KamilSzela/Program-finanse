#ifndef FILEWITHSAVEDEXPENCES_H
#define FILEWITHSAVEDEXPENCES_H
#include <iostream>
#include "Expence.h"
#include <vector>
#include <windows.h>
#include "XMLFile.h"

class FileWithSavedExpences : public XmlFile
{
  public:
      FileWithSavedExpences(string fileWithExpences): XmlFile(fileWithExpences){};
};
#endif
