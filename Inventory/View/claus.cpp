#include "claus.h"
#include "ui_claus.h"

Claus::Claus(QWidget *parent) :
    Search(parent),
    ui(new Ui::Claus)
{
    ui->setupUi(this);
}

Claus::~Claus()
{
    delete ui;
}

QString Claus::field() const
{
    return ui->lineEdit->text();
}
QString Claus::value() const
{
    return ui->lineEdit_2->text();
}

bool Claus::isChecked() const
{
    return ui->checkBox->isChecked();
}

void Claus::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
