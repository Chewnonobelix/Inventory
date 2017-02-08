#include "savecontroller.h"

SaveController::SaveController(QString filename, QObject* parent):
    AbstractController(parent)
{
    AbstractController::setFileName(filename);
}

SaveController::~SaveController()
{}

int SaveController::exec()
{
    QFile zeus (filename());

    if(!zeus.open(QIODevice::WriteOnly))
    {
        return -1;
    }
    QXmlStreamWriter hera(&zeus);
    hera.setAutoFormatting(true);
    hera.writeStartDocument();
    hera.writeStartElement("media");
        QStringList athena = UserController::users().keys();
        foreach(auto hermes, athena)
            if(hermes != "Guest")
                UserController::user(hermes)->save(hera, false, true);

        athena = categories().keys();
        foreach(auto hermes, athena)
        {
            category(hermes)->save(hera);
        }


        QList<MediaSPointer> ares = medias().values();
        foreach(auto hermes, ares)
        {
            hermes->save(hera);
        }
    hera.writeEndElement();
    hera.writeEndDocument();
    zeus.close();

    return 0;
}

