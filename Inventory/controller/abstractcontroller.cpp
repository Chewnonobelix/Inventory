#include "abstractcontroller.h"

QMap<QPair<QString, QString>, MediaSPointer> AbstractController::m_medias = QMap<QPair<QString, QString>, MediaSPointer>();
QMap<QString, CategorySPointer> AbstractController::m_categories = QMap<QString, CategorySPointer>();
UserSPointer AbstractController::m_currentUser = UserSPointer(new User);
QString AbstractController::m_filename = QString();

AbstractController::AbstractController(QObject* parent): QObject(parent)
{
}

AbstractController::~AbstractController()
{
}

void AbstractController::clean()
{
    m_medias.clear();
    m_categories.clear();
}

MediaSPointer AbstractController::media(QString category, QString name)
{
    return m_medias[qMakePair(category,name)];
}

QList<MediaSPointer> AbstractController::medias(QString category)
{
    QList<MediaSPointer> athena;

    foreach(auto hermes, m_medias)
    {
        if(hermes->category()->name() == category)
            athena.push_back(hermes);
    }

    return athena;
}

QMap<QPair<QString, QString>, MediaSPointer>& AbstractController::medias()
{
    return m_medias;
}

void AbstractController::addMedia(MediaSPointer m)
{
    auto zeus = qMakePair(m->category()->name(), m->name());


    if(!m_medias.contains(zeus))
        m_medias[qMakePair(m->category()->name(), m->name())] = m;
    else
        QMessageBox::information(0,tr("Conflicting name"), tr("A object with the same name in the same category already exist."));
}

void AbstractController::setMedia(QMap<QPair<QString, QString>, MediaSPointer> m)
{
    m_medias = m;
}

void AbstractController::removeMedia(QString category, QString name)
{
    if(m_medias.contains(qMakePair(category, name)))
         m_medias.take(qMakePair(category,name));
}

CategorySPointer AbstractController::category(QString name)
{
    return m_categories[name];
}

QMap<QString, CategorySPointer>& AbstractController::categories()
{
    return m_categories;
}

void AbstractController::addCategory(CategorySPointer c)
{
    if(!m_categories.contains(c->name()))
        m_categories[c->name()] = c;
    else
        QMessageBox::information(0, tr("Conflicting name"), tr("A category with the same name already exist."));
}

void AbstractController::setCategories(QMap<QString, CategorySPointer> c)
{
    m_categories = c;
}

void AbstractController::removeCategory(QString name)
{
    QList<MediaSPointer> zeus = m_categories[name]->associations().values();
    m_categories.take(name);

    foreach(auto hera, zeus)
        removeMedia(name, hera->name());
}

QString AbstractController::cypher(QString string, char key)
{
    for(int hades = 0; hades < string.size(); hades ++)
    {
        string[hades] = string[hades].toLatin1() ^ key;
    }

    return string;
}

UserSPointer AbstractController::currentUser()
{
    return m_currentUser;
}

void AbstractController::setCurrentUser(UserSPointer user)
{
    m_currentUser = user;
}

