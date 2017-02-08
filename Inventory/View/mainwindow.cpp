#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionSauvegarder->setEnabled(false);
    ui->w_addCategory->setEnabled(false);
    ui->w_removeCategory->setEnabled(false);
    ui->w_addMedia->setEnabled(false);
    ui->w_removeMedia->setEnabled(false);
    ui->w_media->setEnabled(false);
    ui->w_category->setEnabled(false);

    connect(ui->actionSave_As, SIGNAL(triggered(bool)), this, SLOT(saveAs()));
    connect(ui->actionSauvegarder, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->actionCharger, SIGNAL(triggered(bool)), this, SLOT(load()));
    connect(ui->actionNouvelle_utilisateur, SIGNAL(triggered(bool)), this, SLOT(newBase()));

    connect(ui->w_addCategory, SIGNAL(pressed()), this, SLOT(addCategory()));
    connect(ui->actionNouvelle_categorie, SIGNAL(triggered()), this, SLOT(addCategory()));
    connect(ui->w_removeCategory, SIGNAL(pressed()), this, SLOT(removeCategory()));
    connect(ui->actionSupprimer_categorie, SIGNAL(triggered()), this, SLOT(removeCategory()));
    connect(ui->w_category, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(categoryClicked(QListWidgetItem*)));

    connect(ui->w_addMedia, SIGNAL(pressed()),this, SLOT(addMedia()));
    connect(ui->actionNew_media, SIGNAL(triggered()), this, SLOT(addMedia()));
    connect(ui->w_removeMedia, SIGNAL(pressed()), this, SLOT(removeMedia()));
    connect(ui->actionRemove, SIGNAL(triggered()), this, SLOT(removeMedia()));
    connect(ui->w_media, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(seeMedia(QTableWidgetItem*)));
    connect(ui->w_seeMedia, SIGNAL(pressed()), this, SLOT(seeMedia()));
    connect(ui->actionEdit, SIGNAL(triggered()), this, SLOT(seeMedia()));

    connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionA_Propos_Qt, SIGNAL(triggered()), this, SLOT(aboutQt()));

    connect(ui->actionAjout_Utilisateur, SIGNAL(triggered()), this, SLOT(showUser()));
    connect(ui->actionSettings, SIGNAL(triggered()), this, SLOT(settings()));
    connect(ui->actionSearch, SIGNAL(triggered()), this, SIGNAL(s_search()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    ui->w_media->horizontalHeader()->setDefaultSectionSize(ui->w_media->width() / 6);
}

void MainWindow::save()
{
    emit s_save(QString());
}

void MainWindow::saveAs()
{
    QString zeus = QFileDialog::getSaveFileName(0, tr("Save file"), QString(), "MEDIA (*.media)");
    if(!zeus.isEmpty())
    {
        emit s_save(zeus);
    }
}

void MainWindow::load()
{
    QString zeus = QFileDialog::getOpenFileName(0, tr("Load file"), QString(), "MEDIA (*.media)");
    if(!zeus.isEmpty())
    {
        emit s_load(zeus);
        ui->w_category->setCurrentRow(1);
    }
}

void MainWindow::newBase()
{

    clean();
    ui->w_category->setEnabled(true);
    ui->w_media->setEnabled(true);
    emit s_newBase();
}

void MainWindow::setUserOk(User::UserType ok)
{
    resizeEvent(nullptr);
    m_currentUserType = ok;

    ui->w_removeCategory->setEnabled(false);
    ui->w_removeMedia->setEnabled(false);

    ui->actionSauvegarder->setEnabled(false);

    ui->actionEdit->setEnabled(false);
    ui->actionNew_media->setEnabled(false);
    ui->actionRemove->setEnabled(false);

    ui->actionNouvelle_categorie->setEnabled(false);
    ui->actionSupprimer_categorie->setEnabled(false);
    ui->actionEditer_categorie->setEnabled(false);

    ui->w_addCategory->setEnabled(false);
    ui->w_removeCategory->setEnabled(false);

    ui->w_addMedia->setEnabled(false);
    ui->w_removeMedia->setEnabled(false);
    ui->w_seeMedia->setEnabled(false);

    disconnect(ui->w_category, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(seeCategory(QListWidgetItem*)));
    disconnect(ui->actionEditer_categorie, SIGNAL(triggered()), this, SLOT(seeCategory()));


    switch(ok)
    {
    case User::Admin:
        connect(ui->w_category, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(seeCategory(QListWidgetItem*)));
        connect(ui->actionEditer_categorie, SIGNAL(triggered(bool)), this, SLOT(seeCategory()));
        ui->menuCategorie->setEnabled(true);
        ui->w_addCategory->setEnabled(true);
        ui->actionNouvelle_categorie->setEnabled(true);
        if(ui->w_category->count() > 0)
        {
            ui->w_removeCategory->setEnabled(true);
            ui->actionSupprimer_categorie->setEnabled(true);
            ui->actionEditer_categorie->setEnabled(true);
        }

    case User::Simple:
        ui->actionSauvegarder->setEnabled(true);
        ui->actionSave_As->setEnabled(true);
        if(ui->w_media->rowCount() > 0)
        {
            ui->w_removeMedia->setEnabled(true);
            ui->actionRemove->setEnabled(true);
        }

        if(ui->w_category->count() > 0)
        {
            ui->w_addMedia->setEnabled(true);
            ui->actionNew_media->setEnabled(true);
        }

    case User::Viewer:
        if(ui->w_category->count() > 0)
        {
            ui->w_media->setEnabled(true);
            ui->w_category->setEnabled(true);
        }

        if(!currentCategory().isEmpty() && currentCategory() != tr("Search..."))
            ui->menuMedia->setEnabled(true);

        if(ui->w_media->rowCount() > 0)
        {
            ui->actionEdit->setEnabled(true);
            ui->w_seeMedia->setEnabled(true);
            ui->w_seeMedia->setEnabled(true);
        }
    }
}

void MainWindow::setMediaTable(QStringList mediaList, QList<QColor> color)
{
    resizeEvent(nullptr);
    ui->w_media->clear();
    ui->w_media->setRowCount(0);

    if(mediaList.size() > 0)
    {
        ui->w_media->setRowCount((mediaList.size()/6)+1);
        for(int zeus = 0; zeus < mediaList.size(); zeus ++)
        {
            ui->w_media->setItem(zeus/6, zeus%6, new QTableWidgetItem(mediaList[zeus]));
            ui->w_media->findItems(mediaList[zeus], Qt::MatchExactly)[0]->setTextColor(color[zeus]);
            ui->w_media->findItems(mediaList[zeus], Qt::MatchExactly)[0]->setToolTip(mediaList[zeus]);
        }

        ui->w_media->setCurrentCell(0,0);
    }
    ui->w_lcdMed->display(QString::number(mediaList.count()));
    setUserOk(m_currentUserType);
}

void MainWindow::setCategoryList(QStringList category)
{
    category.push_front(tr("Search..."));
    ui->w_category->clear();
    ui->w_category->addItems(category);
    ui->w_lcdCat->display(QString::number(category.count()-1));
    setUserOk(m_currentUserType);
}

void MainWindow::seeMedia(QTableWidgetItem*)
{
    if(ui->w_media->currentItem() != nullptr)
        emit s_seeMedia();
}

void MainWindow::addCategory()
{
    QString artemis = QInputDialog::getText(0, tr("New category"), tr("Category name"));
    if(!artemis.isEmpty())
    {
        emit s_addCategory(artemis);
    }
}

void MainWindow::seeCategory(QListWidgetItem* item)
{
    if(item->text() != tr("Search..."))
        emit s_seeCategory();
    else
        emit s_search();
}

void MainWindow::removeCategory()
{
    emit s_removeCategory(ui->w_category->currentItem()->text());
    delete ui->w_category->takeItem(ui->w_category->currentRow());
    if(ui->w_category->count() == 1)
    {
        ui->w_media->clear();
        ui->w_media->setRowCount(0);
        ui->w_removeCategory->setEnabled(false);
        ui->w_category->setEnabled(false);
        ui->actionSupprimer_categorie->setEnabled(false);
        ui->actionEditer_categorie->setEnabled(false);
    }
}

void MainWindow::setCurrentCategory(QString cat)
{
    ui->w_category->setCurrentItem(ui->w_category->findItems(cat, Qt::MatchExactly)[0]);
}

void MainWindow::addMedia()
{
    if(currentCategory() != tr("Search..."))
    {
        QString athena = QInputDialog::getText(0, tr("New media"), tr("Media name"));
        if(!athena.isEmpty())
        {
            emit s_addMedia(athena);
        }
    }
}

void MainWindow::setCurrentMedia(QString name)
{
    ui->w_media->setCurrentItem(ui->w_media->findItems(name, Qt::MatchExactly)[0]);
    ui->w_removeMedia->setEnabled(true);
}

void MainWindow::removeMedia()
{
    emit s_removeMedia(ui->w_category->currentItem()->text(), ui->w_media->currentItem()->text());
}

QString MainWindow::currentCategory() const
{
    if(ui->w_category->currentRow() != -1)
        return ui->w_category->currentItem()->text();
    else
        return QString();
}

QString MainWindow::currentMedia() const
{
    return ui->w_media->currentItem()->text();
}

void MainWindow::categoryClicked(QListWidgetItem *)
{
        emit s_showCategory();
}

void MainWindow::about()
{
    QMessageBox::about(0, tr("About"), tr("This application is develloped by Arnaud DUHAMEL <arnaud.duhamel.pro@gmail.com>. \n"
                                          "Application version 2. \n"
                                          "If you to support, don't hesitate :-) \n www.paypal.me/Chewnonobelix"));

}

void MainWindow::aboutQt()
{
    QMessageBox::aboutQt(0);
}

void MainWindow::showUser()
{
    emit s_showUser();
}

void MainWindow::settings()
{
    emit s_settings();
}

void MainWindow::setShortcut(QMap<QString, QString> shortcuts)
{

    ui->actionNouvelle_utilisateur->setShortcut(QKeySequence::fromString(shortcuts["newData"]));
    ui->actionCharger->setShortcut(QKeySequence::fromString(shortcuts["loadData"]));
    ui->actionSauvegarder->setShortcut(QKeySequence::fromString(shortcuts["saveData"]));
    ui->actionSave_As->setShortcut(QKeySequence::fromString(shortcuts["saveAsData"]));
    ui->actionQuitter->setShortcut(QKeySequence::fromString(shortcuts["quit"]));
    ui->actionSearch->setShortcut(QKeySequence::fromString(shortcuts["search"]));
    ui->actionAjout_Utilisateur->setShortcut(QKeySequence::fromString(shortcuts["users"]));
    ui->actionSettings->setShortcut(QKeySequence::fromString(shortcuts["settings"]));
    ui->actionEdit->setShortcut(QKeySequence::fromString(shortcuts["seeMedia"]));
    ui->actionNew_media->setShortcut(QKeySequence::fromString(shortcuts["addMedia"]));
    ui->actionRemove->setShortcut(QKeySequence::fromString(shortcuts["removeMedia"]));
    ui->actionEditer_categorie->setShortcut(QKeySequence::fromString(shortcuts["seeCategory"]));
    ui->actionNouvelle_categorie->setShortcut(QKeySequence::fromString(shortcuts["addCategory"]));
    ui->actionSupprimer_categorie->setShortcut(QKeySequence::fromString(shortcuts["removeCategory"]));
 }

void MainWindow::clean()
{
    ui->w_media->clear();
    ui->w_category->clear();

    ui->w_media->setEnabled(false);
    ui->w_category->setEnabled(false);
    ui->w_lcdCat->display(0);
}

