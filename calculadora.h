#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <string>

class Calculadora
{
public:
    enum TipoExpresion {
        RPN,
        Infix
    };

    struct expresion_invalida {};
    struct division_por_cero {};
    struct error_interno {};

    static double calcular(TipoExpresion tipoExpr, const std::string &expr);
};

bool isNumeric(const std::string &stringToCheck);
bool isOperator(const std::string &stringToCheck);
double realizar_operacion_binaria(char operador, double lhs, double rhs);

#endif // CALCULADORA_H
