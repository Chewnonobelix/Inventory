#include "jeuxderole.h"

JeuxDeRole::JeuxDeRole()
{
    m_achat = Qt::Unchecked;
    m_supplement.clear ();
    m_langueBase = Supplement::VF;
}

JeuxDeRole::JeuxDeRole(const JeuxDeRole& jdr): AbstractMedia(jdr)
{
    m_achat = jdr.achat();
    m_supplement = jdr.supplement();
    m_langueBase = jdr.langue();
}

JeuxDeRole::~JeuxDeRole()
{
}

void JeuxDeRole::chargement (QDomElement & element)
{
    if(element.tagName () != "jdr")
    {
        throw QString("Balise incompatible");
    }

    QDomNodeList zeus = element.elementsByTagName ("nom");

    if(zeus.size () == 0)
    {
        throw QString("Il manque le nom");
    }
    else
    {
        setNom(zeus.at (0).toElement ().text ());
    }

    zeus = element.elementsByTagName ("genre");

    if(zeus.size () == 0)
    {
        throw QString("Il manque le genre");
    }
    else
    {
        setGenre(zeus.at (0).toElement ().text ());
    }
    zeus = element.elementsByTagName ("sortie");

    if(zeus.size () == 0)
    {
        throw QString("Il manque la date de sortie");
    }
    else
    {
        setDate(QDate::fromString (zeus.at (0).toElement ().text ()));
    }

    //url
    zeus = element.elementsByTagName ("url");

    if(zeus.size () == 0)
    {
        throw QString("Il manque l'url");
    }
    else
    {
        setUrl (QUrl(zeus.at (0).toElement ().text ()));
    }
    //fini
    zeus = element.elementsByTagName ("nom");

    if(zeus.size () == 0)
    {
        throw QString("Il manque la balise fini");
    }
    else
    {
        setFini(zeus.at (0).toElement ().text ().toInt ());
    }
    //achat
    zeus = element.elementsByTagName ("achat");

    if(zeus.size () == 0)
    {
        throw QString("Il manque la balise achat");
    }
    else
    {
        setAchat((Qt::CheckState)(zeus.at (0).toElement ().text ().toInt ()));
    }
    //langue
    zeus = element.elementsByTagName ("langueBase");

    if(zeus.size () == 0)
    {
        throw QString("Il manque la langue");
    }
    else
    {
        setLangue (Supplement::langueFromString (zeus.at (0).toElement ().text ()));
    }

    //supplement

    zeus = element.elementsByTagName ("supplement");

    for(int athena = 0; athena < zeus.size (); athena ++)
    {
        Supplement artemis;
        QDomElement hera = zeus.at (athena).toElement ();
        artemis.chargement (hera);
        addSupplement (artemis);
    }
}

void JeuxDeRole::sauvegarde (QXmlStreamWriter & stream)
{
    stream.writeStartElement ("jdr");
    stream.writeTextElement ("nom", nom ());
    stream.writeTextElement ("genre", genre());
    stream.writeTextElement ("sortie", date ().toString ());
    stream.writeTextElement ("url", url ().toString ());
    stream.writeTextElement ("fini", QString::number (isFini ()));

    stream.writeTextElement ("achat", QString::number (achat ()));
    stream.writeTextElement ("langueBase", Supplement::langueToString (langue ()));

    for(QSet<Supplement>::iterator athena = supplement ().begin (); athena != supplement ().end (); athena ++)
    {
        ((Supplement&)(*athena)).sauvegarde (stream);
    }

    stream.writeEndElement ();
}

void JeuxDeRole::nouveau (QMap<QString, QWizardPage *> nouveau)
{
    AbstractMedia::nouveau (nouveau);

    WizardPageJDR* athena = dynamic_cast<WizardPageJDR*>(nouveau["Page 2"]);

    setLangue (Supplement::langueFromString (athena->getLangue ()));
    setAchat (athena->getAchat ());
}


Qt::CheckState JeuxDeRole::achat() const
{
    return m_achat;
}

void JeuxDeRole::setAchat(Qt::CheckState achat)
{
    m_achat = achat;
}

JeuxDeRole& JeuxDeRole::operator = (const JeuxDeRole& jdr)
{
    this->AbstractMedia::operator =(static_cast<const AbstractMedia&>(jdr));

    m_supplement.clear ();
    m_supplement = jdr.supplement();
    m_achat = jdr.achat();
    m_langueBase = jdr.langue();

    return *this;
}

bool JeuxDeRole::operator == (const JeuxDeRole& jdr)
{
    return (this->AbstractMedia::operator ==(static_cast<const AbstractMedia&>(jdr)) &&
            (supplement() == jdr.supplement()) &&
            (achat() == jdr.achat()) &&
            (langue() == jdr.langue()));
}

bool JeuxDeRole::operator < (const JeuxDeRole& jdr)
{
    return ((this->AbstractMedia::operator <(static_cast<const AbstractMedia&>(jdr))) &&
            (nbSupplement() < jdr.nbSupplement()) &&
            (langue() < jdr.langue()));
}

Supplement::Langue JeuxDeRole::langue() const
{
    return m_langueBase;
}

void JeuxDeRole::setLangue(Supplement::Langue langue)
{
    m_langueBase = langue;
}

int JeuxDeRole::nbSupplement () const
{
    return supplement ().size ();
}

QSet<Supplement> JeuxDeRole::supplement () const
{
    return m_supplement;
}

void JeuxDeRole::setSupplement (QSet<Supplement> sup)
{
    m_supplement = sup;
}

void JeuxDeRole::addSupplement (Supplement sup)
{
    m_supplement<<sup;
}
