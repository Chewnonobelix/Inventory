#ifndef FENETRELIVRE_H
#define FENETRELIVRE_H

#include <QDialog>
#include "livre.h"

namespace Ui {
class FenetreLivre;
}

class FenetreLivre : public QDialog
{
    Q_OBJECT
    
public:
    explicit FenetreLivre(Livre* = NULL, QWidget *parent = 0);
    ~FenetreLivre();
    
    void setModel(Livre* = NULL);
private:
    Ui::FenetreLivre *ui;
    Livre* m_model;

public slots:
    void accept();
};

#endif // FENETRELIVRE_H
