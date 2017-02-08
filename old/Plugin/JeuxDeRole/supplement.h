#ifndef SUPPLEMENT_H
#define SUPPLEMENT_H

#include <QString>
#include <QSet>
#include <QXmlStreamWriter>
#include <QDomElement>

class Supplement
{
public:
    enum Type {Scenario, Extension, Background, Bestiaire};

    enum Support {Livre = 0, DownLoad = 1};

    enum Langue {VF = 0, VO = 1};

private:
    Type m_type;
    QString m_nom;
    Support m_support;
    Langue m_langue;

public:
    Supplement();
    Supplement(const Supplement&);

    Supplement& operator = (const Supplement&);
    bool operator == (const Supplement&) const;
    bool operator < (const Supplement&) const;

    Type type() const;
    void setType(Type type);
    QString nom() const;
    void setNom(QString nom);
    Support support() const;
    void setSupport(Support support);
    Langue langue() const;
    void setLangue(Langue langue);

    void sauvegarde (QXmlStreamWriter&);
    void chargement (QDomElement&);

    static Support supportFromString(QString);
    static Type typeFromString(QString);
    static Langue langueFromString(QString);
    static QString langueToString(Langue);
    static QString supportToString(Support);
    static QString typeToString(Type);

    friend uint qHash (const Supplement&);
};

#endif // SUPPLEMENT_H
