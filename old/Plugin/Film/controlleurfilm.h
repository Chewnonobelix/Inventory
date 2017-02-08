#ifndef CONTROLLEURFILM_H
#define CONTROLLEURFILM_H

#include "../../Controlleur/controlleurplugin.h"
#include "film.h"
#include "fenetrefilm.h"
#include "film_global.h"

class FILMSHARED_EXPORT ControlleurFilm: public AbstractControlleurPlugin
{
    Q_OBJECT

public:
    explicit ControlleurFilm(QString, InterfacePlugin*, QObject* = 0);
    ~ControlleurFilm();

    QStringList getListeSort () const;
    void setVue();
};

#endif // CONTROLLEURFILM_H
