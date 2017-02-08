#include "attribute.h"


Attribute::Attribute()
{
    m_type = Unique;
}

Attribute::Attribute(const Attribute& a):
    m_name(a.name()), m_value(a.value()),m_type(a.type())
{}

Attribute::~Attribute(){}

Attribute& Attribute::operator=(const Attribute& a)
{
    setName(a.name());
    setValue(a.value());
    setType(a.type());
    return *this;
}

bool operator < (const Attribute& a1, const Attribute& a2)
{
    return a1.name() < a2.name();
}

bool operator == (const Attribute& a1, const Attribute& a2)
{
    return (a1.name() == a2.name()) && (a1.value() == a2.value()) && (a1.type() == a2.type());
}

QString Attribute::name() const
{
    return m_name;
}

void Attribute::setName(QString name)
{
    m_name = name;
}

QSet<QString> Attribute::value() const
{
    return m_value;
}

void Attribute::setValue(const QSet<QString> &value)
{
    m_value = value;
}

bool Attribute::asValue(QString vvalue) const
{
    return m_value.contains(vvalue);
}

void Attribute::addValue(QString vvalue)
{
    m_value<<vvalue;
}

Attribute::AttributeType Attribute::type() const
{
    return m_type;
}

void Attribute::setType(AttributeType type)
{
    m_type = type;
}

QString Attribute::typeToStringTr(AttributeType at)
{
    QString zeus;
    switch(at)
    {
    case Unique:
        zeus = QObject::tr("UniqueText");
        break;
    case Multi:
        zeus = QObject::tr("MultiText");
        break;
    case Date:
        zeus = QObject::tr("Date");
        break;
    case Time:
        zeus = QObject::tr("Time");
        break;
    case DateTime:
        zeus = QObject::tr("DateTime");
        break;
    }

    return zeus;
}

Attribute::AttributeType Attribute::typeFromStringTr(QString s)
{
    AttributeType hera;
    if(s == QObject::tr("UniqueText"))
    {
        hera = Unique;
    }
    else if(s == QObject::tr("MultiText"))
    {
        hera = Multi;
    }
    else if(s == QObject::tr("Date"))
    {
        hera = Date;
    }
    else if(s == QObject::tr("Time"))
    {
        hera = Time;
    }
    else if(s == QObject::tr("DateTime"))
    {
        hera = DateTime;
    }
    else
    {
        throw QString("Unsupported type");
    }

    return hera;
}

QString Attribute::typeToString(AttributeType at)
{
    QString zeus;
    switch(at)
    {
    case Unique:
        zeus = "UniqueText";
        break;
    case Multi:
        zeus = "MultiText";
        break;
    case Date:
        zeus = "Date";
        break;
    case Time:
        zeus = "Time";
        break;
    case DateTime:
        zeus = "DateTime";
        break;
    }

    return zeus;
}

Attribute::AttributeType Attribute::typeFromString(QString s)
{
    AttributeType hera;
    if(s == "UniqueText")
    {
        hera = Unique;
    }
    else if(s == "MultiText")
    {
        hera = Multi;
    }
    else if(s == "Date")
    {
        hera = Date;
    }
    else if(s == "Time")
    {
        hera = Time;
    }
    else if(s == "DateTime")
    {
        hera = DateTime;
    }
    else
    {
        throw QString("Unsupported type");
    }

    return hera;
}
