#ifndef MEDIACONTROLLER_H
#define MEDIACONTROLLER_H

#include <QObject>
#include "controller_global.h"
#include "abstractcontroller.h"
#include "mediaview.h"
#include "media.h"
#include "usercontroller.h"

class CONTROLLERSHARED_EXPORT MediaController final: public AbstractController
{
    Q_OBJECT

private:
    MediaSPointer m_media;
    MediaViewPointer m_view;

    MediaSPointer generate(QTreeWidgetItem*) const;
public:
    MediaController(MediaSPointer);
    ~MediaController();

    int exec();

public slots:
    void change(QTreeWidgetItem*, QString);
};

#endif // MEDIACONTROLLER_H
