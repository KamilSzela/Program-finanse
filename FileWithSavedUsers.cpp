#include "FileWithSavedUsers.h"

vector <User> FileWithSavedUsers::loadUsersFromAFile()
{
 CMarkup xml;
 vector <User> users;
 bool fileExists = xml.Load("Users.xml");
 if (fileExists == false)
 {
     cout << "Brak zapisanych uzytkownikiow";
     Sleep(1000);
     return users;
 }
 xml.FindElem();
 xml.IntoElem();
 while(xml.FindElem("USER"))
 {
     User newUser;
     xml.IntoElem();
     xml.FindElem("USER_ID");
     int newUserId = atoi( MCD_2PCSZ(xml.GetData()) );
     newUser.setUserId(newUserId);
     xml.FindElem("LOGIN");
     MCD_STR strSN = xml.GetData();
     newUser.setUserLogin(strSN);
     xml.FindElem("PASSWORD");
     strSN = xml.GetData();
     newUser.setUserPassword(strSN);
     xml.FindElem("NAME");
     strSN = xml.GetData();
     newUser.setUserName(strSN);
     xml.FindElem("SURNAME");
     strSN = xml.GetData();
     newUser.setUserSurname(strSN);
     xml.OutOfElem();
     users.push_back(newUser);
 }
 return users;
}
void FileWithSavedUsers::addNewUserToAFile(User newUser)
{
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(getFileName());
    if(!fileExists)
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("USERS");
    }
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("USER");
    xmlFile.IntoElem();
    xmlFile.AddElem("USER_ID", newUser.getUserId());
    xmlFile.AddElem("LOGIN", newUser.getUserLogin());
    xmlFile.AddElem("PASSWORD", newUser.getUserPassword());
    xmlFile.AddElem("NAME", newUser.getUserName());
    xmlFile.AddElem("SURNAME", newUser.getUserSurname());
    xmlFile.Save("Users.xml");
}
void FileWithSavedUsers::changePassword(int userId, string newPassword)
{
 CMarkup xml;
 bool fileExists = xml.Load("Users.xml");
  if (fileExists == false)
 {
     cout << "Brak zapisanych uzytkownikiow";
     Sleep(1000);
     return;
 }
 xml.FindElem();
 xml.IntoElem();
 while(xml.FindElem("USER"))
 {
     xml.IntoElem();
     xml.FindElem("USER_ID");
     int loadedUserId = atoi( MCD_2PCSZ(xml.GetData()) );
     if(loadedUserId == userId)
     {
         xml.FindElem("PASSWORD");
         xml.SetData(newPassword, 0);
     }
     xml.OutOfElem();
 }
 xml.Save("Users.xml");
}
