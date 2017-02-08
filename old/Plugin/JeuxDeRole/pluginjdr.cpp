#include "pluginjdr.h"

PluginJDR::PluginJDR(QObject* parent): QObject(parent)
{
}

PluginJDR::~PluginJDR()
{
}

QString PluginJDR::getNomAffichage () const
{
    return "Jeux de Role";
}

QString PluginJDR::getNomFichier () const
{
    return "jeux_de_role";
}

AbstractControlleur* PluginJDR::createControlleur (QString nom)
{
    return new ControlleurJDR(nom, this);
}

QWizardPage* PluginJDR::getPage() const
{
    return new WizardPageJDR;
}

AbstractMedia* PluginJDR::create() const
{
    return new JeuxDeRole;
}
