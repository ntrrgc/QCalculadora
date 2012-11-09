#include "calculadora_rpn.h"
#include "calculadora.h"
#include "tokenizer.h"
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <stdexcept>
#include <stack>
using namespace std;

namespace rpn {

double calcular(const std::string& expr) {
    queue<Palabra> queue = tokenize_expr(expr);
    return calcular(queue);
}

double calcular(std::queue<Palabra>& expr) {
    stack<double> pila;

    while (!expr.empty()) {
        Palabra pal = expr.front();
        expr.pop();

        if (pal.tipo == Palabra::NUMERO) {
            pila.push(pal.contenido.numero);
        } else if (pal.tipo == Palabra::OPERADOR) {
            //Comprobación de seguridad...
            if (pila.size() < 2)
                throw Calculadora::expresion_invalida();

            double rhs, lhs;
            rhs = pila.top();
            pila.pop();
            lhs = pila.top();
            pila.pop();
            pila.push(realizar_operacion_binaria(pal.contenido.operador, lhs, rhs));
        } else {
            throw Calculadora::expresion_invalida(); //¿qué pinta un paréntesis en RPN?
        }
    };

    if (pila.size() ==1)
        return pila.top();
    else
        throw Calculadora::expresion_invalida();
}

} //namespace rpn
