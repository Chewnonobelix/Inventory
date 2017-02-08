#ifndef LIVRE_H
#define LIVRE_H

#include "livre_global.h"
#include "../../Model/AbstractMedia.h"
#include <QSpinBox>
#include <QListWidget>

class LIVRESHARED_EXPORT Livre: public AbstractMedia
{
private:
    QSet<QString> m_auteur;
    QString m_editeur;
    QString m_cycle;
    int m_numeroTome;

public:
     Livre();
     Livre(const Livre&);
    ~Livre();

    //Accesseur
    QSet<QString> auteur() const;
    QString editeur() const;
    QString cycle() const;
    int numeroTome() const;

    //Mutateur
    void setAuteur(QSet<QString>);
    void addAuteur(QString);
    void setEditeur(QString);
    void setCycle(QString);
    void setNumeroTome(int);

    //Opérateur
    Livre& operator = (const Livre&);
    bool operator == (const Livre&);
    bool operator < (const Livre&);

    void chargement(QDomElement &);
    void sauvegarde(QXmlStreamWriter &);
    void nouveau(QMap<QString, QWizardPage *>);

};


#endif // LIVRE_H
