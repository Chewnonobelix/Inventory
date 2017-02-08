#include "livre.h"


Livre::Livre()
{
    m_numeroTome = 1;
}

Livre::Livre(const Livre & l):AbstractMedia(l)
{
    m_auteur = l.auteur();
    m_editeur = l.editeur();
    m_cycle = l.cycle();
    m_numeroTome = l.numeroTome();
}

Livre::~Livre ()
{
}

void Livre::chargement(QDomElement & e)
{
    QDomNodeList zeus = e.elementsByTagName ("nom");
    if(zeus.size () != 1)
    {
        throw QString("Il y a un souci sur la balise nom");
    }

    setNom(zeus.at (0).toElement ().text ());

    zeus = e.elementsByTagName ("url");
    if(zeus.size () == 1)
    {
        setUrl (zeus.at (0).toElement ().text ());
    }

    zeus = e.elementsByTagName ("genre");
    if(zeus.size () != 1)
    {
        throw QString("Il y a un souci sur la balise genre");
    }
    setGenre (zeus.at (0).toElement ().text ());

    zeus = e.elementsByTagName ("editeur");
    if(zeus.size () != 1)
    {
        throw QString("Il y a un souci sur la balise editeur");
    }
    setEditeur (zeus.at (0).toElement ().text ());

    zeus = e.elementsByTagName ("cycle");
    if(zeus.size () == 1)
    {
        QDomElement chronos = zeus.at (0).toElement ();
        setCycle(chronos.text ());
        setNumeroTome (chronos.attribute ("tome").toInt ());
    }

    zeus = e.elementsByTagName ("sortie");
    if(zeus.size () != 1)
    {
        throw QString("Il y a un souci sur la balise sortie");
    }

    setDate(QDate::fromString (zeus.at (0).toElement ().text ()));

    zeus = e.elementsByTagName ("auteur");
    if(zeus.size () == 0)
    {
        throw QString("Il manque au moins un auteur");
    }

    for(int venus = 0; venus < zeus.size (); venus ++)
    {
        addAuteur (zeus.at (venus).toElement ().text ());
    }

    zeus = e.elementsByTagName ("lu");

    if(zeus.size () != 1)
    {
        throw QString("Il y a un probleme avec la balise lu");
    }

    setFini (zeus.at (0).toElement ().text ().toInt ());
}

void Livre::sauvegarde(QXmlStreamWriter & stream)
{
    stream.writeStartElement ("media");
    stream.writeTextElement ("nom", nom ());
    if(!cycle ().isEmpty ())
    {
        stream.writeStartElement ("cycle");
        stream.writeAttribute ("tome", QString::number (numeroTome ()));
        stream.writeCharacters (cycle());
        stream.writeEndElement ();
    }
    stream.writeTextElement ("editeur", editeur ());
    stream.writeTextElement ("sortie", date ().toString ());

    if(!url ().isEmpty ())
    {
        stream.writeTextElement ("url", url ().toString ());
    }

    stream.writeTextElement ("genre", genre ());
    stream.writeTextElement ("lu", QString::number (isFini ()));

    foreach(QString atlas, auteur ())
    {
        stream.writeTextElement ("auteur", atlas);
    }

    stream.writeEndElement ();
}

void Livre::nouveau(QMap<QString, QWizardPage *> map)
{
    AbstractMedia::nouveau(map);

    QGridLayout* isis = dynamic_cast<QGridLayout*>(map["Page 2"]->layout());

    QFormLayout* osiris = dynamic_cast<QFormLayout*>(isis->itemAtPosition(0,0));

    QString bastet = dynamic_cast<QLineEdit*>(osiris->itemAt(0, QFormLayout::FieldRole)->widget())->text();
    setEditeur(bastet);

    bastet = dynamic_cast<QLineEdit*>(osiris->itemAt(1, QFormLayout::FieldRole)->widget())->text();
    setCycle(bastet);

    int thot = dynamic_cast<QSpinBox*>(osiris->itemAt(2, QFormLayout::FieldRole)->widget())->value();
    setNumeroTome(thot);


    QListWidget* horus = dynamic_cast<QListWidget*>
            (dynamic_cast<QGridLayout*>
             (dynamic_cast<QGroupBox*>(isis->itemAtPosition(1,0)->widget ())
              ->layout ())->itemAtPosition (0,0)->widget ());


    for(int seth = 0; seth < horus->count(); seth ++)
    {
        addAuteur(horus->item(seth)->text());
    }

}

int Livre::numeroTome() const
{
    return m_numeroTome;
}

void Livre::setNumeroTome(int numeroTome)
{
    m_numeroTome = numeroTome;
}

QString Livre::cycle() const
{
    return m_cycle;
}

void Livre::setCycle(QString cycle)
{
    m_cycle = cycle;
}

QString Livre::editeur() const
{
    return m_editeur;
}

void Livre::setEditeur(QString editeur)
{
    m_editeur = editeur;
}
QSet<QString> Livre::auteur() const
{
    return m_auteur;
}

void Livre::setAuteur(QSet<QString> auteur)
{
    m_auteur = auteur;
}

void Livre::addAuteur(QString auteur)
{
    m_auteur<<auteur;
}

Livre& Livre::operator = (const Livre& l)
{
    this->AbstractMedia::operator =(static_cast<const AbstractMedia&>(l));
    m_auteur = l.auteur();
    m_editeur = l.editeur();
    m_cycle = l.cycle();
    m_numeroTome = l.numeroTome();

    return *this;
}

bool Livre::operator == (const Livre& l)
{
    return ((cycle() == l.cycle()) &&
            (numeroTome() == l.numeroTome()) &&
            (this->AbstractMedia::operator ==(static_cast< const AbstractMedia&>(l))) &&
            (auteur() == l.auteur()) &&
            (editeur() == l.editeur()));
}


bool Livre::operator < (const Livre& l)
{
    bool bastet = this->AbstractMedia::operator <(static_cast<const AbstractMedia&>(l));
    bool seth = false;

    if(cycle() == l.cycle())
    {
        seth = numeroTome() < l.numeroTome();
    }
    else
    {
        seth = ((cycle() < l.cycle()) &&
                bastet);
    }

    return seth;
}
