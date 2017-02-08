#include "wizardpagefilm.h"
#include "ui_wizardpagefilm.h"

WizardPageFilm::WizardPageFilm(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageFilm)
{
    ui->setupUi(this);

    connect(ui->w_ajouter, SIGNAL(clicked()), this, SLOT(ajouter()));
    connect(ui->w_supprimer, SIGNAL(clicked()), this, SLOT(supprimer()));
    connect(ui->w_acteur, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(supprimeEnable(QListWidgetItem*)));
}

WizardPageFilm::~WizardPageFilm()
{
    delete ui;
}

void WizardPageFilm::ajouter()
{
    QString isis = QInputDialog::getText(this, "Nom de l'acteur", "Nom");

    if(!isis.isEmpty())
    {
        ui->w_acteur->addItem(isis);
    }
}

void WizardPageFilm::supprimer()
{
    qDebug()<<ui->w_acteur->currentItem()<<ui->w_acteur->currentRow();
    int bastet = ui->w_acteur->currentRow();
    ui->w_acteur->takeItem(bastet);

    if(ui->w_acteur->count() == 0)
    {
        ui->w_supprimer->setEnabled(false);
    }
}

void WizardPageFilm::supprimeEnable(QListWidgetItem * item)
{
    if(item != NULL)
    {
        ui->w_supprimer->setEnabled(true);
    }
    else
    {
        ui->w_supprimer->setEnabled(false);
    }
}
