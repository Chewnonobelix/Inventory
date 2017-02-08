#ifndef PLUGINJEUXVIDEO_H
#define PLUGINJEUXVIDEO_H

#include "jeuxvideo_global.h"
#include "../../Controlleur/InterfacePlugin.h"
#include "JeuxVideo.h"
#include "wizardpagejv.h"

class JEUXVIDEOSHARED_EXPORT PluginJeuxVideo: public QObject, public InterfacePlugin
{
    Q_OBJECT
    Q_INTERFACES(InterfacePlugin)
    Q_PLUGIN_METADATA(IID "plugin_jv")

public:
    explicit PluginJeuxVideo(QObject* = 0);
    ~PluginJeuxVideo();

    QString getNomAffichage() const;
    QString getNomFichier() const;
    AbstractControlleur* createControlleur(QString);
    QWizardPage* getPage() const;
    AbstractMedia* create() const;

};

#endif // PLUGINJEUXVIDEO_H
