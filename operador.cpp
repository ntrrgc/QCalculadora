#include "operador.h"
#include <stdexcept>

int compararOperadores(char A, char B) {
    //const Operador prioridad_operadores[] = {'/', '*', '+', '-'};
    unsigned char pri_a, pri_b;
    switch (A) {
    case '/':
        pri_a = 3; break;
    case '*':
        pri_a = 2; break;
    case '+':
        pri_a = 1; break;
    case '-':
        pri_a = 0; break;
    default:
        throw std::out_of_range("Operador inválido");
    }
    switch (B) {
    case '/':
        pri_b = 3; break;
    case '*':
        pri_b = 2; break;
    case '+':
        pri_b = 1; break;
    case '-':
        pri_b = 0; break;
    default:
        throw std::out_of_range("Operador inválido");
    }
    return pri_a - pri_b;
}

bool Operador::operator== (Operador rhs) {
    return simbolo == rhs.simbolo;
}

bool Operador::operator!= (Operador rhs) {
    return simbolo != rhs.simbolo;
}

bool Operador::operator< (Operador rhs) {
    return compararOperadores(simbolo, rhs.simbolo) < 0;
}

bool Operador::operator<= (Operador rhs) {
    return compararOperadores(simbolo, rhs.simbolo) <= 0;
}

bool Operador::operator>= (Operador rhs) {
    return compararOperadores(simbolo, rhs.simbolo) >= 0;
}

bool Operador::operator> (Operador rhs) {
    return compararOperadores(simbolo, rhs.simbolo) > 0;
}
