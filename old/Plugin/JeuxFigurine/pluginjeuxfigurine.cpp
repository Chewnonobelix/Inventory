#include "pluginjeuxfigurine.h"

QString PluginJeuxFigurine::getNomAffichage() const
{
    return tr("Jeux de figurines");
}
QString PluginJeuxFigurine::getNomFichier() const
{
    return tr("jeux_de_figurines");
}
AbstractControlleur* PluginJeuxFigurine::createControlleur(QString nom)
{
    return new ControlleurJeuxFigurine(nom, this);
}

QWizardPage* PluginJeuxFigurine::getPage() const
{
    return new WizardPageJeuxFigurine;
}

AbstractMedia* PluginJeuxFigurine::create() const
{
    return new JeuxFigurine;
}
