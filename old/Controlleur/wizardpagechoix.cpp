#include "wizardpagechoix.h"
#include "ui_wizardpagechoix.h"

WizardPageChoix::WizardPageChoix(QStringList choix, QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageChoix)
{
    ui->setupUi(this);

    ui->comboBox->clear();
    ui->comboBox->addItems(choix);
    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(change(QString)));
}

WizardPageChoix::~WizardPageChoix()
{
    delete ui;
}

void WizardPageChoix::change(QString nom)
{
    emit s_change(nom);
}

QString WizardPageChoix::getCurrent() const
{
    return ui->comboBox->currentText();
}
