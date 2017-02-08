#ifndef PLUGINSERIE_H
#define PLUGINSERIE_H

#include "serie_global.h"

#include <QObject>
#include "../../Controlleur/InterfacePlugin.h"
#include "controlleurserie.h"
#include "../../pattern/abstractfactory.h"

class SERIESHARED_EXPORT PluginSerie: public QObject, public InterfacePlugin
{
    Q_OBJECT
    Q_INTERFACES(InterfacePlugin)
    Q_PLUGIN_METADATA(IID "plugin_serie")

public:
    explicit PluginSerie(QObject* parent= 0): QObject(parent) {}
    ~PluginSerie(){}

    QString getNomAffichage() const;
    QString getNomFichier() const;
    AbstractControlleur* createControlleur(QString);
    AbstractMedia* create() const;
    QWizardPage* getPage() const;
};

#endif // PLUGINSERIE_H
