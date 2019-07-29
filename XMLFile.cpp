#include "XMLFile.h"

string XmlFile::getFileName()
{
    return XML_FILE_NAME;
}
string XmlFile::convertFloatToString(float number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
