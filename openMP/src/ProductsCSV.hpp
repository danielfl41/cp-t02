#ifndef PRODUCTSCSV_H
#define PRODUCTSCSV_H
#include "./CSVParser.hpp"
#include <unordered_map>
/**
 * Representa un CSVParser de tipo ProductsCSV
 * Extiende el parser para leer específicamente csv formateados como products
 * @extends CSVParser
 */
class ProductsCSV : protected CSVParser
{
private:
    unordered_map<string, array<string, 2>> products;

public:
    /**
* @constructor
* @param filepath - ruta del archivo.
*/
    ProductsCSV(string filepath);
    /**
* Busca una entrada por código de barra y devuelve su nombre y volumen
* @param  barcode Código de barras.
*/
    array<string, 2> find(string barcode);
    /**
* Lee el contenido del archivo, extrae los valores de cada columna y formatear.
* Posteriormente guarda en un map como key el código de barras y como value, el nombre y volumen en array
*/
    void parse();
};
#endif