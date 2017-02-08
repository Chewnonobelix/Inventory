#ifndef FENETRESUPPLEMENT_H
#define FENETRESUPPLEMENT_H

#include <QDialog>
#include "supplement.h"
#include <QAbstractButton>

namespace Ui {
class FenetreSupplement;
}

class FenetreSupplement : public QDialog
{
    Q_OBJECT
    
public:
    explicit FenetreSupplement(Supplement&, QWidget *parent = 0);
    ~FenetreSupplement();
    
private:
    Ui::FenetreSupplement *ui;

public slots:
    void fermer(QAbstractButton*);
};

#endif // FENETRESUPPLEMENT_H
