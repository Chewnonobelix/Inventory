#include "pluginbandedessine.h"

QString PluginBandeDessine::getNomAffichage() const
{
    return "Bande Dessiné";
}

QString PluginBandeDessine::getNomFichier() const
{
    return "bandedessine";
}

AbstractControlleur* PluginBandeDessine::createControlleur(QString nom)
{
    try
    {
        return new ControlleurBD(nom, this);
    }
    catch(QString zeus)
    {
        throw zeus;
    }
}

QWizardPage* PluginBandeDessine::getPage() const
{
    return new WizardPageBD;
}

AbstractMedia* PluginBandeDessine::create() const
{
    return new BandeDessine;
}
