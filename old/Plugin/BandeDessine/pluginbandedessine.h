#ifndef PLUGINBANDEDESSINE_H
#define PLUGINBANDEDESSINE_H

#include "bandedessine_global.h"

#include <QObject>
#include "../../Controlleur/InterfacePlugin.h"
#include "controlleurbd.h"

class BANDEDESSINESHARED_EXPORT PluginBandeDessine:public QObject, public InterfacePlugin
{
    Q_OBJECT
    Q_INTERFACES(InterfacePlugin)
    Q_PLUGIN_METADATA(IID "plugin_bd")

public:
    explicit PluginBandeDessine(QObject* parent = NULL):QObject(parent) {}
    ~PluginBandeDessine() {}

    QString getNomAffichage() const;
    QString getNomFichier() const;
    AbstractControlleur* createControlleur(QString);
    AbstractMedia* create() const;
    QWizardPage* getPage() const;
};

#endif // PLUGINBANDEDESSINE_H
