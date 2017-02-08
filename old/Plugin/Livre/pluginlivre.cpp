#include "pluginlivre.h"

#include "controlleurlivre.h"
PluginLivre::PluginLivre(QObject* parent): QObject(parent)
{
}

PluginLivre::~PluginLivre()
{}

QString PluginLivre::getNomAffichage() const
{
    return "Livre";
}

QString PluginLivre::getNomFichier() const
{
    return "livre";
}

AbstractControlleur* PluginLivre::createControlleur(QString nom)
{
    return new ControlleurLivre(nom, this);
}

AbstractMedia* PluginLivre::create() const
{
    return new Livre;
}

QWizardPage* PluginLivre::getPage() const
{
    return new WizardPageLivre;
}
