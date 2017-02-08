#include "controlleurjeuxfigurine.h"


void ControlleurJeuxFigurine::setVue()
{
    m_vue = new FenetreJeuxFigurine(dynamic_cast<JeuxFigurine*> (courant()));
    connect(dynamic_cast<FenetreJeuxFigurine*>(m_vue), SIGNAL(s_addLivre()), this, SLOT(ajoutLivre()));
    connect(dynamic_cast<FenetreJeuxFigurine*>(m_vue), SIGNAL(s_addFig()), this, SLOT(ajoutFigurine()));
}

QStringList ControlleurJeuxFigurine::getListeSort() const
{
    return getModel(getPlugin()->getNomAffichage()).keys();
}

void ControlleurJeuxFigurine::ajoutLivre()
{
    ControlleurLivre isis;
    connect(&isis, SIGNAL(s_valide(QStringList)), this, SLOT(valideAjoutLivre(QStringList)));
    isis.exec();
}

void ControlleurJeuxFigurine::valideAjoutLivre(QStringList liste)
{
    JeuxFigurine* bastet = dynamic_cast<JeuxFigurine*>(courant());

    try
    {
        bastet->livre(liste[0]);
    }
    catch(QString bastet)
    {
        Livre seth;
        seth.setTitre(liste[0]);
        seth.setSupport(Livre::supportToEnum(liste[2]));
        seth.setLangue(Livre::langueToEnum(liste[1]));
        dynamic_cast<FenetreJeuxFigurine*>(m_vue)->addLivre(seth);
        m_tempLivre<<seth;
    }
}

void ControlleurJeuxFigurine::ajoutFigurine()
{
    ControlleurFigurine uranus(this);
    connect(&uranus, SIGNAL(s_accept(Figurines)), this, SLOT(valideAjoutFigurine(Figurines)));
    uranus.exec();
}

void ControlleurJeuxFigurine::valideAjoutFigurine(Figurines f)
{
    m_tempFig.insert(f.nom(), f);
    dynamic_cast<FenetreJeuxFigurine*>(m_vue)->addFig(f);
}

void ControlleurJeuxFigurine::accept(QSet<QString> livre, QSet<QString> divers, QMultiMap<QString, QStringList> fig)
{
    JeuxFigurine* mars = dynamic_cast<JeuxFigurine*>(courant());

    foreach(const Livre& venus, m_tempLivre)
    {
        mars->addLivres(venus);
    }

    foreach(const Figurines& venus, m_tempFig)
    {
        mars->addFigurines(venus);
    }


    foreach (QString venus, livre)
    {
        mars->removeLivre(venus);
    }
}
