#include "film.h"


Film::Film()
{
}

Film::Film(const Film & f):AbstractMedia(f)
{
   m_realisateur = f.getRealisateur();
   m_scenariste = f.getScenariste();
   m_acteurPrincipaux = f.getActeursPrincipaux();
   m_type = f.getType();
   m_duree = f.getDuree();
   m_support = f.getSupport();
}

Film::~Film()
{
}

QString Film::getRealisateur() const
{
    return m_realisateur;
}

QString Film::getScenariste() const
{
    return m_scenariste;
}

QSet<QString> Film::getActeursPrincipaux() const
{
    return m_acteurPrincipaux;
}

QString Film::getType() const
{
    return m_type;
}

QTime Film::getDuree() const
{
    return m_duree;
}

Film::Support Film::getSupport() const
{
    return m_support;
}

void Film::setRealisateur(QString real)
{
    m_realisateur = real;
}

void Film::setScenariste(QString scena)
{
    m_scenariste = scena;
}

void Film::setActeurPrincipaux(QSet<QString> ap)
{
    m_acteurPrincipaux = ap;
}

void Film::addActeur(QString acteur)
{
    m_acteurPrincipaux<<acteur;
}

void Film::setType(QString type)
{
    m_type = type;
}

void Film::setDuree(QTime duree)
{
    m_duree = duree;
}

void Film::setSupport(Support support)
{
    m_support = support;
}

Film& Film::operator = (const Film& f)
{
    this->AbstractMedia::operator =(f);

    m_realisateur = f.getRealisateur();
    m_scenariste = f.getScenariste();
    m_acteurPrincipaux = f.getActeursPrincipaux();
    m_type = f.getType();
    m_duree = f.getDuree();
    m_support = f.getSupport();

    return *this;
}

bool Film::operator == (const Film& f)
{
    return ((this->AbstractMedia::operator ==(f)) &&
            (getRealisateur() == f.getRealisateur()) &&
            (getScenariste() == f.getScenariste()) &&
            (getActeursPrincipaux() == f.getActeursPrincipaux()) &&
            (getType() == f.getType()) &&
            (getDuree() == f.getDuree()) &&
            (getSupport() == f.getSupport()));
}

bool Film::operator < (const Film& f)
{
    return (this->AbstractMedia::operator <(f));
}

void Film::chargement(QDomElement & element)
{
    QDomNodeList pluton = element.elementsByTagName("nom");
    if(pluton.size() > 0)
    {
        setNom(pluton.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le nom");
    }

    pluton = element.elementsByTagName("genre");

    if(pluton.size() > 0)
    {
        setGenre(pluton.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le genre");
    }

    pluton = element.elementsByTagName("date");

    if(pluton.size() > 0)
    {
        setDate(QDate::fromString(pluton.at(0).toElement().text(), "d/M/yyyy"));
    }
    else
    {
        throw QString("Il manque la date");
    }

    pluton = element.elementsByTagName("vue");
    if(pluton.size() > 0)
    {
        setFini(pluton.at(0).toElement().text().toInt());
    }
    else
    {
        throw QString("Il manque fini");
    }

    pluton = element.elementsByTagName("url");
    if(pluton.size() > 0)
    {
        setUrl(QUrl(pluton.at(0).toElement().text()));
    }
    else
    {
        throw QString("Il manque l'url");
    }

    pluton = element.elementsByTagName("realisateur");

    if(pluton.size() > 0)
    {
        setRealisateur(pluton.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le réalisateur");
    }

    pluton = element.elementsByTagName("scenariste");

    if(pluton.size() > 0)
    {
        setScenariste(pluton.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le scenariste");
    }

    pluton = element.elementsByTagName("support");
    if(pluton.size() > 0)
    {
        setSupport((Film::Support)pluton.at(0).toElement().text().toInt());
    }
    else
    {
        throw QString("Il manque le support");
    }

    pluton = element.elementsByTagName("duree");

    if(pluton.size() > 0)
    {
        setDuree(QTime::fromString(pluton.at(0).toElement().text()));
    }
    else
    {
        throw QString("Il manque la durée");
    }

    pluton = element.elementsByTagName("acteur");

    for(int terra = 0; terra < pluton.size(); terra ++)
    {
        addActeur(pluton.at(terra).toElement().text());
    }

    pluton = element.elementsByTagName("type");

    if(pluton.size() > 0)
    {
        setType(pluton.at(0).toElement().text());
    }
    qDebug()<<"Chargement "<<nom()<<"ok";

}

void Film::sauvegarde(QXmlStreamWriter & stream)
{
    qDebug()<<"Sauvegade de "<<nom();
    stream.writeStartElement("media");
    stream.writeTextElement("nom", nom());
    stream.writeTextElement("genre", genre());
    stream.writeTextElement("date", date().toString("d/M/yyyy"));
    stream.writeTextElement("vue", QString::number(isFini()));
    stream.writeTextElement("url", url().toString());
    stream.writeTextElement("type", getType());
    stream.writeTextElement("realisateur", getRealisateur());
    stream.writeTextElement("scenariste", getScenariste());
    stream.writeTextElement("support", QString::number(getSupport()));
    stream.writeTextElement("duree", getDuree().toString());

    foreach(QString jupiter, getActeursPrincipaux())
    {
        stream.writeTextElement("acteur", jupiter);
    }

    stream.writeEndElement();
}

void Film::nouveau(QMap<QString, QWizardPage *> map)
{
    AbstractMedia::nouveau(map);

    QGridLayout* luna = dynamic_cast<QGridLayout*>(map["Page 2"]->layout());
    qDebug()<<luna<<map["Page 2"];
    if(luna)
    {
        setRealisateur(dynamic_cast<QLineEdit*>(luna->itemAtPosition(0,1)->widget())->text());
        setScenariste(dynamic_cast<QLineEdit*>(luna->itemAtPosition(1,1)->widget())->text());
        setDuree(dynamic_cast<QTimeEdit*>(luna->itemAtPosition(2,1)->widget())->time());
        setType(dynamic_cast<QLineEdit*>(luna->itemAtPosition(3,1)->widget())->text());
        QListWidget* terra = dynamic_cast<QListWidget*>(luna->itemAtPosition(4,1)->widget());

        for(int jupiter = 0; jupiter < terra->count(); jupiter ++)
        {
            addActeur(terra->item(jupiter)->text());
        }
    }
}
