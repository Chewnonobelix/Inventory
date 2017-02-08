#include "pluginjeuxvideo.h"
#include "controlleurjeuxvideo.h"

PluginJeuxVideo::PluginJeuxVideo(QObject* parent): QObject(parent)
{
}

PluginJeuxVideo::~PluginJeuxVideo()
{
}

QString PluginJeuxVideo::getNomAffichage() const
{
    return "Jeux Vidéo";
}

QString PluginJeuxVideo::getNomFichier() const
{
    return "jeuxvideo";
}

AbstractControlleur* PluginJeuxVideo::createControlleur(QString nom)
{
    try
    {
        return new ControlleurJeuxVideo(nom, this);
    }
    catch(QString apollon)
    {
        throw apollon;
    }
}

QWizardPage* PluginJeuxVideo::getPage() const
{
    return new WizardPageJV;
}

AbstractMedia* PluginJeuxVideo::create() const
{
    return new JeuxVideo;
}
