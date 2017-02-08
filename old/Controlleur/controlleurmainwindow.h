#ifndef CONTROLLEURMAINWINDOW_H
#define CONTROLLEURMAINWINDOW_H

#include "controlleur_global.h"
#include "abstractcontrolleur.h"
#include "controlleurchargement.h"
#include "controlleursauvegarde.h"
#include "wizardpagechoix.h"
#include "InterfacePlugin.h"

#include "../Vue/mainwindow.h"


#include <QDir>
#include <QXmlStreamWriter>
#include <QPluginLoader>
#include <QFileInfoList>

class CONTROLLEURSHARED_EXPORT ControlleurMain : public AbstractControlleur
{
    Q_OBJECT

private:
    MainWindow* m_vue;
    QWizard* m_wizard;

    void ajouterFichier(QString, QString, QString);
public:
    explicit ControlleurMain(QObject* = 0);
    ~ControlleurMain();
    MainWindow* getVue() const;

    void exec();

public slots:
    void nouveau(QString);
    void chargement();
    void changement(QString);
    void sauvegarde();
    void ajouter();
    void changePage(QString);
    void changeCategorie(QString);
    void selection(QString, QString);
};

#endif // CONTROLLEURMAINWINDOW_H
