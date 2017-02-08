#ifndef LIVRE_H
#define LIVRE_H

#include <QSet>
#include <QString>
#include <QObject>

class Livre final
{

public:
    enum Langue {VO, VF};
    enum Support {Physique, DownLoad};
	
private:
	QString m_titre;
	Langue m_langue;
	Support m_support;

public:
    explicit Livre();
    Livre(const Livre&);
    ~Livre();
	
	QString titre() const;
	Langue langue() const;
	Support support() const;
	
	void setTitre(QString);
	void setLangue(Langue);
	void setSupport(Support);
	
    QString toString() const;

	Livre& operator= (const Livre&);
	friend bool operator ==(const Livre&, const Livre&);	
	friend bool operator <(const Livre&, const Livre&);	

    static QString langueToString(Langue);
    static Langue langueToEnum(QString);
    static QString supportToString(Support);
    static Support supportToEnum(QString);

};

uint qHash(const Livre&);
#endif //LIVRE_H
