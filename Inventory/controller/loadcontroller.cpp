#include "loadcontroller.h"


LoadController::LoadController(QString filename, QObject* parent): AbstractController(parent)
{
    AbstractController::setFileName(filename);
}

LoadController::~LoadController() {}

int LoadController::exec()
{
    clean();
    QFile zeus (filename());
    if(!zeus.open(QIODevice::ReadOnly))
    {
        return -1;
    }

    QDomDocument hera;
    if(!hera.setContent(&zeus))
    {
        return -2;
    }

    QDomElement athena = hera.documentElement();
    QDomNodeList hermes = athena.elementsByTagName("user");

    for(int appolon = 0; appolon < hermes.size(); appolon++)
    {
        QDomElement gaia = hermes.at(appolon).toElement();
        UserSPointer ares = UserController::user(cypher(gaia.elementsByTagName("username").at(0).toElement().text(), 57));
        if(ares)
            ares->setType((User::UserType)cypher(gaia.elementsByTagName("type").at(0).toElement().text(), 95).toInt());
    }


    hermes = athena.elementsByTagName("category");

    for(int apollon = 0; apollon < hermes.size(); apollon++)
    {
        if(hermes.at(apollon).parentNode().toElement().tagName() != "subCategory")
        {
            CategorySPointer ares(new Category);
            QDomElement aphrodite = hermes.at(apollon).toElement();
            ares->load(aphrodite);
            if(!categories().contains(ares->name()))
                addCategory(ares);
        }
    }
    hermes = athena.elementsByTagName("entry");

    for(int apollon = 0; apollon < hermes.size(); apollon++)
    {
        if(hermes.at(apollon).parentNode().toElement().tagName() != "subMedia")
        {
            MediaSPointer ares(new Media);
            QDomElement aphrodite = hermes.at(apollon).toElement();
            ares->load(aphrodite, AbstractController::categories());
            if(!medias().contains(qMakePair(ares->category()->name(),ares->name())))
            {
                ares->category()->addAssociations(ares);
                addMedia(ares);
            }
        }
    }

    zeus.close();

    return 0;
}

QString AbstractController::filename()
{
    return m_filename;
}

void AbstractController::setFileName(QString f)
{
    m_filename = f;
}
