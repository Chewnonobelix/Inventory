#ifndef __AbstractMedia_h__
#define __AbstractMedia_h__

#include <exception>
#include <QString>
#include <QDate>
#include <QUrl>
#include <QtXML/QDomElement>
#include <QFile>
#include <QXmlStreamWriter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QLabel>
#include <QObject>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QDateEdit>
#include <QDebug>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWizardPage>

class AbstractMedia
{
private:
    QString m_nom;
    QString m_genre;
    QDate m_date;
    bool m_fini;
    QUrl m_url;

public:
    AbstractMedia();
    AbstractMedia(const AbstractMedia&);
    virtual ~AbstractMedia();

    QDate date() const;
    void setDate(QDate);
    QString nom() const;
    void setNom(QString);
    QString genre() const;
    void setGenre(QString);
    bool isFini() const;
    void setFini(bool);
    QUrl url() const;
    void setUrl(QUrl);

    AbstractMedia& operator=(const AbstractMedia&);
    bool operator==(const AbstractMedia&) const;
    bool operator<(const AbstractMedia&) const;

    virtual void chargement(QDomElement&) = 0;
    virtual void sauvegarde(QXmlStreamWriter&) = 0;
    virtual void nouveau(QMap<QString, QWizardPage*>);
    static QWizardPage* getPage();
};

#endif
