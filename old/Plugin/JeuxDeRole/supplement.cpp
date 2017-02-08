#include "supplement.h"
#include <QDebug>

Supplement::Supplement()
{}

Supplement::Supplement(const Supplement& s):m_type(s.type()),
    m_nom(s.nom()), m_support(s.support()), m_langue(s.langue())
{}

Supplement::Type Supplement::type() const
{
    return m_type;
}

void Supplement::setType(Type type)
{
    m_type = type;
}

QString Supplement::nom() const
{
    return m_nom;
}

void Supplement::setNom(QString nom)
{
    m_nom = nom;
}

Supplement::Support Supplement::support() const
{
    return m_support;
}

void Supplement::setSupport(Support support)
{
    m_support = support;
}

Supplement::Langue Supplement::langue() const
{
    return m_langue;
}

void Supplement::setLangue(Langue langue)
{
    m_langue = langue;
}

Supplement& Supplement::operator = (const Supplement& s)
{
    m_type = s.type();
    m_nom = s.nom();
    m_langue = s.langue();
    m_support = s.support();

    return *this;
}

bool Supplement::operator == (const Supplement& s) const
{
    return ((nom() == s.nom()) &&
            (type() == s.type()) &&
            (support() == s.support()) &&
            (langue() == s.langue()));
}

bool Supplement::operator < (const Supplement& s) const
{
    return ((nom() < s.nom()) &&
            (langue() < s.langue()) &&
            (support() < s.support()));
}

uint qHash (const Supplement& s)
{
    return qHash(s.nom()) + qHash(s.langue());
}

bool operator == (const Supplement& s1, const Supplement& s2)
{
    return ((s1.nom() == s2.nom()) &&
            (s1.type() == s2.type()) &&
            (s1.support() == s2.support()) &&
            (s1.langue() == s2.langue()));
}

Supplement::Langue Supplement::langueFromString (QString string)
{
    if(string == "VO")
    {
        return VO;
    }
    else if(string == "VF" )
    {
        return VF;
    }
    else
    {
        throw "Unknown language " + string;
    }
}

QString Supplement::langueToString (Langue l)
{
    switch (l)
    {
    case VO:
        return "VO";
        break;

    default:
        return "VF";
        break;
    }
}

Supplement::Type Supplement::typeFromString (QString string)
{
    if(string == "Scénario")
    {
        return Scenario;
    }
    else if(string == "Extension")
    {
        return Extension;
    }
    else if(string == "Background")
    {
        return Background;
    }
    else if(string == "Bestiaire")
    {
        return Bestiaire;
    }
    else
    {
        throw "Unknown type " + string;
    }
}

QString Supplement::typeToString (Type t)
{
    switch (t)
    {
    case Scenario:
        return "Sc�nario";
        break;

    case Bestiaire:
        return "Bestiaire";
        break;

    case Background:
        return "Background";
        break;

    default:
        return "Extension";
        break;
    }
}

Supplement::Support Supplement::supportFromString (QString string)
{
    if(string == "Livre")
    {
        return Livre;
    }
    else if(string == "DownLoad" )
    {
        return DownLoad;
    }
    else
    {
        throw "Unknown support " + string;
    }
}

QString Supplement::supportToString (Support s)
{
    if(s == Livre)
    {
        return "Livre";
    }
    else
    {
        return "DownLoad";
    }
}

void Supplement::chargement (QDomElement & element)
{
    QDomNodeList athena = element.elementsByTagName ("nomSupplement");

    if(athena.size () == 0)
    {
        throw QString("Il manque le nom du supplément");
    }
    else
    {
        setNom (athena.at (0).toElement ().text ());
    }

    athena = element.elementsByTagName ("langueSupplement");

    if(athena.size () == 0)
    {
        throw QString("Il manque la langue du supplément");
    }
    else
    {
        setLangue (langueFromString (athena.at (0).toElement ().text ()));
    }

    athena = element.elementsByTagName ("typeSupplement");

    if(athena.size () == 0)
    {
        throw QString("Il manque le type du supplément");
    }
    else
    {
        setType (typeFromString (athena.at (0).toElement ().text ()));
    }

    athena = element.elementsByTagName ("supportSupplement");

    if(athena.size () == 0)
    {
        throw QString("Il manque le support du supplément");
    }
    else
    {
        setSupport (supportFromString (athena.at (0).toElement ().text ()));
    }
}

void Supplement::sauvegarde (QXmlStreamWriter & stream)
{
    stream.writeStartElement ("supplement");
    stream.writeTextElement ("nomSupplement", nom ());
    stream.writeTextElement ("langueSupplement", langueToString (langue()));
    stream.writeTextElement ("typeSupplement", typeToString (type()));
    stream.writeTextElement ("supportSupplement", supportToString (support ()));
    stream.writeEndElement ();
}
