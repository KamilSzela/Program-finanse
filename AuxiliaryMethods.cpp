#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertFloatToString(float number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
float AuxiliaryMethods::convertStringToFloat(string number)
{
    float floatNumber;
    istringstream iss(number);
    iss >> floatNumber;

    return floatNumber;
}
int AuxiliaryMethods::convertStringToInt(string number)
{
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}
string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
 char AuxiliaryMethods::loadSingleChar()
 {
     string input = "";
     char charFromKeyboard = {0};
     while (true)
     {
         cin.sync();
         getline(cin,input);
         if(input.length()==1)
         {
             charFromKeyboard = input[0];
             return charFromKeyboard;
         }
         else
            cout << "To nie jest pojedynczy znak. Wpisz ponownie: ";
     }
 }
