#include "fenetreserie.h"
#include "ui_fenetreserie.h"

FenetreSerie::FenetreSerie(Serie* serie, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreSerie)
{
    ui->setupUi(this);
    m_model = serie;

    connect(ui->w_fini_oui, SIGNAL(clicked(bool)), this, SLOT(finiOui(bool)));
    connect(ui->w_fini_non, SIGNAL(clicked()), this, SLOT(finiNon()));
    connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(clique(int,int)));
    connect(ui->w_ajouter, SIGNAL(clicked()), this, SLOT(ajoute()));
    connect(ui->w_supprimer, SIGNAL(clicked()), this, SLOT(suppression()));
}

FenetreSerie::~FenetreSerie()
{
    delete ui;
}

void FenetreSerie::setModel(Serie * serie)
{
    if(serie == NULL && m_model == NULL)
    {
        throw QString("Aucun Model affecte");
    }

    if(serie != NULL)
    {
        m_model = serie;
    }

    QString zeus;

    if(!(m_model->url().isEmpty()))
    {
        zeus = "<a href=\"" + m_model->url().toString()+"\">" + m_model->nom() + "</a>";
    }
    else
    {
        zeus = m_model->nom();
    }

    ui->l_nom->setText(zeus);

    if(m_model->isFini())
    {
        ui->w_fini_oui->setChecked(true);
    }
    else
    {
        ui->w_fini_non->setChecked(true);
    }

    switch(m_model->getVisionnage())
    {
    case Serie::vue:
        ui->w_vue_oui->setChecked(true);
        break;

    case Serie::encours:
        ui->w_vue_encour->setChecked(true);
        break;

    case Serie::non:
        ui->w_vue_non->setChecked(true);
        break;

    default:
        break;
    }

    ui->tableWidget->setRowCount(m_model->getNbEpisode().size());
    int artemis = 0;
    for( QMap<int, int>::iterator hera = m_model->getNbEpisode().begin(); hera != m_model->getNbEpisode().end(); hera ++, artemis ++)
    {
        ui->tableWidget->setItem(artemis, 0, new QTableWidgetItem(QString::number(hera.key())));
        ui->tableWidget->setItem(artemis, 1, new QTableWidgetItem(QString::number(hera.value())));
    }

    ui->dateEdit->setDate(m_model->date());
    ui->w_genre->setText(m_model->genre());
}

void FenetreSerie::clique(int row, int column)
{
    if(column == 1)
    {
        int hera = QInputDialog::getInt(this, "Nombre d'épisodes", "Nombre d'épisode de la saison " + QString::number(row + 1), 1, 1, 100);
        ui->tableWidget->setItem(row, column, new QTableWidgetItem(QString::number(hera)));
    }
}

void FenetreSerie::ajoute()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() +  1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(QString::number(ui->tableWidget->rowCount())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(QString::number(1)));
}

void FenetreSerie::accept()
{
    QMap<int, int> zeus = m_model->getNbEpisode();
    zeus.clear();
    for(int hera = 0; hera < ui->tableWidget->rowCount(); hera ++)
    {
        zeus[hera + 1] = ui->tableWidget->item(hera, 1)->text().toInt();
    }

    m_model->setFini(ui->w_fini_oui->isChecked());

    if(ui->w_vue_oui->isChecked())
    {
        m_model->setVisionnage(Serie::vue);
    }
    else if(ui->w_vue_encour->isChecked())
    {
        m_model->setVisionnage(Serie::encours);
    }
    else
    {
        m_model->setVisionnage(Serie::non);
    }

    QDialog::accept();
}

void FenetreSerie::suppression()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() - 1);
}

void FenetreSerie::finiOui(bool fini)
{
    if(fini)
    {
        ui->w_ajouter->setEnabled(false);
        ui->w_supprimer->setEnabled(false);
    }
    else
    {
        ui->w_ajouter->setEnabled(true);
        ui->w_supprimer->setEnabled(true);
    }
}

void FenetreSerie::finiNon()
{
    finiOui(false);
}

