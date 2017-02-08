#include "pluginserie.h"

QString PluginSerie::getNomAffichage() const
{
    return "Série";
}

QString PluginSerie::getNomFichier() const
{
    return "serie";
}

AbstractControlleur* PluginSerie::createControlleur(QString nom)
{
    try
    {
        return new ControlleurSerie(nom, this);
    }
    catch(QString apollon)
    {
        throw apollon;
    }
}

QWizardPage* PluginSerie::getPage() const
{
    return new WizardPageSerie;
}

AbstractMedia* PluginSerie::create() const
{
    return new Serie;
}
