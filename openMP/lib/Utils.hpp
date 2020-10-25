#ifndef UTILS_H
#define UTILS_H
#include "vector"
#include "string"
#include <sstream>

class Utils
{
public:
    /**
* Convierte un string a un vector en base a un delimitador
* @param &s referencia al string a e ditar.
* @param delimiter delimitador para hacer el split
*/
    static vector<string> split(const string &s, char delimiter)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }
    /**
* Remueve las doble comillas iniciales y finales de una palabra
* @param word Palabra a la cual se le removerán las doble comillas
*/
    static string removeCommas(string word)
    {
        if (word[0] == '"')
            word.erase(0, 1);
        int lastIndex = word.size() - 1;
        if (word[lastIndex] == '"')
            word.erase(lastIndex);
        return word;
    }
};
#endif