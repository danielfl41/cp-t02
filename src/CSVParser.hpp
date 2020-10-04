
#ifndef CSVPARSER_H
#define CSVPARSER_H
#include <fstream>
#include <iostream>
using namespace std;
class CSVParser
{
private:
    string filepath;

public:
    CSVParser(string filepath);
    ifstream read();
};
#endif