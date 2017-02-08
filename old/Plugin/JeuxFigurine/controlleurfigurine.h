#ifndef CONTROLLEURFIGURINE_H
#define CONTROLLEURFIGURINE_H

#include "figurines.h"
#include "ajoutfigurine.h"
#include "../../Controlleur/abstractcontrolleur.h"

class ControlleurFigurine: public AbstractControlleur
{
    Q_OBJECT

private:
    AjoutFigurine m_vue;
    bool m_valide;
    bool valide() const;
    void setValide(bool valide);

public:
    explicit ControlleurFigurine(QObject* = 0);
    void exec();

public slots:
    void receive(QString, QString, QString, QStringList);

signals:
    void s_accept(Figurines);
};

#endif // CONTROLLEURFIGURINE_H
