#ifndef PLUGINJEUXFIGURINE_H
#define PLUGINJEUXFIGURINE_H


#include "../../Controlleur/InterfacePlugin.h"
#include "jeuxfigurine.h"
#include "controlleurjeuxfigurine.h"
#include "wizardpagejeuxfigurine.h"
#include "jeuxfigurine_global.h"

#include <QObject>

class JEUXFIGURINESHARED_EXPORT PluginJeuxFigurine:public QObject, public InterfacePlugin
{
    Q_OBJECT
    Q_INTERFACES(InterfacePlugin)
    Q_PLUGIN_METADATA(IID "plugin_jeux_figurines")

public:
    PluginJeuxFigurine(QObject* parent = nullptr): QObject(parent) {}
    ~PluginJeuxFigurine() {}
    QString getNomAffichage() const;
    QString getNomFichier() const;
    AbstractControlleur* createControlleur(QString);
    QWizardPage* getPage() const;
    AbstractMedia* create() const;
};

#endif // PLUGINJEUXFIGURINE_H
