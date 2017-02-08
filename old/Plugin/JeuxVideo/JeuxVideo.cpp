#include <exception>
using namespace std;

#include "JeuxVideo.h"

JeuxVideo::JeuxVideo(): AbstractMedia(),
    m_supportPhysique(non), m_extension(Qt::Unchecked)
{}

JeuxVideo::JeuxVideo(const JeuxVideo& j): AbstractMedia(j),
    m_type(j.getType()), m_support(j.getSupport()),
    m_supportPhysique(j.hasSupportPhysique()), m_studio(j.getStudio()),
    m_editeur(j.getEditeur()), m_extension(j.isExtension())
{}

JeuxVideo::~JeuxVideo()
{}

QString JeuxVideo::getType() const
{
    return m_type;
}

void JeuxVideo::setType(QString t)
{
    m_type = t;
}

QString JeuxVideo::getSupport() const
{
    return m_support;
}

void JeuxVideo::setSupport(QString s)
{
    m_support = s;
}

JeuxVideo::support JeuxVideo::hasSupportPhysique() const
{
    return m_supportPhysique;
}

void JeuxVideo::setSupportPhysique(support s)
{
    m_supportPhysique = s;
}

QString JeuxVideo::getStudio() const
{
    return m_studio;
}

void JeuxVideo::setStudio(QString s)
{
    m_studio = s;
}

QString JeuxVideo::getEditeur() const
{
    return m_editeur;
}

void JeuxVideo::setEditeur(QString e)
{
    m_editeur = e;
}

Qt::CheckState JeuxVideo::isExtension() const
{
    return m_extension;
}

void JeuxVideo::setExtension(Qt::CheckState e)
{
    m_extension = e;
}

bool JeuxVideo::operator==(const JeuxVideo& j)
{
    return (this->AbstractMedia::operator ==(static_cast<const AbstractMedia&>(j)) &&
            (m_type == j.getType()) &&
            (m_support == j.getSupport()) &&
            (m_supportPhysique == j.hasSupportPhysique()) &&
            (m_studio == j.getStudio()) &&
            (m_editeur == j.getEditeur()) &&
            (m_extension == j.isExtension()));
}

bool JeuxVideo::operator<(const JeuxVideo& j)
{
    return (this->AbstractMedia::operator <(static_cast<const AbstractMedia&>(j)) &&
            getStudio() < j.getStudio());
}

JeuxVideo& JeuxVideo::operator=(const JeuxVideo& j)
{

    this->AbstractMedia::operator =(static_cast<const AbstractMedia&>(j));

    m_type = j.getType();
    m_support = j.getSupport();
    m_supportPhysique = j.hasSupportPhysique();
    m_studio = j.getStudio();
    m_editeur = j.getEditeur();
    m_extension = j.isExtension();

    return *this;
}

