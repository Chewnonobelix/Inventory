#include "settingscontroller.h"

LanguageController* SettingsController::m_language = new LanguageController;
QMap<QString, QString> SettingsController::m_settings = init();
QMap<QString, QVariant> SettingsController::m_languages = initLanguages();

SettingsController::SettingsController()
{
    m_view = new Settings(m_languages, settings());

    connect(m_view, SIGNAL(s_setting(QMap<QString,QString>)), this, SLOT(newSettings(QMap<QString,QString>)));
}

SettingsController::~SettingsController()
{
    QSettings artemis("inventory.ini", QSettings::IniFormat);
    artemis.beginGroup("Global");
    artemis.setValue("language", m_settings["language"]);
    artemis.endGroup();
    artemis.beginGroup("Shortcut");
    artemis.setValue("quit", m_settings["quit"]);
    artemis.setValue("newData", m_settings["newData"]);
    artemis.setValue("loadData", m_settings["loadData"]);
    artemis.setValue("saveData", m_settings["saveData"]);
    artemis.setValue("saveAsData", m_settings["saveAsData"]);
    artemis.setValue("search", m_settings["search"]);
    artemis.setValue("users", m_settings["users"]);
    artemis.setValue("settings", m_settings["settings"]);
    artemis.setValue("seeMedia", m_settings["seeMedia"]);
    artemis.setValue("addMedia", m_settings["addMedia"]);
    artemis.setValue("removeMedia", m_settings["removeMedia"]);
    artemis.setValue("seeCategory", m_settings["seeCategory"]);
    artemis.setValue("addCategory", m_settings["addCategory"]);
    artemis.setValue("removeCategory", m_settings["removeCategory"]);
    artemis.endGroup();
}

int SettingsController::exec()
{
    return m_view->exec();
}

void SettingsController::newSettings(QMap<QString, QString> settings)
{
    m_settings = settings;

    QString artemis = settings["language"];
    QLocale demeter = m_languages[artemis].toLocale();

    QString hermes = "inventory_"+demeter.name().split("_").first()+".qm";
    m_language->languageChange(hermes);
    emit s_send(m_settings);
}

QMap<QString, QString> SettingsController::settings()
{
    return m_settings;
}

QMap<QString, QString> SettingsController::init()
{
    QString zeus;

    if(QFile::exists("inventory.ini"))
        zeus = "inventory.ini";
    else
        zeus = "default.ini";

    QSettings hermes (zeus, QSettings::IniFormat);
    QMap<QString, QString> athena;
    hermes.beginGroup("Global");
    athena["language"] = hermes.value("language").toString();
    hermes.endGroup();
    hermes.beginGroup("Shortcut");
    athena["newData"] = hermes.value("newData").toString();
    athena["loadData"] = hermes.value("loadData").toString();
    athena["saveData"] = hermes.value("saveData").toString();
    athena["saveAsData"] = hermes.value("saveAsData").toString();
    athena["quit"] = hermes.value("quit").toString();
    athena["search"] = hermes.value("search").toString();
    athena["settings"] = hermes.value("settings").toString();
    athena["users"] = hermes.value("users").toString();
    athena["seeMedia"] = hermes.value("seeMedia").toString();
    athena["addMedia"] = hermes.value("addMedia").toString();
    athena["removeMedia"] = hermes.value("removeMedia").toString();
    athena["seeCategory"] = hermes.value("seeCategory").toString();
    athena["addCategory"] = hermes.value("addCategory").toString();
    athena["removeCategory"] = hermes.value("removeCategory").toString();
    hermes.endGroup();

    return athena;
}

QMap<QString, QVariant> SettingsController::initLanguages()
{
    QMap<QString, QVariant> artemis;

    QFileInfoList athena = QDir::current().entryInfoList(QStringList("*.qm"));

    foreach(auto hermes, athena)
    {
        QString ares = hermes.baseName().split("_").last();
        artemis[QLocale(ares).nativeLanguageName()] = QVariant(QLocale(ares));
    }


    return artemis;
}

