#ifndef TRXCSV_H
#define TRXCSV_H
#include "./CSVParser.hpp"
#include "./ProductsCSV.hpp"
class TrxCSV : protected CSVParser
{
private:
    ProductsCSV *productsCSV;
    struct element
    {
        string name;
        string volume;
        int count;
    };
    unordered_map<string, element> trxs;
    void updateProduct(string barcode, int quantity);

public:
    TrxCSV(string filepath, ProductsCSV *productsCSV);
    void parse();
    void write(string filepath);
};
#endif