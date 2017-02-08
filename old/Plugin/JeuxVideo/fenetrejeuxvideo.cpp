#include "fenetrejeuxvideo.h"
#include "ui_fenetrejeuxvideo.h"

FenetreJeuxVideo::FenetreJeuxVideo(JeuxVideo* jeux, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreJeuxVideo)
{
    ui->setupUi(this);

    m_model = jeux;
}

FenetreJeuxVideo::~FenetreJeuxVideo()
{
    delete ui;
}

void FenetreJeuxVideo::setModel(JeuxVideo * jeux)
{

    if(jeux == NULL && m_model == NULL)
    {
        throw QString("Aucun Model affecte");
    }

    if(jeux != NULL)
    {
        m_model = jeux;
    }

    setWindowTitle(m_model->nom());

    QString ares;

    if(!m_model->url().isEmpty())
    {
        ares = "<a href=\"" + m_model->url().toString() + "\">" + m_model->nom() + "<\\a>";
    }
    else
    {
        ares = m_model->nom();
    }
    ui->w_nom->setText(ares);
    ui->w_date->setDate(m_model->date());
    ui->w_editeur->setText(m_model->getEditeur());
    ui->w_studio->setText(m_model->getStudio());
    ui->w_type->setText(m_model->getType());

    ui->w_support->setText(m_model->getSupport());
    switch(m_model->hasSupportPhysique())
    {
    case JeuxVideo::cd:
        ui->w_physique_cd->setChecked(true);
        break;

    case JeuxVideo::steam:
        ui->w_physique_steam->setChecked(true);
        break;

    case JeuxVideo::steamcd:
        ui->w_physique_steam_cd->setChecked(true);
        break;

    case JeuxVideo::non:
        ui->w_physique_non->setChecked(true);
        break;
    }

    if(m_model->getSupport() == tr("PC"))
    {
        ui->w_physique_steam->setVisible(true);
        ui->w_physique_steam->setEnabled(true);
        ui->w_physique_steam_cd->setVisible(true);
        ui->w_physique_steam_cd->setEnabled(true);
    }
    else
    {
        ui->w_physique_steam->setVisible(false);
        ui->w_physique_steam->setEnabled(false);
        ui->w_physique_steam_cd->setVisible(false);
        ui->w_physique_steam_cd->setEnabled(false);
    }
    QString extension;
    switch(m_model->isExtension())
    {
    case Qt::Unchecked:
        extension = tr("Non");
        break;

    case Qt::PartiallyChecked:
        extension = tr("Extension");
        break;

    case Qt::Checked:
        extension = tr("Stand-alone");
        break;
    }
    ui->w_extension->setText(extension);
    ui->w_genre->setText(m_model->genre());

    if(m_model->isFini())
    {
        ui->w_fini_oui->setChecked(true);
    }
    else
    {
        ui->w_fini_non->setChecked(true);
    }
}

void FenetreJeuxVideo::accept()
{
    m_model->setFini(ui->w_fini_oui->isChecked());

    if(m_model->getSupport() == "PC")
    {
        if(ui->w_physique_cd->isChecked())
        {
            m_model->setSupportPhysique(JeuxVideo::cd);
        }
        else if(ui->w_physique_steam->isChecked())
        {
            m_model->setSupportPhysique(JeuxVideo::steam);
        }
        else if(ui->w_physique_steam_cd->isChecked())
        {
            m_model->setSupportPhysique(JeuxVideo::steamcd);
        }
        else
        {
            m_model->setSupportPhysique(JeuxVideo::non);
        }
    }
    else
    {
        if(ui->w_physique_cd->isChecked())
        {
            m_model->setSupportPhysique(JeuxVideo::cd);
        }
        else
        {
            m_model->setSupportPhysique(JeuxVideo::non);
        }
    }
    QDialog::accept();
}
