#ifndef CONTROLLEURLIVRE_H
#define CONTROLLEURLIVRE_H

#include "../../Controlleur/abstractcontrolleur.h"
#include "ajoutlivre.h"
#include "livre.h"

class ControlleurLivre: public AbstractControlleur
{
    Q_OBJECT

private:
    bool m_valide;
    bool valider() const;
    AjoutLivre m_vue;

public:
    ControlleurLivre();
    void exec();

public slots:
    void valide(QList<QString>);

signals:
    void s_valide(QStringList);
};

#endif // CONTROLLEURLIVRE_H
