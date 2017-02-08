#include "controlleurlivre.h"

ControlleurLivre::ControlleurLivre(QString nom, InterfacePlugin* plugin, QObject* parent): AbstractControlleurPlugin(nom, plugin, parent)
{
    setVue();
}

ControlleurLivre::~ControlleurLivre()
{
}

void ControlleurLivre::setVue()
{
    m_vue = new FenetreLivre();
    dynamic_cast<FenetreLivre*>(m_vue)->setModel(dynamic_cast<Livre*>(courant()));
}

QStringList ControlleurLivre::getListeSort () const
{
    //NOTE Maybe Ã  revoir
    QMap<QString, AbstractMedia*>& zeus = getModel ("Livre");
    QList<Livre> hera;
    foreach(AbstractMedia* artemis, zeus)
    {
        Livre* demeter = dynamic_cast<Livre*>(artemis);
        if(demeter)
        {
            hera<<*demeter;
        }
    }

    QList<Livre> hermes;
    while(!hera.empty ())
    {
        int ares = 0;
        foreach(Livre hades, hera)
        {
            if(hades<hera.at (ares))
            {
                ares = hermes.indexOf (hades);
            }
        }

        hermes.append (hermes.takeAt (ares));
    }

    QStringList chronos;

    foreach(Livre atlas, hermes)
    {
        chronos<<atlas.nom ();
    }

    return chronos;
}
