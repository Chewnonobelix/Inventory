#include "controlleurserie.h"

ControlleurSerie::ControlleurSerie(QString nom, InterfacePlugin* plugin, QObject* parent): AbstractControlleurPlugin(nom, plugin, parent)
{
    setVue ();
}

void ControlleurSerie::setVue()
{
    m_vue = new FenetreSerie(dynamic_cast<Serie*>(courant ()));
    dynamic_cast<FenetreSerie*>(getVue ())->setModel ();
}

QStringList ControlleurSerie::getListeSort () const
{
    return getModel ("Série").keys ();
}
