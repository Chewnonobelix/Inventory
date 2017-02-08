#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QString>
#include <QSet>
#include <QObject>
#include <QSharedPointer>
#include <QDebug>
#include "model_global.h"

class MODELSHARED_EXPORT Attribute;

typedef QSharedPointer<Attribute> AttributeSPointer;

class MODELSHARED_EXPORT Attribute
{
public:
    enum AttributeType {Unique = 0, Multi = 1, Date = 2, Time = 4, DateTime = 8};

private:
    QString m_name;
    QSet<QString> m_value;

    AttributeType m_type;


public:
    Attribute();
    Attribute(const Attribute&);
    ~Attribute();

    Attribute& operator=(const Attribute&);
    friend bool operator < (const Attribute&, const Attribute&);
    friend bool operator == (const Attribute&, const Attribute&);

    QString name() const;
    void setName(QString);

    QSet<QString> value() const;
    bool asValue(QString) const;
    void addValue(QString);
    void setValue(const QSet<QString> &);
    AttributeType type() const;
    void setType(AttributeType);

    static QString typeToStringTr(AttributeType);
    static AttributeType typeFromStringTr(QString);
    static QString typeToString(AttributeType);
    static AttributeType typeFromString(QString);

    operator QString () const
    {
        return name();
    }
};


#endif // ATTRIBUTE_H
