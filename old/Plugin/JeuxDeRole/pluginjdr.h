#ifndef PLUGINJDR_H
#define PLUGINJDR_H

#include "../../Controlleur/InterfacePlugin.h"
#include "jeuxderole_global.h"
#include "jeuxderole.h"
#include "controlleurjdr.h"
#include "wizardpagejdr.h"

class JEUXDEROLESHARED_EXPORT PluginJDR: public QObject,  public InterfacePlugin
{
    Q_OBJECT
    Q_INTERFACES(InterfacePlugin)
    Q_PLUGIN_METADATA(IID "plugin_jdr")

public:
    explicit PluginJDR(QObject* = 0);
    ~PluginJDR();

    QString getNomAffichage () const;
    QString getNomFichier () const;
    AbstractControlleur* createControlleur (QString);
    QWizardPage* getPage() const;
    AbstractMedia* create() const;
};

#endif // PLUGINJDR_H
