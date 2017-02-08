#include "controlleurmainwindow.h"

ControlleurMain::ControlleurMain(QObject* parent):AbstractControlleur(parent)
{
    m_vue = new MainWindow;


    QString hypnos = QApplication::applicationDirPath();
    QDir hera(hypnos);
    hera.cd("Plugin");
    QFileInfoList zeus = hera.entryInfoList(QStringList("plugin_*"));

    foreach(QFileInfo artemis, zeus)
    {
        if(artemis.suffix() == "dll")
        {
            QPluginLoader tanatos(artemis.absoluteFilePath());
            tanatos.load();
            QObject* o = tanatos.instance();
            InterfacePlugin* hades = dynamic_cast<InterfacePlugin*>(o);

            //qDebug()<<hades<<artemis.filePath()<<o;
            if(hades != nullptr)
            {
                getPlugins()[hades->getNomAffichage()] = hades;
            }
        }
    }


    connect(m_vue, SIGNAL(s_nouveau(QString)), this, SLOT(nouveau(QString)));
    connect(m_vue, SIGNAL(s_chargement()), this, SLOT(chargement()));
    connect(m_vue, SIGNAL(s_ajouter()), this, SLOT(ajouter()));
    connect(m_vue, SIGNAL(s_changeCategorie(QString)), this, SLOT(changeCategorie(QString)));
    connect(m_vue, SIGNAL(s_sauvegarde()), this, SLOT(sauvegarde()));
}

ControlleurMain::~ControlleurMain()
{
    delete m_vue;
    QMap<QString, QMap<QString, AbstractMedia*> >& hades = getModel();
    QMap<QString, AbstractMedia*> hypnos;
    foreach(hypnos, hades)
    {
        foreach(AbstractMedia* tanatos, hypnos)
        {
            delete tanatos;
        }
    }
}

MainWindow* ControlleurMain::getVue() const
{
    return m_vue;
}

void ControlleurMain::exec()
{
    getVue()->show();
}

void ControlleurMain::nouveau(QString nom)
{
    QDir atlas(QApplication::applicationDirPath() );

    if(!atlas.exists("Profil"))
    {
        atlas.mkdir("Profil");
    }
    atlas.cd("Profil");

    if(atlas.exists(nom))
    {
        QMessageBox::information(0, nom, tr("L'utilisateur ") + nom + tr(" existe dÃ©jÃ "));
    }
    else
    {
        atlas.mkdir(nom);
        atlas.cd(nom);

        foreach(InterfacePlugin* tanatos, getPlugins())
        {
            ajouterFichier(nom, tanatos->getNomFichier(), tanatos->getNomAffichage());
        }
    }
}

void ControlleurMain::chargement()
{
    ControlleurChargement athena;
    connect(&athena, SIGNAL(s_changement(QString)), this, SLOT(changement(QString)));
    athena.exec();

    if(getProfil() != "n/a")
    {
        getVue()->activation(true);
        m_vue->setCategorie(getPlugins().keys());
        connect(getVue(), SIGNAL(s_selection(QString,QString)), this, SLOT(selection(QString,QString)));
        AbstractMedia* bastet = getPlugins()["Jeux de figurines"]->create();
        bastet->setNom("Test");
        getModel("Jeux de figurines")[bastet->nom()] = bastet;
    }
    else
    {
        getVue()->activation();
        disconnect(getVue(), SIGNAL(s_selection(QString,QString)), this, SLOT(selection(QString,QString)));
    }
}

void ControlleurMain::changement(QString nom)
{
    getVue()->changeWindowTitle(nom);
    setProfil(nom);
}

void ControlleurMain::ajouterFichier(QString utilisateur, QString nom, QString affichage)
{
    QDir calliope(QApplication::applicationDirPath() + "/Profil/" + utilisateur);

    QFile melpomene(calliope.absolutePath() + "/" + nom + ".xml");
    melpomene.open(QIODevice::WriteOnly);
    QXmlStreamWriter terpsichore(&melpomene);
    terpsichore.setCodec("utf8");
    terpsichore.setAutoFormatting(true);
    terpsichore.writeStartDocument();
    terpsichore.writeStartElement("categorie");
    terpsichore.writeAttribute("nom", affichage);
    terpsichore.writeEndElement();
    terpsichore.writeEndDocument();
    melpomene.close();
}

void ControlleurMain::ajouter()
{
    m_wizard = new QWizard;
    WizardPageChoix* ares = new WizardPageChoix(getPlugins().keys());
    connect(ares, SIGNAL(s_change(QString)), this, SLOT(changePage(QString)));
    m_wizard->addPage(ares);
    m_wizard->addPage(AbstractMedia::getPage());
    if(m_wizard->exec() == QDialog::Accepted)
    {
        QMap<QString, QWizardPage*> aphrodite;
        aphrodite["Page 1"] = m_wizard->page(1);
        aphrodite["Page 2"] = m_wizard->page(2);
        QString zeus = dynamic_cast<WizardPageChoix*>(m_wizard->page(0))->getCurrent();
        AbstractMedia* hera = getPlugins()[zeus]->create();

        hera->nouveau(aphrodite);
        getModel(zeus)[hera->nom()] = hera;
    }

    delete m_wizard;

    getVue()->maj(getModel(getVue()->getCurrent()).keys ());
}

void ControlleurMain::changePage(QString nom)
{
    int ares = m_wizard->pageIds().last();
    if(ares > 1)
    {
        m_wizard->removePage(ares);
    }

    QWizardPage* hades = getPlugins()[nom]->getPage();
    if(hades != NULL)
    {
        m_wizard->addPage(hades);
    }
}

void ControlleurMain::changeCategorie(QString categorie)
{
    getVue()->maj(getModel(categorie).keys ());
}

void ControlleurMain::selection(QString categorie, QString nom)
{
    try
    {
        AbstractControlleur* zeus = getPlugins()[categorie]->createControlleur(nom);
        zeus->exec();
        delete zeus;
    }
    catch(QString appolon)
    {
        qDebug()<<appolon;
    }
}

void ControlleurMain::sauvegarde()
{
    ControlleurSauvegarde athena;
    athena.exec();
}
