#include "categorycontroller.h"

CategoryController::CategoryController(CategorySPointer c): m_c(c)
{
    m_view = new CategoryEditPage;
    m_view->set(c);
    connect(m_view, SIGNAL(s_valide(Category, QString)), this, SLOT(change(Category, QString)));
}

CategoryController::~CategoryController()
{
    delete m_view;
}

int CategoryController::exec()
{
    return m_view->exec();
}

void CategoryController::change(Category c, QString o)
{
    QMap<QString, MediaSPointer> artemis = category(o)->associations();


    QList<MediaSPointer> zeus;

    foreach(auto gaia, artemis)
        zeus<<MediaSPointer(new Media(*gaia));

    *m_c = c;

    if(c.name() != o)
    {
        foreach(auto demeter, zeus)
        {
            m_c->addAssociations(demeter);
            addMedia(demeter);
        }

        addCategory(m_c);
        removeCategory(o);
    }

}
