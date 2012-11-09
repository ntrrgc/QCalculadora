#include "qcalculadora.h"
#include "ui_qcalculadora.h"
#include "calculadora.h"

QCalculadora::QCalculadora(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QCalculadora)
{
    ui->setupUi(this);
    ui->txtExpr->setFocus();
}

QCalculadora::~QCalculadora()
{
    delete ui;
}

void QCalculadora::on_btnCalcular_clicked()
{
    Calculadora::TipoExpresion tipoExpr;
    tipoExpr = ui->radRPN->isChecked() ? Calculadora::RPN : Calculadora::Infix;

    bool exito = false;
    QString resultado, error_msg;
    try {
        double resultado_num = Calculadora::calcular(tipoExpr, ui->txtExpr->text().toStdString());
        resultado = QString::number(resultado_num);
        exito = true;
    } catch (Calculadora::division_por_cero) {
        error_msg = trUtf8("Div/0!");
    } catch (Calculadora::expresion_invalida) {
        error_msg = trUtf8("Expresión inválida");
    } catch (Calculadora::error_interno) {
        error_msg = trUtf8("Error interno");
    }

    if (exito) {
        ui->txtResultado->setText(resultado);
        ui->txtResultado->setAlignment(Qt::AlignRight);
    } else {
        ui->txtResultado->setText(error_msg);
        ui->txtResultado->setAlignment(Qt::AlignCenter);
    }
}
