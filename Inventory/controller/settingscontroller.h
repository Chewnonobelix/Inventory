#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include <QAction>
#include <QSettings>
#include <QFile>
#include <QTranslator>
#include <QLocale>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QApplication>
#include "controller_global.h"
#include "abstractcontroller.h"
#include "settings.h"
#include "languagecontroller.h"

class CONTROLLERSHARED_EXPORT SettingsController final: public AbstractController
{
    Q_OBJECT

private:
    Settings* m_view;
    static QTranslator* m_translator;

    static QMap<QString, QString> m_settings;
    static QMap<QString, QString> init();
    static QMap<QString, QVariant> m_languages;
    static QMap<QString, QVariant> initLanguages();
    static LanguageController* m_language;

public:
    SettingsController();
    ~SettingsController();
    int exec();
    static QMap<QString, QString> settings();


public slots:
    void newSettings(QMap<QString, QString>);

signals:
    void s_send(QMap<QString, QString>);
};

#endif // SETTINGSCONTROLLER_H
