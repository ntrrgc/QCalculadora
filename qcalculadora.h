#ifndef QCALCULADORA_H
#define QCALCULADORA_H

#include <QDialog>

namespace Ui {
class QCalculadora;
}

class QCalculadora : public QDialog
{
    Q_OBJECT
    
public:
    explicit QCalculadora(QWidget *parent = 0);
    ~QCalculadora();
    
private slots:
    void on_btnCalcular_clicked();

private:
    Ui::QCalculadora *ui;
};

#endif // QCALCULADORA_H
