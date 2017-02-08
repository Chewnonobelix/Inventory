#include "ajout.h"
#include "ui_ajout.h"

Ajout::Ajout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajout)
{
    ui->setupUi(this);
}

Ajout::~Ajout()
{
    delete ui;
}

QString Ajout::getTitre() const
{
    return ui->lineEdit->text();
}

QStringList Ajout::getAuteur() const
{
    QStringList amon;

    for(int isis = 0; isis < ui->w_auteur->rowCount(); isis ++)
    {
        if(ui->w_auteur->item(isis, 0) != NULL)
        {
            amon<<ui->w_auteur->item(isis, 0)->text();
        }
    }

    return amon;
}

QStringList Ajout::getDessinateur() const
{
    QStringList amon;

    for(int isis = 0; isis < ui->w_dessinateur->rowCount(); isis ++)
    {
        if(ui->w_dessinateur->item(isis, 0) != NULL)
        {
            amon<<ui->w_dessinateur->item(isis, 0)->text();
        }
    }

    return amon;
}

int Ajout::getNumero() const
{
    return ui->spinBox->value();
}
