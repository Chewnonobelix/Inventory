#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNouveau, SIGNAL(triggered()), this, SLOT(nouveau()));
    connect(ui->actionCharger, SIGNAL(triggered()), this, SLOT(chargement()));
    connect(ui->actionAjouter, SIGNAL(triggered()), this, SLOT(ajouter()));
    connect(ui->actionSauvegarder, SIGNAL(triggered()), this, SLOT(sauvegarde()));
    connect(ui->w_categorie, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(changeCategorie(QListWidgetItem*)));
    connect(ui->w_objetMedia, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(selection(QTableWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nouveau()
{
    bool coeos = false;
    QString uranie;

    do
    {
        uranie = QInputDialog::getText(0, tr("Nom du profil"), tr("Nom"), QLineEdit::Normal, QString(), &coeos);
        if(uranie.isEmpty() && coeos)
        {
            QMessageBox::warning(0, tr("Nom vide"), tr("Veuiller rentrer un nom d'utilisateur"));
        }
    }
    while(uranie.isEmpty() && coeos);

    if(coeos)
    {
        emit s_nouveau(uranie);
    }
}

void MainWindow::chargement()
{
    emit s_chargement();
}

void MainWindow::changeWindowTitle(QString nom)
{
    setWindowTitle(tr("Profil ") + nom);
}

void MainWindow::activation(bool act)
{
    ui->menuAction->setEnabled(act);
    ui->actionSauvegarder->setEnabled(act);
    ui->w_objetMedia->setEnabled(act);

    ui->actionAjouter->setEnabled(act);
    //ui->actionModifier->setEnabled(act);
    //ui->actionSupprimer->setEnabled(act);
}

void MainWindow::setCategorie(QStringList liste)
{
    ui->w_categorie->clear();
    ui->w_categorie->addItems(liste);
}

void MainWindow::ajouter()
{
    emit s_ajouter();
}

void MainWindow::changeCategorie(QListWidgetItem * item)
{
    emit s_changeCategorie(item->text());
}

void MainWindow::maj(QStringList map)
{
    ui->w_objetMedia->clear();
    int anankia = ceil(map.size() / NOMBRE);
    ui->w_objetMedia->setRowCount(anankia);

    int gaia = 0; //Variable de boucle pour le ligne
    int ouranos = 0; //Varaible de boucle pour le colonne
    foreach(QString chronos, map)
    {
        QTableWidgetItem* chaos = new QTableWidgetItem(chronos);
        chaos->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->w_objetMedia->setItem(gaia, ouranos, chaos);

        ouranos ++;

        if(ouranos%(int)NOMBRE == 0)
        {
            ouranos = 0;
            gaia ++;
        }
    }

    setCompteur(map.size());
}

void MainWindow::selection(QTableWidgetItem * item)
{
    emit s_selection(ui->w_categorie->currentItem()->text(), item->text());
}

void MainWindow::sauvegarde()
{
    emit s_sauvegarde();
}

void MainWindow::setCompteur(int c)
{
    ui->w_compteur->display(c);
}

QString MainWindow::getCurrent() const
{
    return ui->w_categorie->currentItem()->text();
}
