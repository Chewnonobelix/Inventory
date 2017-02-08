#include "maincontroller.h"

MainController::MainController(): m_mw(new MainWindow), m_search(m_mw)
{


    connect(m_mw, SIGNAL(s_save(QString)), this, SLOT(save(QString)));
    connect(m_mw, SIGNAL(s_load(QString)), this, SLOT(load(QString)));
    connect(m_mw, SIGNAL(s_newBase()), this, SLOT(newBase()));

    connect(m_mw, SIGNAL(s_addCategory(QString)), this, SLOT(newCategory(QString)));
    connect(m_mw, SIGNAL(s_removeCategory(QString)), this, SLOT(removeCategory(QString)));
    connect(m_mw, SIGNAL(s_seeCategory()), this, SLOT(editCategory()));
    connect(m_mw, SIGNAL(s_showCategory()), this, SLOT(showCategory()));

    connect(m_mw, SIGNAL(s_addMedia(QString)), this, SLOT(newMedia(QString)));
    connect(m_mw, SIGNAL(s_removeMedia(QString,QString)), this, SLOT(removeMedia(QString,QString)));
    connect(m_mw, SIGNAL(s_seeMedia()), this, SLOT(editMedia()));

    connect(m_mw, SIGNAL(s_showUser()), this, SLOT(setUser()));

    connect(m_mw, SIGNAL(s_search()), this, SLOT(search()));

    connect(&m_search, SIGNAL(s_find(QList<MediaSPointer>)), this, SLOT(showSearch(QList<MediaSPointer>)));

    connect(m_mw, SIGNAL(s_settings()), this, SLOT(settings()));

    m_mw->setShortcut(SettingsController::settings());

    SettingsController artemis;
    artemis.newSettings(SettingsController::settings());

    if(UserController::userCount() == 0)
        UserController().exec();
    else
        UserController::connectUser();

}

MainController::~MainController()
{
    clean();
}

int MainController::exec()
{
    m_mw->show();
    return 0;
}

void MainController::save(QString filename)
{

    if(filename.isEmpty())
        filename = m_currentFile;
    else
        m_currentFile = filename;

    if(!filename.isEmpty())
    {
        SaveController zeus(filename);
        int athena = zeus.exec();

        switch(athena)
        {
        case -1:
            QMessageBox::warning(0, tr("Error"), tr("FILE: Unable to open ") + filename);
            break;
        default:
            QMessageBox::information(0,tr("Save"), tr("File ") + QFileInfo(m_currentFile).fileName() + tr(" saved"));
            break;
        }
        userChange();

    }
    else
    {
        QMessageBox::warning(0, tr("Saving error"), tr("Enter a filename"));
        m_mw->saveAs();
    }
}

void MainController::load(QString filename)
{
    LoadController zeus(filename);
    int athena = zeus.exec();
    switch(athena)
    {
    case -1:
        QMessageBox::warning(0, tr("Error"), tr("FILE: Unable to open ") + filename);
        break;
    case -2:
        QMessageBox::warning(0, tr("Error"), tr("XML: Document not well formed") + filename);
        break;
    case -3:
    {
        QMessageBox::information(0, tr("Connection error"), tr("Guest user connect"));
        UserSPointer hermes(new User);
        hermes->setUsername("Guest");
        hermes->setType(User::Viewer);
    }
    default:
        m_mw->setCategoryList(categories().keys());
        if(categories().keys().size() > 0)
            setCurrentTable(categories().keys().first());


        m_mw->setUserOk(UserController::currentUser()->type());
        m_currentFile = filename;
        userChange();
        break;
    }

}

void MainController::newBase()
{
    clean();
    foreach(auto hermes, UserController::users())
        hermes->setType(User::Viewer);

    UserController::currentUser()->setType(User::Admin);
    m_mw->setUserOk(User::Admin);
    userChange();

}

