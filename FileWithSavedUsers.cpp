#include "FileWithSavedUsers.h"

/*vector <User> FileWithSavedUsers::loadUsersFromAFile()
{
 CMarkup xml;
 vector <User> users;
 bool fileExists = xml.Load("Users.xml");
 if (fileExists == false)
 {
     cout << "Brak zapisanych uzytkownikiow";
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
}*/
