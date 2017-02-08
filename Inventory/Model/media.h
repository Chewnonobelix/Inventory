#ifndef MEDIA_H
#define MEDIA_H

#include <QString>
#include <QStringList>
#include <QMap>
#include <QMultiMap>
#include <QXmlStreamWriter>
#include <QDomElement>
#include <QDomNodeList>
#include <QSharedPointer>
#include <QStack>
#include "model_global.h"

class MODELSHARED_EXPORT Category;
class MODELSHARED_EXPORT Media;

typedef QSharedPointer<Media> MediaSPointer;
typedef QSharedPointer<Category> CategorySPointer;

class MODELSHARED_EXPORT Media
{
private:
    Category* m_category;
    QMap<QString, QString> m_attributes;

    QMap<QString, MediaSPointer> m_subMedia;

public:
    Media();
    Media(const Media&) = default;
    ~Media();

    QString name() const;
    void setName(QString );
    Category* category() const;
    void setCategory(Category*);
    QMap<QString, QString> attributes() const;
    QString attribute(QString) const;
    void setAttributes(const QMap<QString, QString> &);
    bool addAttribute(QString, QString);

    const QMap<QString, MediaSPointer>& subMedias() const;
    MediaSPointer subMedia(QString) const;
    void setSubMedia(QMap<QString, MediaSPointer>);
    void addSubMedia(MediaSPointer);
    void removeSub(QString);

    void save(QXmlStreamWriter&) const;
    void load(QDomElement&, const QMap<QString, CategorySPointer>&);
    bool validate() const;

    Media& operator= (const Media&);
    friend bool operator==(const Media&, const Media&);
    friend bool operator < (const Media&, const Media&);

    operator MediaSPointer()
    {
        return MediaSPointer(this);
    }

    operator QString()
    {
        return "Media(0x"+QString::number((long)this, 16)+", "+name()+")";
    }
};

Q_DECLARE_METATYPE(Media)

#endif // MEDIA_H
