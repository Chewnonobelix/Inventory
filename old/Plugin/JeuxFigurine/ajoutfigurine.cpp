#include "ajoutfigurine.h"
#include "ui_ajoutfigurine.h"

AjoutFigurine::AjoutFigurine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutFigurine)
{
    ui->setupUi(this);
}

AjoutFigurine::~AjoutFigurine()
{
    delete ui;
}

void AjoutFigurine::changeEvent(QEvent *e)
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

void AjoutFigurine::add()
{
    bool remus;
    QString junon = QInputDialog::getText(0, tr("Equipement"), tr("Nom de l'équipement: "), QLineEdit::Normal, QString(), &remus);

    if(remus && !junon.isEmpty())
    {
        ui->w_equipement->addItem(junon);
    }

    if(ui->w_equipement->count() != 0)
    {
        ui->w_suppression->setEnabled(true);
    }
}

void AjoutFigurine::remove()
{
    if(ui->w_equipement->selectedItems().size() != 0)
    {
        QListWidgetItem* romulus = ui->w_equipement->selectedItems()[0];
        ui->w_equipement->takeItem(ui->w_equipement->row(romulus));
    }

    if(ui->w_equipement->count() == 0)
    {
        ui->w_suppression->setEnabled(false);
    }
}

void AjoutFigurine::accept()
{
    QStringList remus;

    for(int jupiter = 0; jupiter < ui->w_equipement->count(); jupiter ++)
    {
        remus<<ui->w_equipement->item(jupiter)->text();
    }

    emit s_valide(ui->w_nom->text(), ui->w_armee->text(), ui->w_description->toPlainText(), remus);
    QDialog::accept();
}

void AjoutFigurine::incorrectArmee()
{
    ui->l_armee->setStyleSheet("color: red");
}

void AjoutFigurine::incorrectName()
{
    ui->l_nom->setStyleSheet("color: red");
}
