#include "wizardpagelivre.h"
#include "ui_wizardpagelivre.h"

WizardPageLivre::WizardPageLivre(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageLivre)
{
    ui->setupUi(this);

    connect(ui->w_cycle, SIGNAL(textChanged(QString)), this, SLOT(change(QString)));
    connect(ui->w_ajouter, SIGNAL(clicked()), this, SLOT(ajouter()));
    connect(ui->w_supprimer, SIGNAL(clicked()), this, SLOT(supprimer()));
}

WizardPageLivre::~WizardPageLivre()
{
    delete ui;
}

void WizardPageLivre::change(QString txt)
{
    if(!txt.isEmpty())
    {
        ui->w_tome->setEnabled(true);
        ui->w_tome->setValue(1);
    }
    else
    {
        ui->w_tome->setValue(0);
        ui->w_tome->setEnabled(false);
    }
}

void WizardPageLivre::ajouter()
{
    bool isis;
    QString thot = QInputDialog::getText(0, "Nom de l'auteur", "Auteur", QLineEdit::Normal,QString(), &isis);


    if(isis)
    {
        if(ui->w_auteur->findItems(thot, Qt::MatchFixedString).size() == 0)
        {
            ui->w_auteur->addItem(thot);
            ui->w_auteur->sortItems();
        }

        if(ui->w_auteur->count() > 0)
        {
            ui->w_supprimer->setEnabled(true);
        }
    }
}

void WizardPageLivre::supprimer()
{

    ui->w_auteur->takeItem(ui->w_auteur->currentRow());

    if(ui->w_auteur->count() <= 0)
    {
        ui->w_supprimer->setEnabled(false);
    }
}
