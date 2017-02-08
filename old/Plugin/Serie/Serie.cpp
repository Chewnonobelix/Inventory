#include <exception>
using namespace std;

#include "Serie.h"

Serie::Serie()
{
}

Serie::Serie(const Serie& s): AbstractMedia(s)
{
    m_nbEpisode = s.getNbEpisode();
    m_visionnage = s.getVisionnage();
}

Serie::~Serie()
{
}

QMap<int, int> Serie::getNbEpisode() const
{
    return m_nbEpisode;
}

int Serie::getNbEpisode(int saison) const
{
    return getNbEpisode()[saison];
}

Serie::Visionnage Serie::getVisionnage() const
{
    return m_visionnage;
}

void Serie::setNbEpisode(int saison, int episode)
{
    getNbEpisode()[saison] = episode;
}

void Serie::setNbEpisode(QMap<int, int> e)
{
    m_nbEpisode = e;
}

void Serie::setVisionnage(Visionnage v)
{
    m_visionnage = v;
}

Serie& Serie::operator=(const Serie& s)
{
    this->AbstractMedia::operator =(static_cast<const AbstractMedia&>(s));
    m_nbEpisode = s.getNbEpisode();
    m_visionnage = s.getVisionnage();

    return *this;
}

bool Serie::operator==(const Serie& s)
{
    return ((this->AbstractMedia::operator ==(static_cast<const AbstractMedia&>(s))) &&
            (m_visionnage == s.m_visionnage) &&
            (getNbEpisode() == s.getNbEpisode()));
}


bool Serie::operator<(const Serie& s)
{
    return this->AbstractMedia::operator <(static_cast<const AbstractMedia&>(s));
}

void Serie::chargement(QDomElement& luna)
{
    QDomNodeList terra;

    terra = luna.elementsByTagName("nom");
    if(terra.size() > 0)
    {
        setNom(terra.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le nom");
    }

    terra = luna.elementsByTagName("genre");

    if(terra.size() > 0)
    {
        setGenre(terra.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le genre");
    }

    terra = luna.elementsByTagName("date");

    if(terra.size() > 0)
    {
        setDate(QDate::fromString(terra.at(0).toElement().text(), "d/M/yyyy"));
    }
    else
    {
        throw QString("Il manque la date");
    }

    terra = luna.elementsByTagName("fini");
    if(terra.size() > 0)
    {
        setFini(terra.at(0).toElement().text().toInt());
    }
    else
    {
        throw QString("Il manque fini");
    }

    terra = luna.elementsByTagName("url");
    if(terra.size() > 0)
    {
        setUrl(QUrl(terra.at(0).toElement().text()));
    }
    else
    {
        throw QString("Il manque l'url");
    }

    terra = luna.elementsByTagName("vision");

    if(terra.size() > 0)
    {
        if(terra.at(0).toElement().text() == "vue")
        {
            setVisionnage(vue);
        }
        else if(terra.at(0).toElement().text() == "encours")
        {
            setVisionnage(encours);
        }
        else
        {
            setVisionnage(non);
        }
    }

    terra = luna.elementsByTagName("saison");

    for(int jupiter = 0; jupiter < terra.size(); jupiter ++)
    {
        QDomElement venus = terra.at(jupiter).toElement();
        getNbEpisode()[venus.attribute("numero").toInt()] = venus.text().toInt();
    }

    qDebug()<<"Chargement de"<<nom()<<"ok";
}

void Serie::sauvegarde(QXmlStreamWriter& terra)
{
    qDebug()<<"Sauvegade de "<<nom();
    terra.writeStartElement("media");
    terra.writeTextElement("nom", nom());
    terra.writeTextElement("genre", genre());
    terra.writeTextElement("date", date().toString("d/M/yyyy"));
    terra.writeTextElement("fini", QString::number(isFini()));
    terra.writeTextElement("url", url().toString());
    QMap<int, int> luna = getNbEpisode();

    for(QMap<int,int>::iterator jupiter = luna.begin(); jupiter != luna.end(); jupiter ++)
    {
        terra.writeStartElement("saison");
        terra.writeAttribute("numero", QString::number(jupiter.key()));
        terra.writeCharacters(QString::number(jupiter.value()));
        terra.writeEndElement();
    }

    switch(getVisionnage())
    {
    case vue:
        terra.writeTextElement("vision", "vue");
        break;
    case encours:
        terra.writeTextElement("vision", "encours");
        break;
    case non:
        terra.writeTextElement("vision", "non");
        break;
    }
    terra.writeEndElement();
}

QWizardPage* Serie::getPage()
{
    return new WizardPageSerie;
}

void Serie::nouveau(QMap<QString, QWizardPage *> salus)
{
    AbstractMedia::nouveau(salus);

    WizardPageSerie* trivia = dynamic_cast<WizardPageSerie*>(salus["Page 2"]);

    for(int pluton = 1; pluton <= trivia->getNbSaison(); pluton ++)
    {
        getNbEpisode()[pluton] = 1;
    }
}
