
#ifndef CSVPARSER_H
#define CSVPARSER_H
#include <fstream>
#include <iostream>
using namespace std;
/**
 * Clase que representa un archivo a ser leído
 */
class CSVParser
{
private:
    string filepath;

public:
    /**
* @constructor
* @param filepath ruta del archivo.
*/
    CSVParser(string filepath);
    /**
* Abre el archivo
 * @returns ifstream Si encuentra el archivo
 */
    ifstream read();
};
#endif