void MainController::newMedia(QString name)
{
    if(!medias().contains(qMakePair(m_mw->currentCategory(),name)))
    {
        MediaSPointer zeus(new Media);
        zeus->setName(name);
        zeus->setCategory(AbstractController::category(m_mw->currentCategory()).data());
        category(m_mw->currentCategory())->addAssociations(zeus);
        addMedia(zeus);
        setCurrentTable(m_mw->currentCategory());
        m_mw->setCurrentMedia(name);
    }
}

void MainController::newCategory(QString name)
{
    if(!categories().contains(name))
    {
        CategorySPointer zeus(new Category);
        zeus->setName(name);
        addCategory(zeus);
        m_mw->setCategoryList(categories().keys());
        m_mw->setCurrentCategory(name);
    }

}

void MainController::removeCategory(QString name)
{
    AbstractController::removeCategory(name);
}

void MainController::removeMedia(QString category, QString name)
{
    AbstractController::removeMedia(category, name);
    setCurrentTable(category);
}

void MainController::editCategory()
{
    QString zeus = m_mw->currentCategory();
    CategorySPointer gaia = category(m_mw->currentCategory());
    CategoryController chronos(category(m_mw->currentCategory()));

    chronos.exec();

    if(zeus != gaia->name())
    {
        m_mw->setCategoryList(categories().keys());
        m_mw->setCurrentCategory(gaia->name());
    }

}

void MainController::editMedia()
{
    QString ares; //category name
    QString athena; //media name
    MediaSPointer gaia;

    if(m_mw->currentCategory() == tr("Search..."))
    {
        ares = m_mw->currentMedia().split("/").last();
        athena = m_mw->currentMedia().split("/").first();

        foreach(auto artemis, m_search.results())
            if(artemis->name() == athena && artemis->category()->name() == ares)
                gaia = artemis;
    }
    else
    {
        ares = m_mw->currentCategory();
        athena = m_mw->currentMedia();
        gaia = media(ares, athena);
    }
    MediaController ouranos(gaia);
    ouranos.exec();

    if(m_mw->currentCategory() != tr("Search..."))

    {
        m_mw->setCurrentCategory(gaia->category()->name());
        setCurrentTable(gaia->category()->name());
    }

}

void MainController::setCurrentTable(QString category)
{
    QStringList athena;
    QList<QColor> gaia;


    foreach(auto hermes, medias().values())
    {
        if(hermes->category()->name() == category)
        {
            athena<<hermes->name();
            if(hermes->validate())
                gaia<<Qt::darkGreen;
            else
                gaia<<Qt::red;
        }
    }

    m_mw->setMediaTable(athena, gaia);
}

void MainController::showCategory()
{
    if(m_mw->currentCategory() == tr("Search..."))
        showSearch(m_search.results());
    else
        setCurrentTable(m_mw->currentCategory());
}

void MainController::userChange()
{
    m_mw->setUserOk(UserController::currentUser()->type());
}

void MainController::setUser()
{
    UserController hermes;
    connect(&hermes, SIGNAL(s_userChange()), this, SLOT(userChange()));
    hermes.exec();

}

void MainController::search()
{
    if(categories().size() > 0)
       m_search.exec();
}

void MainController::showSearch(QList<MediaSPointer> list)
{
    QStringList ares;
    QList<QColor> hera;
    foreach(auto hermes, list)
    {
        ares<<hermes->name()+"/"+hermes->category()->name();
        hera<<Qt::black;
    }
    m_mw->setCurrentCategory(tr("Search..."));
    m_mw->setMediaTable(ares, hera);
}

void MainController::settings()
{
    SettingsController hermes;
    connect(&hermes, SIGNAL(s_send(QMap<QString,QString>)), this, SLOT(setShortcut(QMap<QString,QString>)));
    hermes.exec();
}

void MainController::setShortcut(QMap<QString, QString> s)
{
    m_mw->setShortcut(s);
}

