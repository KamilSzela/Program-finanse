#include "FileWithSavedIncomes.h"

int FileWithSavedIncomes::getLastIncomeId()
{
    return lastIncomeId;
}
void FileWithSavedIncomes::addNewIncomeToAFile(Income newIncome)
{
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(getFileName());
    lastIncomeId++;
    if(!fileExists)
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("INCOMES");
    }
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("INCOME");
    xmlFile.IntoElem();
    xmlFile.AddElem("MONEY_ID", lastIncomeId);
    xmlFile.AddElem("USER_ID", newIncome.getUserId());
    xmlFile.AddElem("DATE", newIncome.getDate());
    xmlFile.AddElem("ITEM", newIncome.getItem());
    xmlFile.AddElem("AMOUNT", newIncome.getAmount());
    xmlFile.Save("Incomes.xml");

}
vector <Income> FileWithSavedIncomes::loadIncomesFromAFile(int loggedUserId)
{
 CMarkup xml;
 vector <Income> incomes;
 bool fileExists = xml.Load("Incomes.xml");
 if (fileExists == false)
 {
     cout << "Brak zapisanych przychodów";
     Sleep(1000);
     return incomes;
 }
 xml.FindElem();
 xml.IntoElem();
 while(xml.FindElem("INCOME"))
 {
     Income newIncome;
     xml.IntoElem();
     xml.FindElem("MONEY_ID");
     int newMoneyId = atoi( MCD_2PCSZ(xml.GetData()) );
     newIncome.setMoneyId(newMoneyId);
     xml.FindElem("USER_ID");
     int newUserId = atoi( MCD_2PCSZ(xml.GetData()) );
     newIncome.setUserId(newUserId);
     xml.FindElem("DATE");
     int newDate = atoi( MCD_2PCSZ(xml.GetData()) );
     newIncome.setDate(newDate);
     xml.FindElem("ITEM");
     MCD_STR strSN = xml.GetData();
     newIncome.setItem(strSN);
     xml.FindElem("AMOUNT");
     int newAmount = atoi( MCD_2PCSZ(xml.GetData()) );
     newIncome.setAmount(newAmount);
     xml.OutOfElem();
     if(newUserId == loggedUserId)
     { incomes.push_back(newIncome);}
     lastIncomeId = newMoneyId;
 }

 return incomes;
}
