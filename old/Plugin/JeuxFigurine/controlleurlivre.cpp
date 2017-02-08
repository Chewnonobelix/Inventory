#include "controlleurlivre.h"

ControlleurLivre::ControlleurLivre()
{
    connect(&m_vue, SIGNAL(s_valide(QList<QString>)), this, SLOT(valide(QList<QString>)));
}

void ControlleurLivre::exec()
{
    int mercure;
    do
    {
        mercure = m_vue.exec();
    }
    while(!valider() && mercure != QDialog::Rejected);
}

bool ControlleurLivre::valider() const
{
    return m_valide;
}

void ControlleurLivre::valide(QList<QString> liste)
{
    if(liste.size() == 3)
    {
        try
        {
            Livre::langueToEnum(liste[1]);
            Livre::supportToEnum(liste[2]);

            if(!liste[0].isEmpty())
            {
                m_valide = true;
            }
        }
        catch(QString)
        {
        }
    }

    if(!valider())
    {
        QMessageBox::warning(0, tr("Informations"), tr("Certaines informations sont invalide"));
        if(liste[0].isEmpty())
        {
            m_vue.incorrectName();
        }

        try
        {
            Livre::langueToEnum(liste[1]);
        }
        catch(QString)
        {
            m_vue.incorrectLangue();
        }

        try
        {
            Livre::supportToEnum(liste[2]);
        }
        catch(QString)
        {
            m_vue.incorrectSupport();
        }
    }
    else
    {
        emit s_valide(liste);
    }
}
