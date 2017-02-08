#include "controlleurjeuxvideo.h"

ControlleurJeuxVideo::ControlleurJeuxVideo(QString nom, InterfacePlugin* plugin, QObject* parent): AbstractControlleurPlugin(nom, plugin, parent)
{
    setVue();
}

ControlleurJeuxVideo::~ControlleurJeuxVideo()
{}


void ControlleurJeuxVideo::setVue()
{
    m_vue = new FenetreJeuxVideo(dynamic_cast<JeuxVideo*>(courant()));
    dynamic_cast<FenetreJeuxVideo*>(getVue())->setModel();
}

QStringList ControlleurJeuxVideo::getListeSort () const
{
    return getModel ("Jeux Vidéo").keys ();
}
