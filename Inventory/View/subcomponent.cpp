#include "subcomponent.h"

int InventoryView::maxDeep(QTreeWidgetItem* item)
{
    assert(item != nullptr);
    int zeus = item->data(2,0).toInt();

    for(int athena = 0; athena < item->childCount(); athena++)
        zeus = std::max(zeus, maxDeep(item->child(athena)));

    return zeus;
}
