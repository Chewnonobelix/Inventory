#ifndef ABSTRACTCONTROLLEUR_H
#define ABSTRACTCONTROLLEUR_H

#include "controlleur_global.h"
#include "../Model/AbstractMedia.h"

#include <QObject>
#include <QMap>
#include <QSet>
#include <QString>
#include <QDebug>
#include <QXmlStreamWriter>
#include <QMessageBox>

class InterfacePlugin;

class CONTROLLEURSHARED_EXPORT AbstractControlleur: public QObject
{
    Q_OBJECT

private:
    static QMap<QString,QMap<QString, AbstractMedia*> > m_model;
    static QString m_profil;
    static QMap<QString, InterfacePlugin*> m_plugins;

protected:

public:
    explicit AbstractControlleur(QObject* = 0);
    ~AbstractControlleur(){}

    static QMap<QString, AbstractMedia*>& getModel(QString);
    static QMap<QString, QMap<QString, AbstractMedia*> >& getModel();
    static QString getProfil();

    static void setProfil(QString);

    static QMap<QString, InterfacePlugin*>& getPlugins();

    virtual void exec() = 0;

public slots:
};

#endif // ABSTRACTCONTROLLEUR_H
