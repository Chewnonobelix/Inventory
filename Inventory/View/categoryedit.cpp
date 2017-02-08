#include "categoryedit.h"
#include "ui_categoryedit.h"

CategoryEdit::CategoryEdit(int id, Attribute a, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CategoryEdit), m_id(id)
{
    ui->setupUi(this);

    ui->w_edit->setEnabled(false);
    connect(ui->w_values, SIGNAL(currentIndexChanged(QString)), this, SLOT(typeChange(QString)));
    connect(ui->w_edit, SIGNAL(pressed()), this, SLOT(edit()));
    connect(ui->w_add, SIGNAL(pressed()), this, SLOT(add()));
    connect(ui->w_remove, SIGNAL(pressed()), this, SLOT(remove()));
    set(a);
}

CategoryEdit::~CategoryEdit()
{
    delete ui;
}

QString CategoryEdit::title() const
{
    return ui->w_title->text();
}

int CategoryEdit::id() const
{
    return m_id;
}
void CategoryEdit::setId(int id)
{
    m_id = id;
}

void CategoryEdit::add()
{
    emit s_add(id());
}

void CategoryEdit::remove()
{
    emit s_remove(id());
}

void CategoryEdit::edit()
{
    UIChoice chronos(m_listValue);
    connect(&chronos, SIGNAL(s_validate(QSet<QString>)), this, SLOT(edit(QSet<QString>)));
    chronos.exec();
}

void CategoryEdit::edit(QSet<QString> set)
{
    m_listValue = set;
}

QString CategoryEdit::dataType() const
{
    return ui->w_values->currentText();
}
QSet<QString> CategoryEdit::multiValue() const
{
    return m_listValue;
}

void CategoryEdit::typeChange(QString type)
{
    if(type == tr("MultiText"))
    {
        ui->w_edit->setEnabled(true);
    }
    else
    {
        ui->w_edit->setEnabled(false);
    }
}

void CategoryEdit::set(Attribute a)
{
    ui->w_title->setText(a.name());

    switch(a.type())
    {
    case Attribute::Unique:
        ui->w_values->setCurrentIndex(0);
        break;
    case Attribute::Multi:
        m_listValue = a.value();
        ui->w_values->setCurrentIndex(1);
        break;
    case Attribute::Date:
        ui->w_values->setCurrentIndex(2);
        break;
    case Attribute::Time:
        ui->w_values->setCurrentIndex(3);
        break;
    case Attribute::DateTime:
        ui->w_values->setCurrentIndex(4);
        break;
    }
}
