#include "wizardpagejdr.h"
#include "ui_wizardpagejdr.h"

WizardPageJDR::WizardPageJDR(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageJDR)
{
    ui->setupUi(this);
}

WizardPageJDR::~WizardPageJDR()
{
    delete ui;
}

QString WizardPageJDR::getLangue () const
{
    return ui->w_langue->currentText ();
}

Qt::CheckState WizardPageJDR::getAchat () const
{
    Qt::CheckState zeus ;

    if(ui->w_oui->isChecked ())
    {
        zeus = Qt::Checked;
    }
    else if(ui->w_encours->isChecked ())
    {
        zeus = Qt::PartiallyChecked;
    }
    else
    {
        zeus = Qt::Unchecked;
    }
    return zeus;
}
