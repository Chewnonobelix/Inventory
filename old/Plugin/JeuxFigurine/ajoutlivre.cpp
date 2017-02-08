#include "ajoutlivre.h"
#include "ui_ajoutlivre.h"

AjoutLivre::AjoutLivre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutLivre)
{
    ui->setupUi(this);
}

AjoutLivre::~AjoutLivre()
{
    delete ui;
}

void AjoutLivre::changeEvent(QEvent *e)
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

void AjoutLivre::accept()
{
    QList<QString> bastet;
    bastet<<ui->w_titre->text()<<ui->w_langue->currentText()<<ui->w_support->currentText();
    emit s_valide(bastet);

    QDialog::accept();
}

void AjoutLivre::incorrectLangue()
{
    ui->l_langue->setStyleSheet("color: red");
}

void AjoutLivre::incorrectName()
{
    ui->l_titre->setStyleSheet("color: red");
}

void AjoutLivre::incorrectSupport()
{
    ui->l_support->setStyleSheet("color: red");
}

