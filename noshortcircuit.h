#ifndef NOSHORTCIRCUIT_H
#define NOSHORTCIRCUIT_H

#define noShortCircuitAnd(expr1,expr2) \
    ( expr1 ? (expr2) : false )

#endif // NOSHORTCIRCUIT_H
