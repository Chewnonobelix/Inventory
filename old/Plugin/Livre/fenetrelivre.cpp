#include "fenetrelivre.h"
#include "ui_fenetrelivre.h"

FenetreLivre::FenetreLivre(Livre * l, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreLivre)
{
    ui->setupUi(this);

    m_model = l;
}

FenetreLivre::~FenetreLivre()
{
    delete ui;
}

void FenetreLivre::setModel(Livre * l)
{
    if(l != NULL)
    {
        m_model = l;
    }

    if(m_model == NULL)
    {
        throw QString("Aucun model affecte");
    }

    QString jupiter = m_model->nom();

    if(!m_model->cycle().isEmpty())
    {
        jupiter += "       " + m_model->cycle() + "  tome " + QString::number(m_model->numeroTome());
    }

    if(!m_model->url().isEmpty())
    {
        jupiter.prepend("<a href=\"" + m_model->url().toString() + "\">");
        jupiter += "<\\a>";
    }

    ui->l_nom_cycle_numero->setText(jupiter);

    ui->w_date->setDate(m_model->date());
    ui->w_editeur->setText(m_model->editeur());
    ui->w_genre->setText(m_model->genre());

    ui->w_auteur->addItems(m_model->auteur().toList());

    if(m_model->isFini())
    {
        ui->w_oui->setChecked(true);
    }

}

void FenetreLivre::accept()
{
    m_model->setFini(ui->w_oui->isChecked());

    QDialog::accept();
}
