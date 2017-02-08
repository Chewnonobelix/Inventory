#ifndef CONTROLLEURSERIE_H
#define CONTROLLEURSERIE_H

#include "../../Controlleur/controlleurplugin.h"
#include "Serie.h"
#include "fenetreserie.h"
#include "serie_global.h"

class SERIESHARED_EXPORT ControlleurSerie: public AbstractControlleurPlugin
{
public:
    explicit ControlleurSerie(QString, InterfacePlugin* , QObject* = 0);
    ~ControlleurSerie(){}

    void setVue();

    QStringList getListeSort () const;
};

#endif // CONTROLLEURSERIE_H
