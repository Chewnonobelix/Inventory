#include "controlleurfilm.h"

ControlleurFilm::ControlleurFilm(QString nom, InterfacePlugin* plugin, QObject* parent): AbstractControlleurPlugin(nom, plugin, parent)
{
    setVue ();
}

ControlleurFilm::~ControlleurFilm()
{
}

void ControlleurFilm::setVue()
{
    m_vue = new FenetreFilm(dynamic_cast<Film*>(courant ()));

    dynamic_cast<FenetreFilm*>(getVue ())->setModel ();
}

QStringList ControlleurFilm::getListeSort () const
{
    return getModel ("Film").keys ();
}
