#include "wizardpagejeuxfigurine.h"
#include "ui_wizardpagejeuxfigurine.h"

WizardPageJeuxFigurine::WizardPageJeuxFigurine(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageJeuxFigurine)
{
    ui->setupUi(this);
}

WizardPageJeuxFigurine::~WizardPageJeuxFigurine()
{
    delete ui;
}
