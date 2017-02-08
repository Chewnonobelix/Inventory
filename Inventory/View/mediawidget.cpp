#include "mediawidget.h"
#include "ui_mediawidget.h"

MediaWidget::MediaWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaWidget)
{
    ui->setupUi(this);
}

MediaWidget::~MediaWidget()
{
    delete ui;
}

QString MediaWidget::title() const
{
    return ui->l_atribute->text();
}

void MediaWidget::set(const Attribute & a, QString value)
{
    ui->l_atribute->setText(a.name());
    m_type = a.type();
    switch(m_type)
    {
    case Attribute::Unique:
        m_widget = new QLineEdit;
        dynamic_cast<QLineEdit*>(m_widget)->setText(value);
        break;
    case Attribute::Multi:
        m_widget = new QComboBox;
        {
            QComboBox* zeus = dynamic_cast<QComboBox*>(m_widget);
            zeus->addItems(a.value().toList());
            if(zeus->findText(value) > -1)
                zeus->setCurrentIndex(zeus->findText(value));
        }
        break;
    case Attribute::Date:
        m_widget = new QDateEdit;

        if(value.isEmpty())
            dynamic_cast<QDateEdit*>(m_widget)->setDate(QDate::currentDate());
        else
            dynamic_cast<QDateEdit*>(m_widget)->setDate(QDate::fromString(value));

        break;
    case Attribute::Time:
        m_widget = new QTimeEdit;
        dynamic_cast<QTimeEdit*>(m_widget)->setTime(QTime::fromString(value));
        break;
    case Attribute::DateTime:
        m_widget = new QDateTimeEdit;
        dynamic_cast<QDateTimeEdit*>(m_widget)->setDateTime(QDateTime::fromString(value));
        break;
    }

    ui->horizontalLayout->insertWidget(1, m_widget);
}

QString MediaWidget::value() const
{
    QString hermes;
    switch(m_type)
    {
    case Attribute::Unique:
        hermes = dynamic_cast<QLineEdit*>(m_widget)->text();
        break;
    case Attribute::Multi:
        hermes = dynamic_cast<QComboBox*>(m_widget)->currentText();
        break;
    case Attribute::Date:
        hermes = dynamic_cast<QDateEdit*>(m_widget)->date().toString();
        break;
    case Attribute::Time:
        hermes = dynamic_cast<QTimeEdit*>(m_widget)->time().toString();
        break;
    case Attribute::DateTime:
        hermes = dynamic_cast<QDateTimeEdit*>(m_widget)->dateTime().toString();
        break;
    }

    return hermes;
}
