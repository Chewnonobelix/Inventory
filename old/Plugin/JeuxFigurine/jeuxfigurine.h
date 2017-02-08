#ifndef JEUXFIGURINE_H
#define JEUXFIGURINE_H

#include "jeuxfigurine_global.h"
#include "../../Model/AbstractMedia.h"
#include "livre.h"
#include "figurines.h"
#include <QString>
#include <QMultiMap>

class JEUXFIGURINESHARED_EXPORT JeuxFigurine: public AbstractMedia
{
private:
    QString m_editeur;
	QSet<Livre> m_livres;
    QMultiMap<QString, Figurines> m_figurines;
    QStringList m_divers;

public:
    JeuxFigurine();
    JeuxFigurine(const JeuxFigurine&);
    ~JeuxFigurine();

    const QMultiMap<QString, Figurines>& figurines() const;
    void setFigurines(QMultiMap<QString, Figurines>);
    void addFigurines(Figurines);
    void removeFigurine(QString, QStringList);
    const QSet<Livre>& livres() const;
    const Livre& livre(QString) const;
    void setLivres(QSet<Livre>);
    void addLivres(Livre);
    void removeLivre(QString);
    QStringList divers() const;
    void setDivers(QStringList);
    void addDivers(QString);
    QString editeur() const;
    void setEditeur(const QString &editeur);

    void chargement(QDomElement&);
    void sauvegarde(QXmlStreamWriter&);

    JeuxFigurine& operator = (const JeuxFigurine&);
    friend bool operator == (const JeuxFigurine&, const JeuxFigurine&);
    friend bool operator < (const JeuxFigurine&, const JeuxFigurine&);
};

#endif // JEUXFIGURINE_H
