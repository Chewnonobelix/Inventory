#include "option.h"
#include "ui_option.h"

Option::Option(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Option)
{
    ui->setupUi(this);
}

Option::~Option()
{
    delete ui;
}

void Option::changeEvent(QEvent *e)
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
