#ifndef CALCULADORA_INFIX_H
#define CALCULADORA_INFIX_H

#include "calculadora_rpn.h"
#include "palabra.h"

namespace infix {

std::queue<Palabra> infix2rpn(std::queue<Palabra>& infix_input);
std::queue<Palabra> infix2rpn(const std::string& expr);

double calcular(const std::string& expr);

} // namespace infix

#endif // CALCULADORA_INFIX_H
