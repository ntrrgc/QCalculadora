#include "calculadora_infix.h"
#include "calculadora.h"
#include "operador.h"
#include "tokenizer.h"
#include <stdexcept>
#include <sstream>
#include <string>
#include <stack>
#include <boost/lexical_cast.hpp>
#include <cctype>

#include <QDebug>
#include <QString>
using namespace std;
using boost::lexical_cast;

namespace infix {

string rpn2text(queue<Palabra> expr) {
    stringstream buf;

    while (!expr.empty()) {
        Palabra palabra = expr.front();
        expr.pop();

        buf << palabra.toString() << " ";
    }
    return buf.str();
}

double calcular(const std::string &expr) {
    queue<Palabra> queue = infix2rpn(expr);
    qDebug(rpn2text(queue).c_str());
    return rpn::calcular(queue);
}

std::queue<Palabra> infix2rpn(const std::string& expr) {
    queue<Palabra> infix_input = tokenize_expr(expr);
    return infix2rpn(infix_input);
}

std::queue<Palabra> infix2rpn(std::queue<Palabra>& infix_input) {
    queue<Palabra> rpn_output;
    stack<Palabra> operator_stack; /* Aquí entran operadores y aperturas de paréntesis */

    while (!infix_input.empty()) {
        Palabra palabra_leida = infix_input.front();
        infix_input.pop();

        switch (palabra_leida.tipo) {
        case Palabra::NUMERO:
            rpn_output.push(palabra_leida);
            break;
        case Palabra::OPERADOR:
        {
            while (!operator_stack.empty()) {
                Palabra palabra_pila = operator_stack.top();

                if (palabra_pila.tipo == Palabra::OPERADOR) {
                    if (palabra_leida.operador() <= palabra_pila.operador()) {
                        rpn_output.push(palabra_pila);
                        operator_stack.pop();
                        continue;
                    }
                }
                break;
            }
            operator_stack.push(palabra_leida);
            break;
        }
        case Palabra::PARENTESIS:
            if (palabra_leida.tipoParentesis() == Palabra::ParentesisApertura) {
                operator_stack.push(palabra_leida);
            } else {
                Palabra op;
                while (!operator_stack.empty() && (op = operator_stack.top()).tipo != Palabra::PARENTESIS) {
                    operator_stack.pop();
                    rpn_output.push(op);
                }
                if (!operator_stack.empty()) {
                    //si lo siguiente que hay en la pila es un paréntesis de apertura (correcto)...
                    operator_stack.pop();
                } else {
                    throw Calculadora::expresion_invalida();
                }
            }
            break;
        default:
            throw Calculadora::expresion_invalida();
        }
    }

    while (!operator_stack.empty()) {
        Palabra op = operator_stack.top();
        operator_stack.pop();
        if (op.tipo != Palabra::PARENTESIS) {
            rpn_output.push(op);
        } else {
            throw Calculadora::expresion_invalida();
        }
    }

    return rpn_output;
}

} //namespace infix
