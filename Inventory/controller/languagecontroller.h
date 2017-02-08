#ifndef LANGUAGECONTROLLER_H
#define LANGUAGECONTROLLER_H

#include <QApplication>
#include <QTranslator>
#include <QDebug>
#include "abstractcontroller.h"
#include "loadcontroller.h"

class LanguageController final: public QObject
{
    Q_OBJECT

private:
    QTranslator* m_language;

public:
    LanguageController();
    ~LanguageController();
    QTranslator* translator() const;
    void setTranslator(QTranslator*);

public slots:
    void languageChange(QString);
};

#endif // LANGUAGECONTROLLER_H
