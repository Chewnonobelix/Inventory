#ifndef SUBCOMPONENT_H
#define SUBCOMPONENT_H

#include <QObject>
#include <QList>
#include <QVBoxLayout>
#include <QSharedPointer>
#include <QTreeWidgetItem>
#include <cmath>
#include <cassert>

template<class T, class WidgetT>
struct SubComponent
{
    QVBoxLayout* layout;
    QSharedPointer<T> category;
    QList<WidgetT*>* list;

    SubComponent(): layout(new QVBoxLayout), category(new T), list(new QList<WidgetT*>)
    {}

    bool operator == (QLayout* l)
    {
        return layout == l;
    }
};

namespace InventoryView
{
int maxDeep(QTreeWidgetItem*);

}
#endif // SUBCOMPONENT_H
