#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "palabra.h"
#include <queue>
#include <string>

Palabra::TipoPalabra identificarTipoPalabra(std::string::const_iterator caracter);

bool leerPalabra(std::string::const_iterator& iter,
                 const std::string::const_iterator end_of_string,
                 Palabra& palabra);

std::queue<Palabra> tokenize_expr(const std::string& expr);

#endif // TOKENIZER_H
