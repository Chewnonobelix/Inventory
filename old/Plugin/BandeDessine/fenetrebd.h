#ifndef FENETREBD_H
#define FENETREBD_H

#include <QDialog>

#include "bandedessine.h"
#include "bandedessine_global.h"
#include "ajout.h"

namespace Ui {
class FenetreBD;
}

class BANDEDESSINESHARED_EXPORT FenetreBD : public QDialog
{
    Q_OBJECT
    
public:
    explicit FenetreBD(BandeDessine* = NULL, QWidget *parent = 0);
    ~FenetreBD();

    void setModel(BandeDessine* = NULL);
    
private:
    Ui::FenetreBD *ui;
    BandeDessine* m_model;

public slots:
    void accept();
    void ajout();
};

#endif // FENETREBD_H
