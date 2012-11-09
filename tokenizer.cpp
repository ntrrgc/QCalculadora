#include "tokenizer.h"
#include "calculadora.h"
#include <boost/lexical_cast.hpp>
#include <stdexcept>
using namespace std;

Palabra::TipoPalabra identificarTipoPalabra(string::const_iterator caracter, Palabra::TipoPalabra tipoPalabraAnterior = Palabra::PARENTESIS) {
    switch (*caracter) {
    case '(':
    case ')':
        return Palabra::PARENTESIS;
    case '+':
    case '/':
    case '*':
        return Palabra::OPERADOR;
    case '-':
    {
        string::const_iterator siguiente_caracter= caracter;
        siguiente_caracter++;
        if (isdigit(*siguiente_caracter))
            if (tipoPalabraAnterior == Palabra::NUMERO)
                return Palabra::OPERADOR;
            else
                return Palabra::NUMERO;
        else
            return Palabra::OPERADOR;
    }
    case '.':
        return Palabra::NUMERO;
    }
    if (isdigit(*caracter)) {
        return Palabra::NUMERO;
    }
    throw Calculadora::expresion_invalida();
}

bool leerPalabra(string::const_iterator& iter, const string::const_iterator end_of_string, Palabra& palabra) {
    //Saltamos los espacios
    while (iter != end_of_string && *iter == ' ')
        iter++;

    if (iter == end_of_string)
        return false;

    switch (identificarTipoPalabra(iter, palabra.tipo)) {
    case Palabra::NUMERO:
    {
        string::const_iterator fin_palabra = iter;
        do {
            fin_palabra++;
        } while (fin_palabra != end_of_string && (isdigit(*fin_palabra) || *fin_palabra == '.'));
        string strnumber(iter, fin_palabra);
        iter = fin_palabra;
        palabra = Palabra(Palabra::NUMERO, boost::lexical_cast<double>(strnumber));
        return true;
    }
    case Palabra::OPERADOR:
    {
        Operador op(*iter);
        iter++;
        palabra = Palabra(Palabra::OPERADOR, op);
        return true;
    }
    case Palabra::PARENTESIS:
    {
        Palabra::TipoParentesis tipoParentesis =
                (*iter == '(' ? Palabra::ParentesisApertura : Palabra::ParentesisCierre);
        iter++;
        palabra = Palabra(Palabra::PARENTESIS, tipoParentesis);
        return true;
    }
    default:
        throw std::runtime_error("Error interno");
    }
}

std::queue<Palabra> tokenize_expr(const std::string& expr) {
    queue<Palabra> queue;
    string::const_iterator iter = expr.begin();
    Palabra palabra;
    while (leerPalabra(iter, expr.end(), palabra)) {
        queue.push(palabra);
    }
    return queue;
}
