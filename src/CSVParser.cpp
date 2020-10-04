
#include "CSVParser.hpp"
CSVParser::CSVParser(string filepath)
{
    this->filepath = filepath;
}
ifstream CSVParser::read()
{
    ifstream file(this->filepath);
    string value;
    if (!file.good())
    {
        string message = "Problem opening the file";
        throw message + " " + this->filepath;
    }
    return file;
}