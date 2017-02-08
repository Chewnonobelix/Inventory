#ifndef INTERFACEPLUGIN_H
#define INTERFACEPLUGIN_H

#include <QString>
#include <QtPlugin>

#include "abstractcontrolleur.h"
#include "../pattern/abstractfactory.h"

class CONTROLLEURSHARED_EXPORT InterfacePlugin//: public AbstractFactory<AbstractMedia>
{
public:
    virtual QString getNomAffichage() const = 0;
    virtual QString getNomFichier() const = 0;
    virtual AbstractControlleur* createControlleur(QString) = 0;
    virtual QWizardPage* getPage() const = 0;
    virtual AbstractMedia* create() const = 0;
};

Q_DECLARE_INTERFACE(InterfacePlugin, "InterfacePlugin_IID")
#endif // INTERFACEPLUGIN_H
