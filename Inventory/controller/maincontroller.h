#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QMap>
#include "abstractcontroller.h"
#include "mainwindow.h"
#include "savecontroller.h"
#include "loadcontroller.h"
#include "controller_global.h"
#include "categorycontroller.h"
#include "mediacontroller.h"
#include "usercontroller.h"
#include "languagecontroller.h"
#include "researchcontroller.h"
#include "settingscontroller.h"

class CONTROLLERSHARED_EXPORT MainController final: public AbstractController
{
    Q_OBJECT

private:
    MainWindowPointer m_mw;
    QString m_currentFile;
    ResearchController m_search;

    void setCurrentTable(QString);
public:
    MainController();
    ~MainController();

    int exec();

public slots:
    void save(QString);
    void load(QString);
    void newBase();
    void newMedia(QString);
    void newCategory(QString);
    void removeCategory(QString);
    void removeMedia(QString, QString);
    void editCategory();
    void editMedia();
    void showCategory();
    void setUser();
    void userChange();
    void search();
    void showSearch(QList<MediaSPointer>);
    void settings();
    void setShortcut(QMap<QString, QString>);
};

#endif // MAINCONTROLLER_H
