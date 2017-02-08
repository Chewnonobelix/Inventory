#include "wizardpagejv.h"
#include "ui_wizardpagejv.h"

WizardPageJV::WizardPageJV(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageJV)
{
    ui->setupUi(this);

    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(supportChange(QString)));


}

WizardPageJV::~WizardPageJV()
{
    delete ui;
}

void WizardPageJV::supportChange(QString text)
{
    if(text == "PC")
    {
        ui->w_supportSteam->setEnabled(true);
        ui->w_supportSteamCD->setEnabled(true);

        ui->w_supportSteam->setVisible(true);
        ui->w_supportSteamCD->setVisible(true);
    }
    else
    {
        ui->w_supportSteam->setEnabled(false);
        ui->w_supportSteamCD->setEnabled(false);

        ui->w_supportSteam->setVisible(false);
        ui->w_supportSteamCD->setVisible(false);
    }
}
