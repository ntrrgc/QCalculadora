#ifndef CALCULADORA_RPN_H
#define CALCULADORA_RPN_H

#include <queue>
#include <string>
#include "palabra.h"

namespace rpn {

double calcular(std::queue<Palabra>& expr);
double calcular(const std::string& expr);

} //namespace rpn

#endif // CALCULADORA_RPN_H
