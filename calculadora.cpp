#include "calculadora.h"
#include "calculadora_rpn.h"
#include "calculadora_infix.h"
using namespace std;

double Calculadora::calcular(TipoExpresion tipoExpr, const std::string& expr) {
    switch (tipoExpr) {
    case RPN:
        return rpn::calcular(expr);
    case Infix:
        return infix::calcular(expr);
    default:
        throw error_interno();
    }
}

bool isNumeric(const string& stringToCheck)
{
    bool negativo = false;

    if (stringToCheck.empty()) // Las cadenas vacías no son números
        return false;

    // ¿Es un número negativo?
    if (stringToCheck[0] == '-') {
        if (stringToCheck.length() == 1) // ¿Es el operador - , cosa que no es número?
            return false;
        else
            negativo = true;
    }

    return (stringToCheck.find_first_not_of("0123456789.", negativo ? 1 : 0) == string::npos);
}

double realizar_operacion_binaria(char operador, double lhs, double rhs) {
    switch (operador) {
    case '+':
        return lhs+rhs;
    case '-':
        return lhs-rhs;
    case '*':
        return lhs*rhs;
    case '/':
        return lhs/rhs;
    default:
        throw Calculadora::error_interno();
    }
}

bool isOperator(const std::string& stringToCheck) {
    if (stringToCheck.length() == 1) {
        switch (stringToCheck[0]) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        }
    }
    return false;
}
