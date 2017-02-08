#ifndef FILM_H
#define FILM_H

#include <QTime>

#include "film_global.h"
#include "../../Model/AbstractMedia.h"

#include <QListWidget>

class FILMSHARED_EXPORT Film: public AbstractMedia
{
public: enum Support{aucun = 0, DVD = 1, Graver = 2, divx = 4, VHS = 8, BlueRay = 16};

private:
    QString m_realisateur;
    QString m_scenariste;
    QSet<QString> m_acteurPrincipaux;
    QString m_type;
    QTime m_duree;
    Support m_support;

public:
    explicit Film();
    Film(const Film&);
    ~Film();

    //Accesseur
    QString getRealisateur() const;
    QString getScenariste() const;
    QSet<QString> getActeursPrincipaux() const;
    QString getType() const;
    QTime getDuree() const;
    Support getSupport() const;

    //Mutateur
    void setRealisateur(QString);
    void setScenariste(QString);
    void setActeurPrincipaux(QSet<QString>);
    void addActeur(QString);
    void setType(QString);
    void setDuree(QTime);
    void setSupport(Support);

    //Opérateur
    Film& operator = (const Film&);
    bool operator == (const Film&);
    bool operator < (const Film&);

    void chargement(QDomElement &);
    void sauvegarde(QXmlStreamWriter &);
    void nouveau(QMap<QString, QWizardPage *>);
};

#endif // FILM_H
