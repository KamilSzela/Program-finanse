#include "FileWithSavedExpences.h"

int FileWithSavedExpences::getLastExpenceId()
{
    return lastExpenceId;
}
void FileWithSavedExpences::addNewExpenceToAFile(Expence newExpence)
{
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(getFileName());
    lastExpenceId++;
    if(!fileExists)
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("EXPENCES");
    }
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("EXPENCE");
    xmlFile.IntoElem();
    xmlFile.AddElem("MONEY_ID", lastExpenceId);
    xmlFile.AddElem("USER_ID", newExpence.getUserId());
    xmlFile.AddElem("DATE", newExpence.getDate());
    xmlFile.AddElem("ITEM", newExpence.getItem());
    xmlFile.AddElem("AMOUNT", newExpence.getAmount());
    xmlFile.Save("Expences.xml");

}
vector <Expence> FileWithSavedExpences::loadExpencesFromAFile(int loggedUserId)
{
 CMarkup xml;
 vector <Expence> expences;
 bool fileExists = xml.Load("Expences.xml");
 if (fileExists == false)
 {
     cout << "Brak zapisanych wydatkow";
     Sleep(1000);
     return expences;
 }
 xml.FindElem();
 xml.IntoElem();
 while(xml.FindElem("EXPENCE"))
 {
     Expence newExpence;
     xml.IntoElem();
     xml.FindElem("MONEY_ID");
     int newMoneyId = atoi( MCD_2PCSZ(xml.GetData()) );
     newExpence.setMoneyId(newMoneyId);
     xml.FindElem("USER_ID");
     int newUserId = atoi( MCD_2PCSZ(xml.GetData()) );
     newExpence.setUserId(newUserId);
     xml.FindElem("DATE");
     int newDate = atoi( MCD_2PCSZ(xml.GetData()) );
     newExpence.setDate(newDate);
     xml.FindElem("ITEM");
     MCD_STR strSN = xml.GetData();
     newExpence.setItem(strSN);
     xml.FindElem("AMOUNT");
     int newAmount = atoi( MCD_2PCSZ(xml.GetData()) );
     newExpence.setAmount(newAmount);
     xml.OutOfElem();
     if(newUserId == loggedUserId)
     { expences.push_back(newExpence);}
     lastExpenceId = newMoneyId;
 }

 return expences;
}
