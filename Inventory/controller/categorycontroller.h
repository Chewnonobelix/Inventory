#ifndef CATEGORYCONTROLLER_H
#define CATEGORYCONTROLLER_H

#include <QObject>
#include "abstractcontroller.h"
#include "categoryeditpage.h"
#include "controller_global.h"

class CONTROLLERSHARED_EXPORT CategoryController final : public AbstractController
{
    Q_OBJECT

private:
    CategorySPointer m_c;
    CategoryEditPagePointer m_view;

public:
    CategoryController(CategorySPointer);
    ~CategoryController();

    int exec();

public slots:
    void change(Category, QString);
};

#endif // CATEGORYCONTROLLER_H
