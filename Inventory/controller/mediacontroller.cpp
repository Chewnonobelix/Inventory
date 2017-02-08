#include "mediacontroller.h"

MediaController::MediaController(MediaSPointer m):m_media(m)
{
    m_media = m;
    m_view = new MediaView(m, UserController::currentUser()->type());
    connect(m_view, SIGNAL(s_send(QTreeWidgetItem*, QString)), this, SLOT(change(QTreeWidgetItem*, QString)));
}

MediaController::~MediaController()
{
    delete m_view;
}

int MediaController::exec()
{
    return m_view->exec();
}

MediaSPointer MediaController::generate(QTreeWidgetItem* root) const
{
    MediaSPointer demeter(new Media);
    QList<MediaWidget*> list = *(root->data(1,0).value<SubMedia>().list);
    QMap<QString, QString> hermes;
    foreach(auto athena, list)
    {
        hermes[athena->title()] = athena->value();
    }


    demeter->setAttributes(hermes);
    demeter->setName(root->text(0));
    demeter->setCategory(root->data(1,0).value<SubMedia>().category.data()->category());
    for(auto gaia = 0; gaia < root->childCount(); gaia++)
        demeter->addSubMedia(generate(root->child(gaia)));

    return demeter;
}

void MediaController::change(QTreeWidgetItem* root, QString old)
{
    removeMedia(m_media->category()->name(), old);
    *m_media = *generate(root);
    addMedia(m_media);
}

