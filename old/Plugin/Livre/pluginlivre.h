#ifndef PLUGINLIVRE_H
#define PLUGINLIVRE_H

#include "../../Controlleur/InterfacePlugin.h"
#include "livre.h"
//#include "controlleurlivre.h"
#include "wizardpagelivre.h"
#include "livre_global.h"


class LIVRESHARED_EXPORT PluginLivre:public QObject, public InterfacePlugin
{
    Q_OBJECT
    Q_INTERFACES(InterfacePlugin)
    Q_PLUGIN_METADATA(IID "plugin_livre")

public:
    explicit PluginLivre(QObject* = 0);
    ~PluginLivre();

    QString getNomAffichage() const;
    QString getNomFichier() const;
    AbstractControlleur* createControlleur(QString);
    QWizardPage* getPage() const;
    AbstractMedia* create() const;
};

#endif // PLUGINLIVRE_H
