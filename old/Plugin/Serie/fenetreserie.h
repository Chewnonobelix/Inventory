#ifndef FENETRESERIE_H
#define FENETRESERIE_H

#include <QDialog>
#include <QInputDialog>
#include <QTableWidgetItem>
#include "Serie.h"
#include "serie_global.h"

namespace Ui {
class FenetreSerie;
}

class SERIESHARED_EXPORT FenetreSerie : public QDialog
{
    Q_OBJECT
    
public:
    explicit FenetreSerie(Serie* = NULL, QWidget *parent = 0);
    ~FenetreSerie();
    
    void setModel(Serie* = NULL);

private:
    Ui::FenetreSerie *ui;
    Serie* m_model;

public slots:
    void clique(int, int);
    void ajoute();
    void accept();
    void suppression();
    void finiOui(bool);
    void finiNon();
};

#endif // FENETRESERIE_H
