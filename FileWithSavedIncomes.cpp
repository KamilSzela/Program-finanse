#include "FileWithSavedIncomes.h"

int FileWithSavedIncomes::getLastIncomeId()
{
    return lastIncomeId;
}
string FileWithSavedIncomes::changeIntDateToDateWithDashes(int intDate)
{
    ostringstream ss;
    ss << intDate;
    string str = ss.str();
    string stringDate;
    for (int i=0; i<str.length(); i++)
    {
        stringDate += str[i];
        if(i==3||i==5)
        {
            stringDate += '-';
        }
    }
    return stringDate;
}


string FileWithSavedIncomes::changeDateWithDashesToNumbersOnlyDate(string dateWithDashes)
{
    string dateNumbersOnly;
    for(int i=0; i<dateWithDashes.length(); i++)
    {
        if(dateWithDashes[i] == '-') i++;
        dateNumbersOnly += dateWithDashes[i];
    }
    return dateNumbersOnly;
}
void FileWithSavedIncomes::addNewIncomeToAFile(Income newIncome)
{
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(getFileName());
    lastIncomeId++;
    string dateWithDashes = changeIntDateToDateWithDashes(newIncome.getDate());
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
    xmlFile.AddElem("DATE", dateWithDashes);
    xmlFile.AddElem("ITEM", newIncome.getItem());
    string amountString = AuxiliaryMethods::convertFloatToString(newIncome.getAmount());
    xmlFile.AddElem("AMOUNT", amountString);
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
     MCD_STR dateFromFile = xml.GetData();
     dateFromFile = changeDateWithDashesToNumbersOnlyDate(dateFromFile);
     int dateFromFileAfterConversion = atoi(dateFromFile.c_str());
     newIncome.setDate(dateFromFileAfterConversion);
     xml.FindElem("ITEM");
     MCD_STR strSN = xml.GetData();
     newIncome.setItem(strSN);
     xml.FindElem("AMOUNT");
     float newAmount = atof( MCD_2PCSZ(xml.GetData()) );
     newIncome.setAmount(newAmount);
     xml.OutOfElem();
     if(newUserId == loggedUserId)
     { incomes.push_back(newIncome);}
     lastIncomeId = newMoneyId;
 }

 return incomes;
}
