#ifndef FENETREJEUXVIDEO_H
#define FENETREJEUXVIDEO_H

#include <QDialog>

#include "JeuxVideo.h"
#include "jeuxvideo_global.h"

namespace Ui {
class FenetreJeuxVideo;
}

class JEUXVIDEOSHARED_EXPORT FenetreJeuxVideo : public QDialog
{
    Q_OBJECT
    
public:
    explicit FenetreJeuxVideo(JeuxVideo* = NULL, QWidget *parent = 0);
    ~FenetreJeuxVideo();

    void setModel(JeuxVideo* = NULL);
    
private:
    Ui::FenetreJeuxVideo *ui;
    JeuxVideo* m_model;

public slots:
    void accept();
};

#endif // FENETREJEUXVIDEO_H
