#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#include <QObject>
#include <QMap>
#include <QPair>
#include <QInputDialog>
#include <QMessageBox>

#include "controller_global.h"
#include "media.h"
#include "category.h"
#include "user.h"

class AbstractController: public QObject
{
private:
    static QMap<QPair<QString,QString>, MediaSPointer> m_medias;
    static QMap<QString, CategorySPointer> m_categories;
    static UserSPointer m_currentUser;
    static QString m_filename;

protected:
    QString cypher(QString, char);

public:
    AbstractController(QObject* = nullptr);
    virtual ~AbstractController();

    virtual int exec() = 0;

    static void clean();

    static MediaSPointer media(QString, QString);
    static QMap<QPair<QString, QString>, MediaSPointer>& medias();
    static QList<MediaSPointer> medias(QString);
    static void addMedia(MediaSPointer);
    static void setMedia(QMap<QPair<QString, QString>, MediaSPointer>);
    static void removeMedia(QString, QString);

    static CategorySPointer category(QString);
    static QMap<QString, CategorySPointer>& categories();
    static void addCategory(CategorySPointer);
    static void setCategories(QMap<QString, CategorySPointer>);
    static void removeCategory(QString);

    static UserSPointer currentUser();
    static void setCurrentUser(UserSPointer);

    static QString filename();
    static void setFileName(QString);
};

#endif // ABSTRACTCONTROLLER_H
