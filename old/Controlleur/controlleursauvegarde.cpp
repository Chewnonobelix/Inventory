#include "controlleursauvegarde.h"
#include <QDebug>

ControlleurSauvegarde::ControlleurSauvegarde(QObject* parent): AbstractControlleur(parent)
{
}

ControlleurSauvegarde::~ControlleurSauvegarde()
{
}

void ControlleurSauvegarde::exec()
{
    foreach(InterfacePlugin* atlas, getPlugins())
    {
        qDebug()<<atlas->getNomAffichage();
        QFile ares;

        ares.setFileName(QApplication::applicationDirPath() + "/Profil/"+getProfil()+"/"+atlas->getNomFichier()+".xml");

        if(!ares.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(0, "Erreur", "Impossible d'ouvrir le fichier " + ares.fileName());
            return;
        }

        QXmlStreamWriter hermes(&ares);
        hermes.setCodec("utf8");
        hermes.setAutoFormatting(true);
        hermes.writeStartDocument();
        hermes.writeStartElement("categorie");
        hermes.writeAttribute("nom", atlas->getNomAffichage());

        QMap<QString, AbstractMedia*> chronos = getModel(atlas->getNomAffichage());
        foreach(AbstractMedia* zeus, chronos)
        {
            try
            {
                zeus->sauvegarde(hermes);
            }
            catch(QString dyonisos)
            {
                qDebug()<<dyonisos;
            }
        }

        hermes.writeEndElement();
        hermes.writeEndDocument();

        ares.close();
    }
}
