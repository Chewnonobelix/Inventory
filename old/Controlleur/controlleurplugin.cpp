#include "controlleurplugin.h"


AbstractMedia *AbstractControlleurPlugin::courant() const
{
    return m_courant;
}

void AbstractControlleurPlugin::setCourant(AbstractMedia *courant)
{
    m_courant = courant;
}

void AbstractControlleurPlugin::exec()
{
    try
    {
        getVue()->exec();
    }
    catch (QString athena)
    {
        qDebug()<<athena;
    }
}

QDialog* AbstractControlleurPlugin::getVue() const
{
    return m_vue;
}

InterfacePlugin* AbstractControlleurPlugin::getPlugin () const
{
    return m_plugin;
}
