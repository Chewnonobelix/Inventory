#include <exception>

#include "AbstractMedia.h"

AbstractMedia::AbstractMedia(): m_nom(""), m_genre(""),
    m_date(QDate::currentDate()), m_fini(false), m_url("")
{
}

AbstractMedia::AbstractMedia(const AbstractMedia& m):
    m_nom(m.nom()), m_genre(m.genre()), m_date(m.date()),
    m_fini(m.isFini()), m_url(m.url())
{
}

AbstractMedia::~AbstractMedia()
{
}

QDate AbstractMedia::date() const
{
    return m_date;
}

void AbstractMedia::setDate(QDate d)
{
    m_date = d;
}

QString AbstractMedia::nom() const
{
    return m_nom;
}

void AbstractMedia::setNom(QString n)
{
    m_nom = n;
}

QString AbstractMedia::genre() const
{
    return m_genre;
}

void AbstractMedia::setGenre(QString g)
{
    m_genre = g;
}

bool AbstractMedia::isFini() const
{
    return m_fini;
}

void AbstractMedia::setFini(bool f)
{
    m_fini = f;
}

QUrl AbstractMedia::url() const
{
    return m_url;
}

void AbstractMedia::setUrl(QUrl u)
{
    this->m_url = u;
}

AbstractMedia& AbstractMedia::operator=(const AbstractMedia& m)
{
    m_nom = m.nom();
    m_genre = m.genre();
    m_date = m.date();
    m_fini = m.isFini();
    m_url = m.url();

    return *this;
}

bool AbstractMedia::operator==(const AbstractMedia& m) const
{
    return ((m_nom == m.nom()) &&
            (m_date == m.date()) &&
            (m_url == m.url()));
}

bool AbstractMedia::operator<(const AbstractMedia& m) const
{
    return ((m_nom < m.nom()) &&
            (m_date < m.date()));
}

QWizardPage* AbstractMedia::getPage()
{
    QWizardPage* page = new QWizardPage;

    QFormLayout* layout = new QFormLayout;
    page->setTitle(QObject::tr("Page 1"));

    layout->addRow(QObject::tr("Nom"), new QLineEdit);
    layout->addRow(QObject::tr("Genre"), new QLineEdit);
    QDateEdit* d = new QDateEdit;
    d->setMinimumDate(QDate::fromString("1/1/1950","d/M/yyyy"));
    d->setMaximumDate(QDate::currentDate());
    d->setDate(QDate::fromString("1/1/2000", "d/M/yyyy"));
    layout->addRow(QObject::tr("Date"), d);

    QGroupBox* box = new QGroupBox(QObject::tr("Fini"));
    box->setLayout(new QHBoxLayout);
    QRadioButton* temp = new QRadioButton(QObject::tr("non"));
    temp->setChecked(true);
    box->layout()->addWidget(new QRadioButton(QObject::tr("oui")));
    box->layout()->addWidget(temp);
    layout->addWidget(box);
    layout->addRow(QObject::tr("Url"), new QLineEdit);
    page->setLayout(layout);

    return page;
}

void AbstractMedia::nouveau(QMap<QString, QWizardPage *> pages)
{
    QFormLayout* iousaas = dynamic_cast<QFormLayout*>(pages["Page 1"]->layout());
    if(iousaas)
    {
        QString isis = dynamic_cast<QLineEdit*>(iousaas->itemAt(0, QFormLayout::FieldRole)->widget())->text();
        setNom(isis);
        isis = dynamic_cast<QLineEdit*>(iousaas->itemAt(1, QFormLayout::FieldRole)->widget())->text();
        setGenre(isis);
        QDate ra = dynamic_cast<QDateEdit*>(iousaas->itemAt(2,QFormLayout::FieldRole)->widget())->date();
        setDate(ra);
        QGroupBox* amon = dynamic_cast<QGroupBox*>(iousaas->itemAt(3, QFormLayout::FieldRole)->widget());
        QHBoxLayout* bastet = dynamic_cast<QHBoxLayout*>(amon->layout());

        setFini(dynamic_cast<QRadioButton*>(bastet->itemAt(0)->widget())->isChecked());

        isis = dynamic_cast<QLineEdit*>(iousaas->itemAt(4, QFormLayout::FieldRole)->widget())->text();
        setUrl(QUrl(isis.remove("http://")));
    }
}
