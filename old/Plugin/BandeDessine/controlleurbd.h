#ifndef CONTROLLEURBD_H
#define CONTROLLEURBD_H

#include "../../Controlleur/controlleurplugin.h"
#include "bandedessine.h"
#include "fenetrebd.h"
#include "bandedessine_global.h"

class BANDEDESSINESHARED_EXPORT ControlleurBD: public AbstractControlleurPlugin
{
    Q_OBJECT
public:
    explicit ControlleurBD(QString , InterfacePlugin*, QObject* = 0);

    ~ControlleurBD() {}

    QStringList getListeSort () const;

    void setVue();
};

#endif // CONTROLLEURBD_H
