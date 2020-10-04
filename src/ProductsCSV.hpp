#ifndef PRODUCTSCSV_H
#define PRODUCTSCSV_H
#include "./CSVParser.hpp"
#include <unordered_map>
class ProductsCSV : protected CSVParser
{
private:
    unordered_map<string, array<string, 2>> products;

public:
    ProductsCSV(string filepath);
    array<string, 2> find(string barcode);
    void parse();
};
#endif