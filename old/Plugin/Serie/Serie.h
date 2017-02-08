
#ifndef __Serie_h__
#define __Serie_h__

#include "../../Model/AbstractMedia.h"
#include "wizardpageserie.h"
#include "serie_global.h"

#include <exception>
#include <QMap>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QGridLayout>

using namespace std;

// class AbstractMedia;
class Serie;

class SERIESHARED_EXPORT Serie: public AbstractMedia
{
public: enum Visionnage{non = 0, encours = 1, vue = 2};

private:
    QMap<int, int> m_nbEpisode;
    Visionnage m_visionnage;

public:
    Serie();
    Serie(const Serie&);
    ~Serie();

    QMap<int, int> getNbEpisode() const;
    int getNbEpisode(int)  const;
    Visionnage getVisionnage() const;

    void setNbEpisode(int, int);
    void setNbEpisode(QMap<int, int>);
    void setVisionnage(Visionnage);

    Serie& operator=(const Serie&);
    bool operator==(const Serie&);
    bool operator<(const Serie&);

    void chargement(QDomElement&);
    void sauvegarde(QXmlStreamWriter&);
    void nouveau(QMap<QString, QWizardPage*>);

    static QWizardPage* getPage();
};

#endif
