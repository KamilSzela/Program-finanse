#ifndef FILEWITHSAVEDUSERS_H
#define FILEWITHSAVEDUSERS_H
#include <iostream>
#include "User.h"
#include <vector>
#include <windows.h>
#include "XMLFile.h"

class FileWithSavedUsers : public XmlFile
{
  public:
      vector <User> loadUsersFromAFile();
      FileWithSavedUsers(string fileWithUsers): XmlFile(fileWithUsers){};
      void addNewUserToAFile(User newUser);
};
#endif
