#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QMap>
#include <QDebug>
#include "view_global.h"

namespace Ui {
class Settings;
}

class VIEWSHARED_EXPORT Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QMap<QString, QVariant> = QMap<QString, QVariant>(), QMap<QString, QString> = QMap<QString, QString>(), QWidget *parent = 0);
    ~Settings();

    void setLanguageChoice(QMap<QString, QVariant>);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Settings *ui;


    void setLanguage(QMap<QString, QString>);
    void setNewData(QMap<QString, QString>);
    void setLoadData(QMap<QString, QString>);
    void setSaveData(QMap<QString, QString>);
    void setSaveAsData(QMap<QString, QString>);
    void setQuit(QMap<QString, QString>);
    void setUsers(QMap<QString, QString>);
    void setSearch(QMap<QString, QString>);
    void setSeeMedia(QMap<QString, QString>);
    void setAddMedia(QMap<QString, QString>);
    void setRemoveMedia(QMap<QString, QString>);
    void setSeeCategory(QMap<QString, QString>);
    void setAddCategory(QMap<QString, QString>);
    void setRemoveCategory(QMap<QString, QString>);
    void setSettings(QMap<QString, QString>);

    QString language() const;
    QString newData() const;
    QString loadData() const;
    QString saveData() const;
    QString saveAsData() const;
    QString quit() const;
    QString users() const;
    QString search() const;
    QString seeMedia() const;
    QString addMedia() const;
    QString removeMedia() const;
    QString seeCategory() const;
    QString addCategory() const;
    QString removeCategory() const;
    QString settings() const;

public slots:
    void accept();

signals:
    void s_setting(QMap<QString, QString>);
};

#endif // SETTINGS_H
