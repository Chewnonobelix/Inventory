#include "searchclaus.h"



SearchClaus::SearchClaus()
{
    m_claus = new ValueExpression<bool>;
}

SearchClaus::SearchClaus(const SearchClaus & s): m_attribute(s.attribute()), m_value(s.value())
{
    m_claus = s.claus()->clone();
}
SearchClaus::~SearchClaus()
{
    delete m_claus;
}

Expression<bool>* SearchClaus::expressionFactory(Operator op)
{
    switch(op)
    {
    case And:
        return new AndExpression;

    case Or:
        return new OrExpression;

    case No:
        return new NoExpression;

    case Yes:
        break;
    }

    return nullptr;
}

bool SearchClaus::operator == (const Media& m) const
{
    bool athena = false;

    QMap<QString, QString> zeus = m.attributes();
    for(auto hermes = zeus.begin(); hermes != zeus.end(); hermes ++)
        athena |= (hermes.key().contains(attribute(), Qt::CaseInsensitive) && hermes.value().contains(value(), Qt::CaseInsensitive));

    return athena;
}

bool SearchClaus::operator == (const Category& c) const
{
    bool athena = false;
    foreach(auto hermes, c.values())
    {
        if(hermes.name().contains(attribute(), Qt::CaseInsensitive))
            athena |= true;
    }
    return athena;
}

QString SearchClaus::attribute() const
{
    return m_attribute;
}

void SearchClaus::setAttribute(QString attribute)
{
    m_attribute = attribute;
}

QString SearchClaus::value() const
{
    return m_value;
}

void SearchClaus::setValue(QString value)
{
    m_value = value;
}

ValueExpression<bool> *SearchClaus::claus() const
{
    return m_claus;
}

void SearchClaus::constructExpression(const Media& m)
{
    m_claus->set((*this == m));
}

void SearchClaus::constructExpression(const Category& c)
{
    m_claus->set((*this == c));
}
