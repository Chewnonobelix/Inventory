#include "livre.h"


Livre::Livre()
{}

Livre::Livre(const Livre& l): m_titre(l.titre()),
    m_langue(l.m_langue), m_support(l.support())
{}

Livre::~Livre()
{}

QString Livre::titre() const
{
	return m_titre;
}

Livre::Langue Livre::langue() const
{
	return m_langue;
}

Livre::Support Livre::support() const
{
	return m_support;
}

void Livre::setTitre(QString t)
{
    m_titre = t;
}

void Livre::setLangue(Langue l)
{
	m_langue = l;
}

void Livre::setSupport(Support s)
{
	m_support = s;
}

Livre& Livre::operator= (const Livre& l)
{
    setTitre(l.titre());
    setSupport(l.support());
    setLangue(l.langue());
	
	return *this;
}

bool operator ==(const Livre& l1, const Livre& l2)
{
    return (l1.titre() == l2.titre()) &&
            (l1.support() == l2.support()) &&
            (l1.langue() == l2.langue());
}	

bool operator <(const Livre& l1, const Livre& l2)
{
    return (l1.titre() < l2.titre());
}

uint qHash(const Livre& l)
{
    return qHash(l.titre());
}

QString Livre::toString() const
{
    QString janus = QObject::tr("Titre: ") + titre() + "\n \n";
    janus += QObject::tr("Support: ") + supportToString(support()) + "\n \n";
    janus += QObject::tr("Langue: ") + langueToString(langue()) + "\n \n";
    return janus;
}

QString Livre::langueToString(Langue l)
{
    switch(l)
    {
    case VO:
        return "VO";
        break;

    case VF:
        return "VF";
        break;

    default:
        throw QString(QObject::tr("Langue non reconnue"));
    }
}

Livre::Langue Livre::langueToEnum(QString l)
{
    if(l == "VO")
    {
        return VO;
    }
    else if(l == "VF")
    {
        return VF;
    }

    throw QString(QObject::tr("Langue non reconnue"));
}

QString Livre::supportToString(Support s)
{
    switch(s)
    {
    case Physique:
        return "Physique";
        break;

    case DownLoad:
        return "DownLoad";
        break;

    default:
        throw QString(QObject::tr("Support inconnu"));
    }
}

Livre::Support Livre::supportToEnum(QString s)
{
    if(s == "Physique")
    {
        return Physique;
    }
    else if(s == "DownLoad")
    {
        return DownLoad;
    }

    throw QString(QObject::tr("Support non reconnue"));
}
