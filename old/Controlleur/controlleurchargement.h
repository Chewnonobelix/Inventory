#ifndef CONTROLLEURCHARGEMENT_H
#define CONTROLLEURCHARGEMENT_H

#include "abstractcontrolleur.h"
#include "InterfacePlugin.h"
#include <QtWidgets/QFileDialog>
#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

class ControlleurChargement: public AbstractControlleur
{
    Q_OBJECT
private:
    void chargerFichier(QString);

public:
    explicit ControlleurChargement(QObject* = 0);
    ~ControlleurChargement();

    void exec();

signals:
    void s_changement(QString);
};

#endif // CONTROLLEURCHARGEMENT_H
