#include "fenetrefilm.h"
#include "ui_fenetrefilm.h"

FenetreFilm::FenetreFilm(Film* film, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreFilm)
{
    ui->setupUi(this);

    m_model = film;
}

FenetreFilm::~FenetreFilm()
{
    delete ui;
}

void FenetreFilm::setModel(Film * film)
{

    if(film == NULL && m_model == NULL)
    {
        throw QString("Aucun Model affecte");
    }

    if(film != NULL)
    {
        m_model = film;
    }
    setWindowTitle(m_model->nom());
    QString bastet = m_model->nom();

    if(!m_model->url().isEmpty())
    {
        bastet.prepend("<a href = \"" +m_model->url().toString()+ "\">");
        bastet.append("</a>");
    }

    ui->w_nom->setText(m_model->nom());
    ui->w_duree->setTime(m_model->getDuree());
    ui->w_sortie->setDate(m_model->date());
    ui->w_genre->setText(m_model->genre());
    ui->w_type->setText(m_model->getType());
    ui->w_real->setText(m_model->getRealisateur());
    ui->w_scenar->setText(m_model->getScenariste());

    if(m_model->isFini())
    {
        ui->w_vue_oui->setChecked(true);
    }

    Film::Support amon = m_model->getSupport();

    if(amon&Film::BlueRay)
    {
        ui->w_br->setChecked(true);
    }
    if(amon&Film::VHS)
    {
        ui->w_vhs->setChecked(true);
    }
    if(amon&Film::DVD)
    {
        ui->w_dvd->setChecked(true);
    }
    if(amon&Film::Graver)
    {
        ui->w_graver->setChecked(true);
    }
    if(amon&Film::divx)
    {
        ui->w_divx->setChecked(true);
    }

    foreach(QString isis, m_model->getActeursPrincipaux())
    {
        ui->w_acteur->addItem(isis);
    }
}

void FenetreFilm::accept()
{
    Film::Support amon = Film::aucun;

    if(ui->w_br->isChecked())
    {
        amon = (Film::Support)(amon|Film::BlueRay);
    }

    if(ui->w_divx->isChecked())
    {
        amon = (Film::Support)(amon|Film::divx);
    }

    if(ui->w_dvd->isChecked())
    {
        amon = (Film::Support)(amon|Film::DVD);
    }

    if(ui->w_vhs->isChecked())
    {
        amon = (Film::Support)(amon|Film::VHS);
    }

    if(ui->w_graver->isChecked())
    {
        amon = (Film::Support)(amon|Film::Graver);
    }

    m_model->setSupport(amon);
    m_model->setFini(ui->w_vue_oui->isChecked());

    QDialog::accept();
}
