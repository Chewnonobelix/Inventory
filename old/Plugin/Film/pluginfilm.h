#ifndef PLUGINFILM_H
#define PLUGINFILM_H

#include "film_global.h"
#include "../../Controlleur/InterfacePlugin.h"
#include "controlleurfilm.h"
#include "film.h"
#include "wizardpagefilm.h"

class FILMSHARED_EXPORT PluginFilm: public QObject, public InterfacePlugin
{
    Q_OBJECT
    Q_INTERFACES(InterfacePlugin)
    Q_PLUGIN_METADATA(IID "plugin_film")

public:
    explicit PluginFilm(QObject* = 0);
    ~PluginFilm();

    QString getNomAffichage() const;
    QString getNomFichier() const;
    AbstractControlleur* createControlleur(QString);
    QWizardPage* getPage() const;
    AbstractMedia* create() const;
};

#endif // PLUGINFILM_H
