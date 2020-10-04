
using namespace std;
#include "TrxCSV.hpp"
#include "ProductsCSV.hpp"
int main()
{
    ProductsCSV products("products_taller.csv");
    TrxCSV trx("trx_taller.csv", &products);

    try
    {
        products.parse();
        trx.parse();
        trx.write("output.csv");
    }
    catch (const string &msg)
    {
        cout << msg << endl;
    }
}
