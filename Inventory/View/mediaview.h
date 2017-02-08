#ifndef MEDIAVIEW_H
#define MEDIAVIEW_H

#include <QDialog>
#include <QPointer>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QTreeWidgetItem>
#include <QInputDialog>
#include <QMessageBox>
#include "category.h"
#include "media.h"
#include "mediawidget.h"
#include "view_global.h"
#include "user.h"
#include "attribute.h"
#include "subcomponent.h"

namespace Ui {
class MediaView;
}

typedef SubComponent<Media, MediaWidget> SubMedia;

class VIEWSHARED_EXPORT MediaView : public QDialog
{
    Q_OBJECT

public:
    explicit MediaView(MediaSPointer, User::UserType, QWidget *parent = 0);
    ~MediaView();

private:
    Ui::MediaView *ui;
    QList<MediaWidget*> m_attribute;
    QVBoxLayout* l_attribute;
    QTreeWidgetItem* m_root;
    User::UserType m_user;
    QString m_old;

    QTreeWidgetItem* constructTree(MediaSPointer, int);

public slots:
    void accept();
    void showSub(QTreeWidgetItem*, int);
    void addSub();
    void removeSub();
    void editName(QTreeWidgetItem*, int);

signals:
    void s_send(QTreeWidgetItem*, QString);

};

typedef QPointer<MediaView> MediaViewPointer;
Q_DECLARE_METATYPE(SubMedia)
#endif // MEDIAVIEW_H
