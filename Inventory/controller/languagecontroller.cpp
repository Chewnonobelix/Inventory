#include "languagecontroller.h"

LanguageController::LanguageController()
{
    QString hermes = QLocale::system().name().section('_', 0, 0);
    m_language = new QTranslator;
    m_language->load("inventory_" + hermes+".qm");
}

LanguageController::~LanguageController()
{
    delete m_language;
}

void LanguageController::languageChange(QString language)
{
    qApp->removeTranslator(m_language);
    m_language = new QTranslator;

    if(m_language->load(language))
    {
        qApp->installTranslator(m_language);
    }
}


QTranslator* LanguageController::translator() const
{
    return m_language;
}

void LanguageController::setTranslator(QTranslator* tr)
{
    QApplication::removeTranslator(m_language);
    m_language = tr;
    QApplication::installTranslator(tr);
}
