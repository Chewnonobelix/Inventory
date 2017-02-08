#ifndef SAVECONTROLLER_H
#define SAVECONTROLLER_H

#include<QFile>
#include <QMessageBox>
#include <QXmlStreamWriter>
#include "usercontroller.h"
#include "abstractcontroller.h"

class SaveController final: public AbstractController
{
private:

public:
    SaveController(QString, QObject* = nullptr);
    ~SaveController();

    int exec();
};

#endif // SAVECONTROLLER_H
