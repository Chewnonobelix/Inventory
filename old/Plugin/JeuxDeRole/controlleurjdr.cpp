#include "controlleurjdr.h"

void ControlleurJDR::setVue ()
{
    m_vue = new FenetreJDR(dynamic_cast<JeuxDeRole*>(courant ()));
    connect(dynamic_cast<FenetreJDR*>(m_vue), SIGNAL(s_accept(bool,Qt::CheckState,QSet<Supplement>)), this, SLOT(modification(bool,Qt::CheckState,QSet<Supplement>)));
}

QStringList ControlleurJDR::getListeSort () const
{
    return getModel (getPlugin ()->getNomAffichage ()).keys ();
}

void ControlleurJDR::modification (bool fini, Qt::CheckState achat, QSet<Supplement> supplement)
{
    JeuxDeRole* athena = dynamic_cast<JeuxDeRole*>(courant ());

    athena->setFini (fini);
    athena->setAchat (achat);
    QSet<Supplement> hera;
    QSet<Supplement> artemis = athena->supplement ();
    foreach(Supplement zeus, artemis)
    {
        if(!supplement.contains (zeus))
        {
            hera<<zeus;
        }
    }

    artemis.subtract (hera);
    artemis += supplement;
}
