#include "bandedessine.h"

BandeDessine::BandeDessine()
{
}

BandeDessine::BandeDessine(const BandeDessine& bd): AbstractMedia(bd)
{
    m_tome = bd.getTome();
    m_auteur = bd.getAuteur();
    m_dessinateur = bd.getDessinateur();
    m_enCoursAchat = bd.isEnCoursAchat();
    m_lu = bd.isLu();
}

BandeDessine::~BandeDessine(){}

//Accesseur
bool BandeDessine::isEnCoursAchat() const
{
    return m_enCoursAchat;
}

bool BandeDessine::isLu() const
{
    return m_lu;
}

QMap<int,QString> BandeDessine::getTome() const
{
    return m_tome;
}

QString BandeDessine::getTome(int numero) const
{
    return getTome()[numero];
}

QSet<QString> BandeDessine::getAuteur() const
{
    return m_auteur;
}

QSet<QString> BandeDessine::getDessinateur() const
{
    return m_dessinateur;
}

//Mutateur
void BandeDessine::setEnCoursAchat(bool eca)
{
    m_enCoursAchat = eca;
}

void BandeDessine::setLu(bool lu)
{
    m_lu = lu;
}

void BandeDessine::setTome(QMap<int, QString> t)
{
    m_tome = t;
}

void BandeDessine::addTome(int numero, QString nom)
{
    if(!getTome().contains(numero))
    {
        m_tome[numero] = nom;
    }
}

void BandeDessine::setAuteur(QSet<QString> auteur)
{
    m_auteur = auteur;
}

void BandeDessine::addAuteur(QString auteur)
{
    m_auteur<<auteur;
}

void BandeDessine::setDessinateur(QSet<QString> dessinateur)
{
    m_dessinateur = dessinateur;
}

void BandeDessine::addDessinateur(QString dessinateur)
{
    m_dessinateur<<dessinateur;
}

int BandeDessine::findTome(QString nom) const
{
    return getTome().key(nom, -1);
}

void BandeDessine::chargement(QDomElement & element)
{
    QDomNodeList artemis = element.elementsByTagName("nom");

    if(artemis.size() != 0)
    {
        setNom(artemis.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le nom");
    }

    artemis = element.elementsByTagName("date");

    if(artemis.size() != 0)
    {
        setDate(QDate::fromString(artemis.at(0).toElement().text()));
    }
    else
    {
        throw QString("Il manque la date");
    }
    artemis = element.elementsByTagName("genre");

    if(artemis.size() != 0)
    {
        setGenre(artemis.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le nom");
    }
    artemis = element.elementsByTagName("url");

    if(artemis.size() != 0)
    {
        setUrl(QUrl(artemis.at(0).toElement().text()));
    }
    else
    {
        throw QString("Il manque l'url");
    }

    artemis = element.elementsByTagName("fini");

    if(artemis.size() != 0)
    {
        setFini(artemis.at(0).toElement().text().toInt());
    }
    else
    {
        throw QString("Il manque la balise fini");
    }

    artemis = element.elementsByTagName("lu");

    if(artemis.size() != 0)
    {
        setLu(artemis.at(0).toElement().text().toInt());
    }
    else
    {
        throw QString("Il manque la balise lu");
    }

    artemis = element.elementsByTagName("encoursachat");

    if(artemis.size() != 0)
    {
        setEnCoursAchat(artemis.at(0).toElement().text().toInt());
    }
    else
    {
        throw QString("Il manque la balise encoursachat");
    }

    artemis = element.elementsByTagName("tome");

    for(int zeus = 0; zeus < artemis.size(); zeus ++)
    {
        addTome(artemis.at(zeus).toElement().attribute("numero", "0").toInt(),
                artemis.at(zeus).toElement().text());
    }

    artemis = element.elementsByTagName("auteur");

    for(int zeus = 0; zeus < artemis.size(); zeus ++)
    {
        addAuteur(artemis.at(zeus).toElement().text());
    }

    artemis = element.elementsByTagName("dessinateur");

    for(int zeus = 0; zeus < artemis.size(); zeus ++)
    {
        addDessinateur(artemis.at(zeus).toElement().text());
    }

}

void BandeDessine::sauvegarde(QXmlStreamWriter & stream)
{
    stream.writeStartElement("media");
    stream.writeTextElement("nom", nom());
    stream.writeTextElement("date", date().toString());
    stream.writeTextElement("genre", genre());
    stream.writeTextElement("url", url().toString());
    stream.writeTextElement("fini", QString::number(isFini()));

    stream.writeTextElement("lu", QString::number(isLu()));
    stream.writeTextElement("encoursachat", QString::number(isEnCoursAchat()));

    foreach(QString artemis, getAuteur())
    {
        stream.writeTextElement("auteur", artemis);
    }

    foreach(QString artemis, getDessinateur())
    {
        stream.writeTextElement("dessinateur", artemis);
    }

    for(QMap<int, QString>::iterator artemis = getTome().begin(); artemis != getTome().end(); artemis ++)
    {
        stream.writeStartElement("tome");
        stream.writeAttribute("numero", QString::number(artemis.key()));
        stream.writeCharacters(artemis.value());
        stream.writeEndElement();
    }
    stream.writeEndElement();
}

void BandeDessine::nouveau(QMap<QString, QWizardPage *> pages)
{
    AbstractMedia::nouveau(pages);
}

BandeDessine& BandeDessine::operator = (const BandeDessine& bd)
{
    this->AbstractMedia::operator =(static_cast<const AbstractMedia&>(bd));
    m_auteur = bd.getAuteur();
    m_dessinateur = bd.getDessinateur();
    m_tome = bd.getTome();
    m_enCoursAchat = bd.isEnCoursAchat();
    m_lu = bd.isLu();

    return *this;
}

bool BandeDessine::operator ==(const BandeDessine& bd)
{
    return (this->AbstractMedia::operator ==(static_cast<const AbstractMedia&>(bd)) &&
            (m_tome == bd.getTome()) &&
            (m_auteur == bd.getAuteur()) &&
            (m_dessinateur == bd.getDessinateur())&&
            (m_enCoursAchat == bd.isEnCoursAchat()) &&
            (m_lu == bd.isLu()));
}

bool BandeDessine::operator <(const BandeDessine& bd)
{
    return this->AbstractMedia::operator <(static_cast<const AbstractMedia&>(bd));
}
