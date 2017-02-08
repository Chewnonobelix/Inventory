#ifndef CONTROLLEURLIVRE_H
#define CONTROLLEURLIVRE_H

#include "../../Controlleur/controlleurplugin.h"

#include "fenetrelivre.h"
#include "livre.h"
#include "livre_global.h"
#include "pluginlivre.h"

class LIVRESHARED_EXPORT ControlleurLivre: public AbstractControlleurPlugin
{
private:

public:
    explicit ControlleurLivre(QString,InterfacePlugin*, QObject* = 0);
    ~ControlleurLivre();

    void setVue();
    QStringList getListeSort () const;
};

#endif // CONTROLLEURLIVRE_H
