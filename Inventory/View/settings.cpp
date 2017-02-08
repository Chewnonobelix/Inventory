#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QMap<QString, QVariant> language, QMap<QString, QString> settings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    setLanguageChoice(language);

    setLanguage(settings);
    setNewData(settings);
    setLoadData(settings);
    setSaveAsData(settings);
    setSaveData(settings);
    setQuit(settings);
    setUsers(settings);
    setSearch(settings);
    setSeeCategory(settings);
    setAddCategory(settings);
    setRemoveCategory(settings);
    setSeeMedia(settings);
    setAddMedia(settings);
    setRemoveMedia(settings);
    setSettings(settings);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Settings::accept()
{
    QMap<QString, QString> hermes;

    hermes["language"] = language();
    hermes["seeMedia"] = seeMedia();
    hermes["addMedia"] = addMedia();
    hermes["removeMedia"] = removeMedia();
    hermes["seeCategory"] = seeCategory();
    hermes["addCategory"] = addCategory();
    hermes["removeCategory"] = removeCategory();
    hermes["newData"] = newData();
    hermes["loadData"] = loadData();
    hermes["saveData"] = saveData();
    hermes["saveAsData"] = saveAsData();
    hermes["quit"] = quit();
    hermes["search"] = search();
    hermes["users"] = users();
    hermes["settings"] = settings();

    emit s_setting(hermes);
    close();
}

void Settings::setLanguage(QMap<QString, QString> s)
{
    ui->w_language->setCurrentIndex(ui->w_language->findText(s["language"]));
}

void Settings::setNewData(QMap<QString, QString> s)
{
    ui->w_newData->setKeySequence(QKeySequence::fromString(s["newData"]));
}

void Settings::setLoadData(QMap<QString, QString> s)
{
    ui->w_loadData->setKeySequence(QKeySequence::fromString(s["loadData"]));
}

void Settings::setSaveData(QMap<QString, QString> s)
{
    ui->w_saveData->setKeySequence(QKeySequence::fromString(s["saveData"]));
}

void Settings::setSaveAsData(QMap<QString, QString> s)
{
    ui->w_saveAsData->setKeySequence(QKeySequence::fromString(s["saveAsData"]));
}

void Settings::setQuit(QMap<QString, QString> s)
{
    ui->w_quit->setKeySequence(QKeySequence::fromString(s["quit"]));
}

void Settings::setUsers(QMap<QString, QString> s)
{
    ui->w_users->setKeySequence(QKeySequence::fromString(s["users"]));
}

void Settings::setSearch(QMap<QString, QString> s)
{
    ui->w_search->setKeySequence(QKeySequence::fromString(s["search"]));
}

void Settings::setSeeMedia(QMap<QString, QString> s)
{
    ui->w_seeMedia->setKeySequence(QKeySequence::fromString(s["seeMedia"]));
}

void Settings::setAddMedia(QMap<QString, QString> s)
{
    ui->w_addMedia->setKeySequence(QKeySequence::fromString(s["addMedia"]));
}

void Settings::setRemoveMedia(QMap<QString, QString> s)
{
    ui->w_removeMedia->setKeySequence(QKeySequence::fromString(s["removeMedia"]));
}

void Settings::setSeeCategory(QMap<QString, QString> s)
{
    ui->w_seeCategory->setKeySequence(QKeySequence::fromString(s["seeCategory"]));
}

void Settings::setAddCategory(QMap<QString, QString> s)
{
    ui->w_addCategory->setKeySequence(QKeySequence::fromString(s["addCategory"]));
}

void Settings::setRemoveCategory(QMap<QString, QString> s)
{
    ui->w_removeCategory->setKeySequence(QKeySequence::fromString(s["removeCategory"]));
}

void Settings::setSettings(QMap<QString, QString> s)
{
    ui->w_settings->setKeySequence(QKeySequence::fromString(s["settings"]));
}

QString Settings::language() const
{
    return ui->w_language->currentText();
}
QString Settings::newData() const
{
    return ui->w_newData->keySequence().toString();
}
QString Settings::loadData() const
{
    return ui->w_loadData->keySequence().toString();
}

QString Settings::saveData() const
{
    return ui->w_saveData->keySequence().toString();
}

QString Settings::saveAsData() const
{
    return ui->w_saveAsData->keySequence().toString();
}

QString Settings::quit() const
{
    return ui->w_quit->keySequence().toString();
}

QString Settings::users() const
{
    return ui->w_users->keySequence().toString();
}

QString Settings::search() const
{
    return ui->w_search->keySequence().toString();
}

QString Settings::seeMedia() const
{
    return ui->w_seeMedia->keySequence().toString();
}

QString Settings::addMedia() const
{
    return ui->w_addMedia->keySequence().toString();
}

QString Settings::removeMedia() const
{
    return ui->w_removeMedia->keySequence().toString();
}

QString Settings::seeCategory() const
{
    return ui->w_seeCategory->keySequence().toString();
}

QString Settings::addCategory() const
{
    return ui->w_addCategory->keySequence().toString();
}

QString Settings::removeCategory() const
{
    return ui->w_removeCategory->keySequence().toString();
}

QString Settings::settings() const
{
    return ui->w_settings->keySequence().toString();
}

void Settings::setLanguageChoice(QMap<QString, QVariant> list)
{
    ui->w_language->clear();
    ui->w_language->addItem(tr("System default"));

    for(auto athena = list.begin(); athena != list.end(); athena++)
        ui->w_language->addItem(athena.key(), athena.value());
}
