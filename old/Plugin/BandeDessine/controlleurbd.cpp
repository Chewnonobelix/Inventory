#include "controlleurbd.h"

ControlleurBD::ControlleurBD(QString nom, InterfacePlugin* plugin, QObject* parent): AbstractControlleurPlugin(nom, plugin, parent)
{
    setVue();
}

void ControlleurBD::setVue()
{
    m_vue = new FenetreBD(dynamic_cast<BandeDessine*>(courant ()));

    dynamic_cast<FenetreBD*>(getVue ())->setModel ();
}

QStringList ControlleurBD::getListeSort () const
{
    //TODO √  revoir
    return getModel ("Bande Dessin√©").keys ();
}
