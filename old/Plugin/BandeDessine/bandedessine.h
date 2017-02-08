#ifndef BANDEDESSINE_H
#define BANDEDESSINE_H

#include "../../Model/AbstractMedia.h"
#include "wizardpagebd.h"
#include "bandedessine_global.h"

class BANDEDESSINESHARED_EXPORT BandeDessine : public AbstractMedia
{
private:
    QMap<int, QString> m_tome;
    QSet<QString> m_auteur;
    QSet<QString> m_dessinateur;
    bool m_enCoursAchat;
    bool m_lu;

public:
    BandeDessine();
    BandeDessine(const BandeDessine&);
    ~BandeDessine();

    //Accesseur
    bool isEnCoursAchat() const;
    bool isLu() const;
    QMap<int,QString> getTome() const;
    QString getTome(int) const;
    QSet<QString> getAuteur() const;
    QSet<QString> getDessinateur() const;

    //Mutateur
    void setEnCoursAchat(bool);
    void setLu(bool);
    void setTome(QMap<int, QString>);
    void addTome(int, QString);
    void setAuteur(QSet<QString>);
    void addAuteur(QString);
    void setDessinateur(QSet<QString>);
    void addDessinateur(QString);

    int findTome(QString) const;

    void chargement(QDomElement &);
    void sauvegarde(QXmlStreamWriter &);
    void nouveau(QMap<QString, QWizardPage*>);

    BandeDessine& operator = (const BandeDessine&);
    bool operator ==(const BandeDessine&);
    bool operator <(const BandeDessine&);
};

#endif // BANDEDESSINE_H
