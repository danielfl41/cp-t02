#include "TrxCSV.hpp"
#include "vector"
#include "Utils.hpp"
#include <string>
#include <sstream>
TrxCSV::TrxCSV(string filepath, ProductsCSV *productsCSV) : CSVParser(filepath)
{
    this->productsCSV = productsCSV;
}
void TrxCSV::updateProduct(string barcode, int quantity)
{
    try
    {
        unordered_map<string, element>::iterator result = this->trxs.find(barcode);
        if (result == this->trxs.end())
        {

            array<string, 2> product = this->productsCSV->find(barcode);
            element &element = this->trxs[barcode];
            element.name = product[0];
            element.volume = product[1];
            element.count = quantity;
        }
        else
        {
            element &element = result->second;
            element.count += quantity;
        };
        return;
    }
    catch (const string &msg)
    {
        throw msg;
    }
}
void TrxCSV::parse()
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
            string stringQuantity = Utils::removeCommas(row[1]);
            stringstream streamQuantity(stringQuantity);
            int quantity = 0;
            streamQuantity >> quantity;
            this->updateProduct(barcode, quantity);
            row.clear();
        }
    }
    catch (const string &e)
    {
        throw e;
    }
}
void TrxCSV::write(string filepath)
{
    try
    {
        ofstream outfile;
        outfile.open(filepath);
        outfile << "\"Barcode\";\"Name\";\"Volume\";\"Count\"" << endl;
        for (const auto &result : this->trxs)
        {
            const element element = result.second;
            const string barcode = result.first;
            string count = to_string(element.count);
            string line = "\"" + barcode + "\";\"" + element.name + "\";\"" + element.volume + "\";\"" + count + "\"";
            outfile << line << endl;
        }
        outfile.close();
        return;
    }
    catch (const string &e)
    {
        throw e;
    }
}