void JeuxVideo::chargement(QDomElement& e)
{
    QDomNodeList l;

    l = e.elementsByTagName("nom");
    if(l.size() > 0)
    {
        setNom(l.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le nom");
    }
    l = e.elementsByTagName("genre");

    if(l.size() > 0)
    {
        setGenre(l.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le genre");
    }

    l = e.elementsByTagName("date");

    if(l.size() > 0)
    {
        setDate(QDate::fromString(l.at(0).toElement().text(), "d/M/yyyy"));
    }
    else
    {
        throw QString("Il manque la date");
    }

    l = e.elementsByTagName("fini");
    if(l.size() > 0)
    {
        setFini(l.at(0).toElement().text().toInt());
    }
    else
    {
        throw QString("Il manque fini");
    }

    l = e.elementsByTagName("url");
    if(l.size() > 0)
    {
        setUrl(QUrl(l.at(0).toElement().text()));
    }
    else
    {
        throw QString("Il manque l'url");
    }

    l = e.elementsByTagName("type");
    if(l.size() > 0)
    {
        setType(l.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le type");
    }

    l = e.elementsByTagName("support");
    if(l.size() > 0)
    {
        setSupport(l.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le support");
    }

    l = e.elementsByTagName("supportPhysique");
    if(l.size() > 0)
    {
        switch(l.at(0).toElement().text().toInt())
        {
        case 0:
            setSupportPhysique(non);
            break;

        case 1:
            setSupportPhysique(cd);
            break;

        case 2:
            setSupportPhysique(steam);
            break;

        case 3:
            setSupportPhysique(steamcd);
            break;

        default:
            setSupportPhysique(non);
            break;
        }
    }
    else
    {
        throw QString("Il manque le support physique");
    }

    l = e.elementsByTagName("studio");
    if(l.size() > 0)
    {
        setStudio(l.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque le studio");
    }
    l = e.elementsByTagName("editeur");
    if(l.size() > 0)
    {
        setEditeur(l.at(0).toElement().text());
    }
    else
    {
        throw QString("Il manque l'éditeur");
    }
    l = e.elementsByTagName("extension");
    if(l.size() > 0)
    {
        switch(l.at(0).toElement().text().toInt())
        {
        case 0:
            setExtension(Qt::Unchecked);
            break;

        case 1:
            setExtension(Qt::PartiallyChecked);
            break;

        case 2:
            setExtension(Qt::Checked);
            break;

        default:
            break;
        }
    }
    else
    {
        throw QString("Il manque l'extension");
    }

    qDebug()<<"Chargement "<<nom()<<"ok";
}

void JeuxVideo::sauvegarde(QXmlStreamWriter& s)
{
    qDebug()<<"Sauvegade de "<<nom();
    s.writeStartElement("media");
    s.writeTextElement("nom", nom());
    s.writeTextElement("genre", genre());
    s.writeTextElement("date",date().toString("d/M/yyyy"));
    s.writeTextElement("fini", QString::number(isFini()));
    s.writeTextElement("url", url().toString());
    s.writeTextElement("type", getType());
    s.writeTextElement("support", getSupport());
    s.writeTextElement("supportPhysique", QString::number(hasSupportPhysique()));
    s.writeTextElement("studio", getStudio());
    s.writeTextElement("editeur", getEditeur());
    s.writeTextElement("extension", QString::number(isExtension()));
    s.writeEndElement();
}

void JeuxVideo::nouveau(QMap<QString, QWizardPage *> pages)
{
    AbstractMedia::nouveau(pages);
    QGridLayout* luna = dynamic_cast<QGridLayout*>(pages["Page 2"]->layout());


    if(luna)
    {
        setType(dynamic_cast<QLineEdit*>(luna->itemAtPosition(0,1)->widget())->text());
        setSupport(dynamic_cast<QComboBox*>(luna->itemAtPosition(1,1)->widget())->currentText());
        setExtension(dynamic_cast<QCheckBox*>(luna->itemAtPosition(2,0)->widget())->checkState());
        QGroupBox* salus = dynamic_cast<QGroupBox*>(luna->itemAtPosition(2,1)->widget());
        QGridLayout* jupiter = dynamic_cast<QGridLayout*>(salus->layout());

        if(dynamic_cast<QRadioButton*>(jupiter->itemAtPosition(0,0)->widget())->isChecked())
        {
            setSupportPhysique(cd);
        }
        else if(getSupport() == "PC" && dynamic_cast<QRadioButton*>(jupiter->itemAtPosition(0,1)->widget())->isChecked())
        {
            setSupportPhysique(steam);
        }
        else if(getSupport() == "PC" && dynamic_cast<QRadioButton*>(jupiter->itemAtPosition(3,1)->widget())->isChecked())
        {
            setSupportPhysique(steamcd);
        }
        else
        {
            setSupportPhysique(non);
        }
        setStudio(dynamic_cast<QLineEdit*>(luna->itemAtPosition(3,1)->widget())->text());
        setEditeur(dynamic_cast<QLineEdit*>(luna->itemAtPosition(4,1)->widget())->text());
    }
}
