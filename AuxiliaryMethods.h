#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertFloatToString(float number);
    static float convertStringToFloat(string number);
    static int convertStringToInt(string number);
    static string convertIntToString(int number);
    static char loadSingleChar();
};

#endif
