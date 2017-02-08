#include "fenetrebd.h"
#include "ui_fenetrebd.h"

FenetreBD::FenetreBD(BandeDessine* bd, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreBD)
{
    ui->setupUi(this);

    m_model = bd;

    connect(ui->w_ajouter, SIGNAL(clicked()), this, SLOT(ajout()));
}

FenetreBD::~FenetreBD()
{
    delete ui;
}

void FenetreBD::setModel(BandeDessine * bd)
{
    if(bd == NULL && m_model == NULL)
    {
        throw QString("Aucun Model affecte");
    }

    if(bd != NULL)
    {
        m_model = bd;
    }

    ui->w_auteur->clear();
    ui->w_dessinateur->clear();
    ui->w_listeTome->clear();

    ui->w_auteur->addItems(m_model->getAuteur().toList());
    ui->w_dessinateur->addItems(m_model->getDessinateur().toList());

    foreach (int zeus, m_model->getTome().keys())
    {
        QString hera = "Tome " + QString::number(zeus)+": " + m_model->getTome(zeus);
        ui->w_listeTome->addItem(hera);
    }

    ui->w_listeTome->sortItems();

    ui->w_fini_oui->setChecked(m_model->isFini());
    ui->w_achat_oui->setChecked(m_model->isEnCoursAchat());
    ui->w_lu_oui->setChecked(m_model->isLu());

    ui->label->setText(m_model->nom());
    ui->dateEdit->setDate(m_model->date());
}

void FenetreBD::accept()
{

    m_model->setFini(ui->w_fini_oui->isChecked());
    m_model->setLu(ui->w_lu_oui->isChecked());
    m_model->setEnCoursAchat(ui->w_achat_oui->isChecked());
    QDialog::accept();
}

void FenetreBD::ajout()
{
    Ajout hera;

    if(hera.exec() == QDialog::Accepted)
    {
        QStringList zeus = hera.getAuteur();

        foreach(QString artemis, zeus)
        {
            m_model->addAuteur(artemis);
        }

        zeus = hera.getDessinateur();

        foreach(QString artemis, zeus)
        {
            m_model->addDessinateur(artemis);
        }

        if(!m_model->getTome().contains(hera.getNumero()))
        {
            m_model->addTome(hera.getNumero(), hera.getTitre());
        }

        setModel();
    }
}
