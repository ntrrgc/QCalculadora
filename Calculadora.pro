#-------------------------------------------------
#
# Project created by QtCreator 2012-02-23T00:29:14
#
#-------------------------------------------------

QT       += core gui

TARGET = Calculadora
TEMPLATE = app


SOURCES += main.cpp\
        qcalculadora.cpp \
    calculadora.cpp \
    calculadora_rpn.cpp \
    calculadora_infix.cpp \
    operador.cpp \
    palabra.cpp \
    tokenizer.cpp

HEADERS  += qcalculadora.h \
    calculadora.h \
    calculadora_rpn.h \
    calculadora_infix.h \
    operador.h \
    palabra.h \
    tokenizer.h

FORMS    += qcalculadora.ui

RESOURCES += \
    resource.qrc
