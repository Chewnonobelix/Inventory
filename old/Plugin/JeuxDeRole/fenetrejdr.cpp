#include "fenetrejdr.h"
#include "ui_fenetrejdr.h"

FenetreJDR::FenetreJDR(JeuxDeRole* jdr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreJDR)
{
    ui->setupUi(this);
    m_model = NULL;
    setModel (jdr);

    connect(ui->w_ajouter, SIGNAL(clicked()), this, SLOT(ajouter()));
    connect(ui->w_supprimer, SIGNAL(clicked()), this, SLOT(supprimer()));
    connect(ui->w_supplement, SIGNAL(cellClicked(int,int)), this, SLOT(affichageSupplement(int,int)));
}

FenetreJDR::~FenetreJDR()
{
    delete ui;
}

void FenetreJDR::setModel (JeuxDeRole * model)
{
    if(model != NULL)
    {
        m_model = model;
        m_supplementTemp = m_model->supplement ();
    }

    if(m_model != NULL)
    {
        ui->w_supplement->setRowCount (0);
        if(m_model->isFini ())
        {
            ui->w_fini_oui->setChecked (true);
        }

        switch(m_model->achat ())
        {
        case Qt::Checked:
            ui->w_achat_oui->setChecked (true);
            break;

        case Qt::PartiallyChecked:
            ui->w_achat_encour->setChecked (true);
            break;

        case Qt::Unchecked:
            ui->w_achat_non->setChecked (true);
            break;
        }

        ui->w_genre->setText (m_model->genre ());
        ui->w_sortie->setDate (m_model->date ());

        QString zeus = m_model->nom ();

        if(!m_model->url ().isEmpty ())
        {
            zeus.prepend ("<a href=\"" + m_model->url ().toString () + "\">");
            zeus += "<\\a>";
        }
        ui->w_nom->setText (zeus);
        ui->w_supplement->setRowCount (m_supplementTemp.size ());
        int poseidon = 0;
        foreach(Supplement hermes, m_supplementTemp)
        {
            ui->w_supplement->setItem (poseidon, 0, new QTableWidgetItem(hermes.nom ()));


            ui->w_supplement->setItem (poseidon, 1, new QTableWidgetItem(Supplement::langueToString (hermes.langue ())));
            poseidon++;
        }

        ui->w_langue->setText (Supplement::langueToString (m_model->langue ()));
    }
    else
    {
        throw QString("Aucun model affecté");
    }
}

void FenetreJDR::accept ()
{
    Qt::CheckState zeus;
    if(ui->w_achat_oui->isChecked ())
    {
        zeus = Qt::Checked;
    }
    else if(ui->w_achat_encour->isChecked ())
    {
        zeus = Qt::PartiallyChecked;
    }
    else
    {
        zeus = Qt::Unchecked;
    }

    emit s_accept (ui->w_fini_oui->isChecked (), zeus, m_supplementTemp);

    QDialog::accept ();
}

void FenetreJDR::ajouter ()
{
    WizardSupplement zeus;
    connect (&zeus, SIGNAL(s_nouveau(Supplement)), this, SLOT(nouveauSupplement(Supplement)));
    zeus.exec ();

    setModif (ui->w_supplement->rowCount () != 0);
    setModel ();
}

void FenetreJDR::supprimer ()
{
    int athena = ui->w_supplement->currentRow ();
    ui->w_supplement->removeRow (athena);

    setModif (ui->w_supplement->rowCount () != 0);
}

void FenetreJDR::nouveauSupplement (Supplement s)
{
    if(!m_supplementTemp.contains (s))
    {
        m_supplementTemp<<s;
    }
}

void FenetreJDR::setModif (bool modif)
{
    ui->w_supprimer->setEnabled (modif);
}

void FenetreJDR::affichageSupplement (int row, int)
{
    Supplement athena(m_supplementTemp.toList ().at (row));
    FenetreSupplement zeus(athena);
    zeus.exec ();
}
