#ifndef PALABRA_H
#define PALABRA_H

#include "operador.h"

#include <sstream>

struct Palabra {
    enum TipoPalabra {
        OPERADOR,
        NUMERO,
        PARENTESIS
    };
    enum TipoParentesis {
        ParentesisApertura = '(',
        ParentesisCierre = ')'
    };

    Palabra() : tipo(Palabra::PARENTESIS) {}
    Palabra(TipoPalabra tipo, double numero) : tipo(tipo) { contenido.numero = numero; }
    Palabra(TipoPalabra tipo, Operador operador) : tipo(tipo) { contenido.operador = operador.simbolo; }
    Palabra(TipoPalabra tipo, TipoParentesis tipoParentesis) : tipo(tipo) { contenido.tipoParentesis = tipoParentesis; }

    TipoPalabra tipo;

    union {
        double numero;
        char operador;
        TipoParentesis tipoParentesis;
    } contenido;

    double numero() const { return (contenido.numero); }
    double numero(double new_value) { return (contenido.numero = new_value); }
    Operador operador() const { return Operador(contenido.operador); }
    Operador operador(Operador new_value) { return Operador(contenido.operador = new_value.simbolo); }
    TipoParentesis tipoParentesis() const { return (contenido.tipoParentesis); }
    TipoParentesis tipoParentesis(TipoParentesis new_value) { return (contenido.tipoParentesis = new_value); }

    std::string toString() const {
        std::stringstream buf;

        switch (tipo) {
        case OPERADOR:
            buf << operador().simbolo;
            break;
        case PARENTESIS:
            buf << tipoParentesis();
            break;
        case NUMERO:
            buf << numero();
            break;
        default:
            buf << "?";
        }

        return buf.str();
    }
};

#endif // PALABRA_H
