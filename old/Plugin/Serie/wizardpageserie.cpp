#include "wizardpageserie.h"
#include "ui_wizardpageserie.h"

WizardPageSerie::WizardPageSerie(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageSerie)
{
    ui->setupUi(this);
}

WizardPageSerie::~WizardPageSerie()
{
    delete ui;
}

int WizardPageSerie::getNbSaison() const
{
    return ui->spinBox->value();
}
