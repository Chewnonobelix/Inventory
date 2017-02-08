#include "abstractcontrolleur.h"

QMap<QString,QMap<QString, AbstractMedia*> > AbstractControlleur::m_model = QMap<QString,QMap<QString, AbstractMedia*> >();
QString AbstractControlleur::m_profil = "n/a";
QMap<QString, InterfacePlugin*> AbstractControlleur::m_plugins = QMap<QString, InterfacePlugin*>();

AbstractControlleur::AbstractControlleur(QObject* parent): QObject(parent)
{
}

QMap<QString, AbstractMedia *> &AbstractControlleur::getModel(QString nom)
{
    return getModel()[nom];
}

QMap<QString, QMap<QString, AbstractMedia *> > &AbstractControlleur::getModel()
{
    return m_model;
}

QString AbstractControlleur::getProfil()
{
    return m_profil;
}

QMap<QString, InterfacePlugin*>& AbstractControlleur::getPlugins()
{
    return m_plugins;
}

void AbstractControlleur::setProfil(QString profil)
{
    m_profil = profil;
}
