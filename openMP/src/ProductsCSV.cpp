#include "ProductsCSV.hpp"
#include <sstream>
#include "Utils.hpp"
ProductsCSV::ProductsCSV(string filepath) : CSVParser(filepath)
{
}
array<string, 2> ProductsCSV::find(string barcode)
{
    unordered_map<string, array<string, 2>> &products = this->products;
    unordered_map<string, array<string, 2>>::iterator result = products.find(barcode);
    try
    {
        if (result == products.end())
            throw "product barcode:" + barcode + " not found";
        return result->second;
    }
    catch (const string &msg)
    {
        throw msg;
    }
}
void ProductsCSV::parse()
{
    try
    {
        ifstream file = this->read();
        string line;
        vector<string> row;
        while (getline(file, line))
        {
            row = Utils::split(line, ';');

            string barcode = Utils::removeCommas(row[0]);
            string name = Utils::removeCommas(row[1]);
            string volume = Utils::removeCommas(row[2]);
            this->products[barcode] = {name, volume};
            row.clear();
        }
    }
    catch (const string &e)
    {
        throw e;
    }
}