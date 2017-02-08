#ifndef LOADCONTROLLER_H
#define LOADCONTROLLER_H

#include <QFile>
#include <QDomElement>
#include <QDomDocument>
#include <QDomNodeList>
#include <QDebug>
#include "usercontroller.h"
#include "abstractcontroller.h"

class LoadController final : public AbstractController
{
private:

public:
    LoadController(QString, QObject* = nullptr);
    ~LoadController();
    int exec();

};

#endif // LOADCONTROLLER_H
