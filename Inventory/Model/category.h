#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>
#include <QSet>
#include <QMap>
#include <QMultiMap>
#include <QXmlStreamWriter>
#include <QDomElement>
#include <QDebug>
#include <QSharedPointer>
#include "model_global.h"
#include "attribute.h"
#include "media.h"

class MODELSHARED_EXPORT Category;

typedef QSharedPointer<Category> CategorySPointer;

class MODELSHARED_EXPORT Category
{

private:
    QList<Attribute> m_value;

    Category* m_parent;
    QMap<QString, CategorySPointer> m_subCategory;


    QMultiMap<QString, MediaSPointer> m_associations;
public:
    Category();
    Category(const Category&) = default;
    ~Category();

    QString name() const;
    void setName(QString);

    const QList<Attribute>& values() const;
    Attribute* value(QString);
    const Attribute* value(QString) const;
    void addValue(Attribute);
    void setValue(const QList<Attribute>&);

    const QMap<QString, CategorySPointer>& subCategory() const;
    CategorySPointer subCategory(QString) const;
    void setSubCategory(const QMap<QString, CategorySPointer> &);
    void addSubCategory(CategorySPointer);

    Category* parent() const;
    void setParent(Category*);

    void load(QDomElement&);
    void save(QXmlStreamWriter&) const;

    Category& operator=(const Category&);
    friend bool operator <(const Category&, const Category&);
    friend bool operator ==(const Category&, const Category&);

    QList<CategorySPointer>& research(QList<CategorySPointer>&, QStringList) const;

    const QMultiMap<QString, MediaSPointer>& associations() const;
    void setAssociations(const QMultiMap<QString, MediaSPointer> &associations);
    void addAssociations(MediaSPointer);
    void removeAssociations(MediaSPointer);
    bool containAssociation(Media*) const;
};

Q_DECLARE_METATYPE(Category)

#endif // CATEGORY_H
