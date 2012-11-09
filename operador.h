#ifndef OPERADOR_H
#define OPERADOR_H

struct Operador {
    Operador() {}
    Operador(char simbolo) : simbolo(simbolo) {}

    char simbolo;

    bool operator== (Operador rhs);
    bool operator!= (Operador rhs);
    bool operator< (Operador rhs);
    bool operator<= (Operador rhs);
    bool operator>= (Operador rhs);
    bool operator> (Operador rhs);
};

#endif // OPERADOR_H
