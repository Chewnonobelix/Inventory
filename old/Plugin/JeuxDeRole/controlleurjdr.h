#ifndef CONTROLLEURJDR_H
#define CONTROLLEURJDR_H

#include "../../Controlleur/controlleurplugin.h"
#include "fenetrejdr.h"
#include "jeuxderole_global.h"

class JEUXDEROLESHARED_EXPORT ControlleurJDR: public AbstractControlleurPlugin
{
    Q_OBJECT

public:
    ControlleurJDR(QString nom, InterfacePlugin* plugin, QObject* parent = 0): AbstractControlleurPlugin(nom, plugin, parent)
    {
        setVue();
    }
    ~ControlleurJDR(){}

    void setVue ();
    QStringList getListeSort () const;

public slots:
    void modification(bool, Qt::CheckState, QSet<Supplement>);
};

#endif // CONTROLLEURJDR_H
