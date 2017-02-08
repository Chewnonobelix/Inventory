
#ifndef __JeuxVideo_h__
#define __JeuxVideo_h__

#include "../../Model/AbstractMedia.h"
#include "wizardpagejv.h"
#include "jeuxvideo_global.h"

#include <exception>
#include <QString>
#include <QtWidgets/QRadioButton>
#include <QCheckBox>
#include <QComboBox>

using namespace std;

class JEUXVIDEOSHARED_EXPORT JeuxVideo: public AbstractMedia
{
public: enum support{non = 0, cd = 1 , steam = 2, steamcd = 3};

private:
    QString m_type;
    QString m_support;
    support m_supportPhysique;
    QString m_studio;
    QString m_editeur;
    Qt::CheckState m_extension;

public:
    JeuxVideo();
    JeuxVideo(const JeuxVideo&);
    ~JeuxVideo();

    QString getType() const;
    void setType(QString);
    QString getSupport() const;
    void setSupport(QString);
    support hasSupportPhysique() const;
    void setSupportPhysique(support);
    QString getStudio() const;
    void setStudio(QString);
    QString getEditeur() const;
    void setEditeur(QString);
    Qt::CheckState isExtension() const;
    void setExtension(Qt::CheckState);

    bool operator==(const JeuxVideo&);
    bool operator<(const JeuxVideo&);
    JeuxVideo& operator=(const JeuxVideo&);

    void chargement(QDomElement&);
    void sauvegarde(QXmlStreamWriter&);
    void nouveau(QMap<QString, QWizardPage *>);
};

#endif
