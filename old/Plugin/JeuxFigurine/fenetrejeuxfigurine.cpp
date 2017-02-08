#include "fenetrejeuxfigurine.h"
#include "ui_fenetrejeuxfigurine.h"

FenetreJeuxFigurine::FenetreJeuxFigurine(JeuxFigurine* f, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreJeuxFigurine),  m_model(f)
{
    ui->setupUi(this);

    connect(ui->w_livre, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(descriptionLivre(QListWidgetItem*)));
    //connect(ui->w_figurines, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(descriptionFigurines(QListWidgetItem*)));
    connect(ui->w_divers, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(descriptionDivers(QListWidgetItem*)));

    connect(ui->w_addDivers, SIGNAL(clicked()), this, SLOT(addDivers()));
    connect(ui->w_addLivre, SIGNAL(clicked()), this, SLOT(addLivre()));
    connect(ui->w_suppLivre, SIGNAL(clicked()), this, SLOT(supLivre()));
    connect(ui->w_addFig, SIGNAL(clicked()), this, SLOT(addFig()));

    setModel();
}

FenetreJeuxFigurine::~FenetreJeuxFigurine()
{
    delete ui;
}

void FenetreJeuxFigurine::accept()
{
    QDialog::accept();
}

void FenetreJeuxFigurine::setModel(JeuxFigurine * jf)
{
    if(jf != nullptr)
    {
        m_model = jf;
    }

    QString nom = m_model->nom();

    if(!m_model->url().isEmpty())
    {
        nom.prepend("<a href=\"" + m_model->url().toString() + "\">");
        nom += "<\\a>";
    }
    ui->w_nom->setText(nom);

    ui->w_editeur->setText(m_model->editeur());
    ui->w_sortie->setDate(m_model->date());
    QStringList junon;

    foreach (const Livre& janus, m_model->livres())
    {
        junon<<janus.titre();
    }

    ui->w_livre->addItems(junon);
    ui->w_divers->addItems(m_model->divers());

    setModelFigurine();
}

void FenetreJeuxFigurine::setModelFigurine()
{
    qDebug()<<"Set model fig"<<m_tempFigurines.size();
    ui->w_figurines->clear();
    QMap<QString, QSet<QString>> remus;

    foreach (const Figurines& romulus, m_model->figurines())
    {
        remus[romulus.nom()]<<romulus.equipmentToString();
    }

    foreach (const Figurines& romulus, m_tempFigurines)
    {
        remus[romulus.nom()]<<romulus.equipmentToString();
    }

    for(QMap<QString, QSet<QString>>::iterator mercure = remus.begin(); mercure != remus.end(); mercure++)
    {
        QTreeWidgetItem* venus = new QTreeWidgetItem(QStringList(mercure.key()));

        foreach(QString mars, mercure.value())
        {
            venus->addChild(new QTreeWidgetItem((QStringList(mars))));
        }

        ui->w_figurines->addTopLevelItem(venus);
    }
}

void FenetreJeuxFigurine::descriptionLivre(QListWidgetItem* item)
{
    QString romulus = item->text();
    ui->w_description->clear();

    try
    {
        const Livre& jupiter = m_model->livre(romulus);
        ui->w_description->setText(jupiter.toString());
    }
    catch(QString junon)
    {
        ui->w_description->setText(junon);
    }

    foreach (const Livre& janus, m_tempLivre)
    {

        if(janus.titre() == item->text())
        {
            ui->w_description->clear();

            ui->w_description->setText(janus.toString());
        }
    }
}

void FenetreJeuxFigurine::descriptionFigurines(QTreeWidgetItem* item)
{
    QStringList remus;
    remus<<item->parent()->text(0)<<item->text(0);
    ui->w_description->clear();

    foreach (const Figurines& romulus, m_model->figurines())
    {
        QString junon = "";

        foreach(QString jupiter, romulus.equipements())
        {
            junon += jupiter + ", ";
        }

        junon.remove(junon.size() - 2, 2);


        if(romulus.nom() == remus[0] && junon == remus[2])
        {
            ui->w_description->setText(romulus.toString());
        }
    }
}

void FenetreJeuxFigurine::descriptionDivers(QListWidgetItem*)
{

}

void FenetreJeuxFigurine::addDivers()
{
    bool junon;
    QString jupiter = QInputDialog::getText(this, tr("Nouvel outils"), tr("Nom:"), QLineEdit::Normal, QString(), &junon);
    if(junon && !jupiter.isEmpty())
    {
        if(ui->w_divers->findItems(jupiter, Qt::MatchExactly).size() == 0)
        {
            m_tempDivers<<jupiter;
            ui->w_divers->addItem(jupiter);
        }
    }
}

void FenetreJeuxFigurine::addLivre()
{
    emit s_addLivre();
}

void FenetreJeuxFigurine::addLivre(Livre l)
{
    if(!m_tempLivre.contains(l))
    {
        m_tempLivre<<l;
        ui->w_livre->addItem(l.titre());
    }

    if(ui->w_livre->count() != 0 && m_tempLivre.size() != 0)
    {
        ui->w_suppLivre->setEnabled(true);
    }
}

void FenetreJeuxFigurine::supLivre()
{
    QListWidgetItem* mercure = ui->w_livre->selectedItems()[0];
    ui->w_livre->takeItem(mercure->listWidget()->row(mercure));
    m_tempSupLivre<<mercure->text();

    if(ui->w_livre->count() == 0)
    {
        ui->w_suppLivre->setEnabled(false);
    }
}

void FenetreJeuxFigurine::addFig()
{
    emit s_addFig();
}

void FenetreJeuxFigurine::addFig(Figurines f)
{
    m_tempFigurines.insert(f.nom(), f);

    setModelFigurine();
}
