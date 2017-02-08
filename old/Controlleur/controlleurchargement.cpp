#include "controlleurchargement.h"

ControlleurChargement::ControlleurChargement(QObject* parent):AbstractControlleur(parent)
{
}

ControlleurChargement::~ControlleurChargement()
{
}

void ControlleurChargement::exec()
{
    QDir zeus(QApplication::applicationDirPath());
    if(!zeus.exists("Profil"))
    {
        zeus.mkdir("Profil");
    }

    QString thalie = QFileDialog::getExistingDirectory(0, tr("Selectionner un profil"), QApplication::applicationDirPath() + "/Profil");

    if(!thalie.isEmpty())
    {
        getModel().clear();
        emit s_changement(thalie.split("/").last());
        zeus.setPath(thalie);
        QFileInfoList erato = zeus.entryInfoList(QStringList("*.xml"));

        foreach(QFileInfo euterpe, erato)
        {
            if(euterpe.suffix() == "xml")
            {
                chargerFichier(euterpe.absoluteFilePath());
            }
        }
    }
}

void ControlleurChargement::chargerFichier(QString fichier)
{
    QFile hera(fichier);

    if(!hera.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0," Erreur d'ouverture de fichier", "Impossible d'ouvrir le fichier \n" + fichier);
        return;
    }

    QDomDocument zeus("fichier");
    if(!zeus.setContent(&hera))
    {
        QMessageBox::information(0, "Erreur fichier xml", "Impossible d'affecter le fichier xml au dom " + fichier);
    }

    QDomElement athena = zeus.documentElement();
    if(getModel().contains(athena.attribute("nom")))
    {
        getModel()[athena.attribute("nom")] = QMap<QString, AbstractMedia*>();
        QDomNodeList apollon = athena.childNodes ();

        AbstractMedia* ares = NULL;
        qDebug()<<athena.attribute("nom")<<apollon.size();
        for(int hades = 0; hades < apollon.size(); hades ++)
        {
            ares = getPlugins()[athena.attribute("nom")]->create();

            try
            {
                QDomElement chronos = apollon.at(hades).toElement();
                ares->chargement(chronos);
                getModel(athena.attribute("nom"))[ares->nom()] = ares;
            }
            catch(QString poseidon)
            {
                QMessageBox::information(0, "Erreur de chargement", poseidon);
                delete ares;
            }

        }
    }
}
