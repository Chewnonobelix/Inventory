#include "pluginfilm.h"

PluginFilm::PluginFilm(QObject* parent): QObject(parent)
{
}


PluginFilm::~PluginFilm()
{
}

QString PluginFilm::getNomAffichage() const
{
    return "Film";
}

QString PluginFilm::getNomFichier() const
{
    return "film";
}

AbstractControlleur* PluginFilm::createControlleur(QString nom)
{
    try
    {
        return new ControlleurFilm(nom, this);
    }
    catch(QString apollon)
    {
        throw apollon;
    }
}

QWizardPage* PluginFilm::getPage() const
{
    return new WizardPageFilm;
}

AbstractMedia* PluginFilm::create() const
{
    return new Film;
}
