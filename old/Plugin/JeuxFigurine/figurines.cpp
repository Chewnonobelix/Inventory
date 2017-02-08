#include "figurines.h"


Figurines::Figurines(): m_nom(""), m_description(""), m_armee("")
{
}

Figurines::Figurines(const Figurines & f):
    m_nom(f.nom()), m_description(f.description()), m_equipements(f.equipements()), m_armee(f.armee())
{
}

Figurines::~Figurines()
{
}

QString Figurines::nom() const
{
    return m_nom;
}

void Figurines::setNom(QString nom)
{
    m_nom = nom;
}

QString Figurines::description() const
{
    return m_description;
}

void Figurines::setDescription(QString description)
{
    m_description = description;
}

QSet<QString> Figurines::equipements() const
{
    return m_equipements;
}

void Figurines::setEquipements(QSet<QString> equipements)
{
    m_equipements = equipements;
}

void Figurines::addEquipements(QString e)
{
    m_equipements<<e;
}

QString Figurines::armee() const
{
    return m_armee;
}

void Figurines::setArmee(QString armee)
{
    m_armee = armee;
}

Figurines& Figurines::operator= (const Figurines& f)
{
    setNom(f.nom());
    setDescription(f.description());
    setEquipements(f.equipements());
    setArmee(f.armee());

    return *this;
}

bool operator == (const Figurines& f1,const Figurines& f2)
{
    return ((f1.nom() == f2.nom()) &&
            (f1.description() == f2.description()) &&
            (f1.equipements() == f2.equipements()) &&
            (f1.armee() == f2.armee()));
}

bool operator < (const Figurines& f1,const Figurines& f2)
{
    return (f1.nom() < f2.nom()) && (f1.armee() < f2.armee());
}

QString Figurines::toString() const
{
    //TODO
    QString junon;

    junon = QObject::tr("Nom: ") + nom() + "\n\n";
    junon += QObject::tr("Armée: ") + armee() + "\n\n";

    junon += QObject::tr("Equipements: \n");

    foreach (QString remus, equipements())
    {
        junon += remus + "\n";
    }
    junon += QObject::tr("Description: ") + description();

    return "TODO";
}

uint qHash(const Figurines& f)
{
    uint remus = 0;
    foreach(QString junon, f.equipements())
    {
        remus += qHash(junon);
    }

    return qHash(f.nom()) + qHash(f.armee()) + remus;
}

QString Figurines::equipmentToString() const
{
    QString junon = "";

    foreach(QString jupiter, equipements())
    {
        junon += jupiter + ", ";
    }

    junon.remove(junon.size() - 2, 2);
    if(junon.isEmpty())
    {
        junon = QObject::tr("Defaut");
    }

    return junon;
}
