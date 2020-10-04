
using namespace std;
#include "TrxCSV.hpp"
#include "ProductsCSV.hpp"
int main()
{
    // Instancia las clases, especificando la ruta de los archivos segú el tipo
    ProductsCSV products("products_taller.csv");
    TrxCSV trx("trx_taller.csv", &products);

    try
    {
        // Se realiza un parse sobre el contenido del archivo de productos
        products.parse();
        // Posteriormente se realiza el mismo proceso con el otro archivo
        // Es necesario hacerlo después, porque primeramente se tiene que
        // obtener la información de los productos
        trx.parse();
        // Guarda el contenido generado en el parse de trx en un nuevo archivo
        trx.write("output.csv");
    }
    catch (const string &msg)
    {
        cout << "ERROR:" << endl
             << msg << endl;
    }
}
