#include <QApplication>
#include "../Controlleur/controlleurmainwindow.h"
#include <QList>

//TODO rajouter les listeSort dans les plugins

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControlleurMain atlas(0);
    atlas.exec();

    return a.exec();
}
