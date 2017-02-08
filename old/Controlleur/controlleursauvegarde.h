#ifndef CONTROLLEURSAUVEGARDE_H
#define CONTROLLEURSAUVEGARDE_H

#include "abstractcontrolleur.h"
#include "InterfacePlugin.h"

#include <QDir>
#include <QApplication>

class ControlleurSauvegarde: public AbstractControlleur
{
    Q_OBJECT

public:
    explicit ControlleurSauvegarde(QObject* = NULL);
    ~ControlleurSauvegarde();

    void exec();
};

#endif // CONTROLLEURSAUVEGARDE_H
