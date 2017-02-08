#ifndef CONTROLLEURJEUXVIDEO_H
#define CONTROLLEURJEUXVIDEO_H

#include "../../Controlleur/controlleurplugin.h"
#include "JeuxVideo.h"
#include "fenetrejeuxvideo.h"
#include "jeuxvideo_global.h"
#include "pluginjeuxvideo.h"

class JEUXVIDEOSHARED_EXPORT ControlleurJeuxVideo: public AbstractControlleurPlugin
{
public:
    explicit ControlleurJeuxVideo(QString, InterfacePlugin* , QObject* = 0);
    ~ControlleurJeuxVideo();
    QStringList getListeSort () const;

    void setVue();
};

#endif // CONTROLLEURJEUXVIDEO_H
