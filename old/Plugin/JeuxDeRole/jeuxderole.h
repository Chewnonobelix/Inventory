#ifndef JEUXDEROLE_H
#define JEUXDEROLE_H

#include "jeuxderole_global.h"
#include "supplement.h"
#include "../../Model/AbstractMedia.h"
#include <QCheckBox>
#include <QSet>
#include "wizardpagejdr.h"

class JEUXDEROLESHARED_EXPORT JeuxDeRole: public AbstractMedia
{

private:
    QSet<Supplement> m_supplement;
    Qt::CheckState m_achat;
    Supplement::Langue m_langueBase;

public:
    JeuxDeRole();
    JeuxDeRole(const JeuxDeRole&);
    ~JeuxDeRole();

    void chargement (QDomElement &);
    void sauvegarde (QXmlStreamWriter &);
    void nouveau (QMap<QString, QWizardPage *>);

    int nbSupplement() const;
    void addSupplement(Supplement);
    QSet<Supplement> supplement() const;
    void setSupplement(QSet<Supplement>);

    Qt::CheckState achat() const;
    void setAchat(Qt::CheckState achat);
    Supplement::Langue langue() const;
    void setLangue(Supplement::Langue langue);

    JeuxDeRole& operator = (const JeuxDeRole&);
    bool operator == (const JeuxDeRole&);
    bool operator < (const JeuxDeRole&);
};

#endif // JEUXDEROLE_H
