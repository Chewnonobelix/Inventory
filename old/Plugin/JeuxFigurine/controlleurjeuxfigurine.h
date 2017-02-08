#ifndef CONTROLLEURJEUXFIGURINE_H
#define CONTROLLEURJEUXFIGURINE_H

#include "../../Controlleur/controlleurplugin.h"
#include "fenetrejeuxfigurine.h"
#include "controlleurlivre.h"
#include "controlleurfigurine.h"

class ControlleurJeuxFigurine: public AbstractControlleurPlugin
{
    Q_OBJECT

private:
    QMultiMap<QString, Figurines> m_tempFig;
    QSet<Livre> m_tempLivre;

public:
    explicit ControlleurJeuxFigurine(QString nom, InterfacePlugin* ip, QObject* parent = 0):
        AbstractControlleurPlugin(nom, ip, parent)
    {
        setVue();

    }

    ~ControlleurJeuxFigurine(){}

    void setVue();
    QStringList getListeSort() const;

private slots:
    void valideAjoutLivre(QStringList);
    void valideAjoutFigurine(Figurines);

public slots:
    void ajoutLivre();
    void ajoutFigurine();
    void accept(QSet<QString>, QSet<QString>, QMultiMap<QString, QStringList>);

};

#endif // CONTROLLEURJEUXFIGURINE_H
