#ifndef XMLFILE_H
#define XMLFILE_H
#include <iostream>
#include <sstream>
#include "Markup.h"

using namespace std;

class XmlFile
{
    const string XML_FILE_NAME;

public:
    XmlFile(string filename): XML_FILE_NAME(filename) {};
    string getFileName();
};

#endif
