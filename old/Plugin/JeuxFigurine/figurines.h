#ifndef FIGURINES_H
#define FIGURINES_H

#include <QString>
#include <QSet>
#include <QObject>

class Figurines
{
private:
    QString m_nom;
    QString m_description;
    QSet<QString> m_equipements;
    QString m_armee;

public:
    explicit Figurines();
    Figurines(const Figurines&);
    ~Figurines();

    QString nom() const;
    void setNom(QString);
    QString description() const;
    void setDescription(QString);
    QSet<QString> equipements() const;
    void setEquipements(QSet<QString>);
    void addEquipements(QString);
    QString armee() const;
    void setArmee(QString);

    QString toString() const;
    QString equipmentToString() const;
    Figurines& operator= (const Figurines&);
    friend bool operator == (const Figurines&,const Figurines&);
    friend bool operator < (const Figurines&,const Figurines&);
};

uint qHash(const Figurines&);

#endif // FIGURINES_H
