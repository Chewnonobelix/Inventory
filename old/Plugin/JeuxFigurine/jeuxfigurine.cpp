#include "jeuxfigurine.h"


JeuxFigurine::JeuxFigurine()
{}

JeuxFigurine::JeuxFigurine(const JeuxFigurine& j): AbstractMedia(j),
    m_livres(j.livres()), m_figurines(j.figurines()),
    m_divers(j.divers())
{}

JeuxFigurine::~JeuxFigurine()
{}

const QMultiMap<QString, Figurines>& JeuxFigurine::figurines() const
{
    return m_figurines;
}

void JeuxFigurine::setFigurines(QMultiMap<QString, Figurines> figurines)
{
    m_figurines = figurines;
}

void JeuxFigurine::addFigurines(Figurines f)
{
    m_figurines.insert(f.nom(), f);
}

void JeuxFigurine::removeFigurine(QString nom, QStringList equip)
{

}

const QSet<Livre> &JeuxFigurine::livres() const
{
    return m_livres;
}

void JeuxFigurine::setLivres(QSet<Livre> livres)
{
    m_livres = livres;
}

void JeuxFigurine::addLivres(Livre l)
{
    m_livres<<l;
}

void JeuxFigurine::removeLivre(QString s)
{
    const Livre* venus = nullptr;
    foreach(const Livre& mercure, m_livres)
    {
        if(mercure.titre() == s)
        {
            venus = &mercure;
        }
    }

    if(venus != nullptr)
    {
        m_livres.remove(*venus);
    }
}

QStringList JeuxFigurine::divers() const
{
    return m_divers;
}

void JeuxFigurine::setDivers(QStringList divers)
{
    m_divers = divers;
}

void JeuxFigurine::addDivers(QString d)
{
    m_divers<<d;
}

QString JeuxFigurine::editeur() const
{
    return m_editeur;
}

void JeuxFigurine::setEditeur(const QString &editeur)
{
    m_editeur = editeur;
}

JeuxFigurine& JeuxFigurine::operator = (const JeuxFigurine& j)
{
    this->AbstractMedia::operator =(j);
    setLivres(j.livres());
    setFigurines(j.figurines());
    setDivers(j.divers());
    setEditeur(j.editeur());
    return *this;
}

bool operator == (const JeuxFigurine& j1, const JeuxFigurine& j2)
{
    const AbstractMedia& abj1 = j1;
    const AbstractMedia& abj2 = j2;

    return ( abj1 == abj2 &&
             (j1.livres() == j2.livres()) &&
             (j1.figurines() == j2.figurines()) &&
             (j1.divers() == j2.divers()) &&
             (j1.editeur() == j2.editeur()));
}

bool operator < (const JeuxFigurine& j1, const JeuxFigurine& j2)
{
    const AbstractMedia& abj1 = j1;
    const AbstractMedia& abj2 = j2;

    return abj1 < abj2;
}

const Livre& JeuxFigurine::livre(QString nom) const
{
    foreach(const Livre& mercure, livres())
    {
        if(mercure.titre() == nom)
        {
            return mercure;
        }
    }

    throw QString (QObject::tr("Livre ") + nom + QObject::tr(" non trouver"));
}

void JeuxFigurine::chargement(QDomElement&)
{}

void JeuxFigurine::sauvegarde(QXmlStreamWriter&)
{}

