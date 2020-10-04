#ifndef TRXCSV_H
#define TRXCSV_H
#include "./CSVParser.hpp"
#include "./ProductsCSV.hpp"
/**
 * Representa un CSVParser de tipo TrxCSV
 * Extiende el parser para leer específicamente csv formateados como trx
 * @extends CSVParser
 */
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
    /**
* Crea o actualiza una entrada en caso de existir o no una key con el código de barras.
* Además actualiza la cantidad total, sumándole quantity a la ya existente
* @param  barcode Código de barras.
* @param  quantity Cantidad a añadir
*/
    void updateProduct(string barcode, int quantity);

public:
    /**
* @constructor
* @param filepath ruta del archivo.
* @param *productsCSV Referencia a un objeto de tipo ProductsCSV que contenga la información de los productos.
*/
    TrxCSV(string filepath, ProductsCSV *productsCSV);
    /**
* Lee el contenido del archivo, extrae los valores de cada columna y formatear.
* Encontrado el código de barras llama a updateProduct
* @returns ifstream Si encuentra el archivo
*/
    void parse();
    /**
* Guarda el contenido formateado en csv en un archivo
* @param filepath Ruta del archivo a guardar.
*/
    void write(string filepath);
};
#endif