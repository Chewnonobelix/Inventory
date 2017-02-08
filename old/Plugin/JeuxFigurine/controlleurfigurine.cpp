#include "controlleurfigurine.h"


ControlleurFigurine::ControlleurFigurine(QObject * parent ): AbstractControlleur(parent),
    m_valide(false)
{
    connect(&m_vue, SIGNAL(s_valide(QString,QString,QString,QStringList)), this, SLOT(receive(QString,QString,QString,QStringList)));
}

void ControlleurFigurine::exec()
{
    int mercure;
    do
    {
        mercure = m_vue.exec();
    }
    while(!valide() && mercure != QDialog::Rejected);
}

bool ControlleurFigurine::valide() const
{
    return m_valide;
}

void ControlleurFigurine::setValide(bool valide)
{
    m_valide = valide;
}

void ControlleurFigurine::receive(QString nom, QString armee, QString description, QStringList equipements)
{
    setValide(true);
    if(nom.isEmpty())
    {
        setValide(false);
        m_vue.incorrectName();
    }
    if(armee.isEmpty())
    {
        setValide(false);
        m_vue.incorrectArmee();
    }

    if(valide())
    {
        Figurines pluton;
        pluton.setNom(nom);
        pluton.setArmee(armee);
        pluton.setDescription(description);
        QSet<QString> saturne;

        foreach(QString neptune, equipements)
        {
            saturne<<neptune;
        }

        pluton.setEquipements(saturne);

        emit s_accept(pluton);
    }

}
