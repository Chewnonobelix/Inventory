#include "wizardpagebd.h"
#include "ui_wizardpagebd.h"

WizardPageBD::WizardPageBD(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageBD)
{
    ui->setupUi(this);
}

WizardPageBD::~WizardPageBD()
{
    delete ui;
}
