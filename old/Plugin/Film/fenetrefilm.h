#ifndef FENETREFILM_H
#define FENETREFILM_H

#include <QDialog>
#include "film_global.h"
#include "film.h"

namespace Ui {
class FenetreFilm;
}

class FILMSHARED_EXPORT FenetreFilm : public QDialog
{
    Q_OBJECT
    
public:
    explicit FenetreFilm(Film* = NULL, QWidget *parent = 0);
    ~FenetreFilm();
    
    void setModel(Film* = NULL);

private:
    Ui::FenetreFilm *ui;
    Film* m_model;

public slots:
    void accept();

};

#endif // FENETREFILM_H
