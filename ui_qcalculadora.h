/********************************************************************************
** Form generated from reading UI file 'qcalculadora.ui'
**
** Created: Thu Mar 8 02:04:47 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCALCULADORA_H
#define UI_QCALCULADORA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QCalculadora
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *txtResultado;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtExpr;
    QRadioButton *radRPN;
    QRadioButton *radInfix;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCalcular;

    void setupUi(QDialog *QCalculadora)
    {
        if (QCalculadora->objectName().isEmpty())
            QCalculadora->setObjectName(QString::fromUtf8("QCalculadora"));
        QCalculadora->resize(357, 166);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/calculator-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        QCalculadora->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(QCalculadora);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        txtResultado = new QLineEdit(QCalculadora);
        txtResultado->setObjectName(QString::fromUtf8("txtResultado"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        txtResultado->setFont(font);
        txtResultado->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"font-weight: bold;"));
        txtResultado->setReadOnly(true);

        verticalLayout->addWidget(txtResultado);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(QCalculadora);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtExpr = new QLineEdit(QCalculadora);
        txtExpr->setObjectName(QString::fromUtf8("txtExpr"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtExpr);

        radRPN = new QRadioButton(QCalculadora);
        radRPN->setObjectName(QString::fromUtf8("radRPN"));
        radRPN->setChecked(true);

        formLayout->setWidget(1, QFormLayout::SpanningRole, radRPN);

        radInfix = new QRadioButton(QCalculadora);
        radInfix->setObjectName(QString::fromUtf8("radInfix"));

        formLayout->setWidget(2, QFormLayout::SpanningRole, radInfix);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCalcular = new QPushButton(QCalculadora);
        btnCalcular->setObjectName(QString::fromUtf8("btnCalcular"));
        btnCalcular->setDefault(true);

        horizontalLayout->addWidget(btnCalcular);


        verticalLayout->addLayout(horizontalLayout);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(txtExpr);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(txtExpr, radRPN);
        QWidget::setTabOrder(radRPN, radInfix);
        QWidget::setTabOrder(radInfix, btnCalcular);
        QWidget::setTabOrder(btnCalcular, txtResultado);

        retranslateUi(QCalculadora);

        QMetaObject::connectSlotsByName(QCalculadora);
    } // setupUi

    void retranslateUi(QDialog *QCalculadora)
    {
        QCalculadora->setWindowTitle(QApplication::translate("QCalculadora", "QCalculadora", 0, QApplication::UnicodeUTF8));
        txtResultado->setText(QString());
        label->setText(QApplication::translate("QCalculadora", "&Expresi\303\263n", 0, QApplication::UnicodeUTF8));
        radRPN->setText(QApplication::translate("QCalculadora", "&RPN", 0, QApplication::UnicodeUTF8));
        radInfix->setText(QApplication::translate("QCalculadora", "&Infix", 0, QApplication::UnicodeUTF8));
        btnCalcular->setText(QApplication::translate("QCalculadora", "C&alcular", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QCalculadora: public Ui_QCalculadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCALCULADORA_H
