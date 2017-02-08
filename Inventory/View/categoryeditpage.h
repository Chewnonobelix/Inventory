#ifndef CATEGORYEDITPAGE_H
#define CATEGORYEDITPAGE_H

#include <QDialog>
#include <QListWidget>
#include <QList>
#include <QPointer>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QAbstractScrollArea>
#include <QSpacerItem>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QVariant>
#include <QQueue>
#include <QInputDialog>
#include <QObject>
#include <cmath>
#include "view_global.h"
#include "category.h"
#include "categoryedit.h"
#include "subcomponent.h"

namespace Ui {
class  CategoryEditPage;
}

typedef SubComponent<Category, CategoryEdit> SubCategory;

class VIEWSHARED_EXPORT CategoryEditPage : public QDialog
{
    Q_OBJECT
public:

    explicit CategoryEditPage(QWidget *parent = 0);
    ~CategoryEditPage();
    void set(CategorySPointer);
    QList<CategorySPointer> toRemove() const;

private:
    Ui::CategoryEditPage *ui;
    QString m_old;
    SubCategory m_parent;
    QTreeWidgetItem* m_root;
    QList<CategorySPointer> m_remove;

    void updateIndex(QTreeWidgetItem*);
    void clearAttribute();

    QTreeWidgetItem* constructSub(CategorySPointer, int = 0);
    CategorySPointer prefixCheck(QTreeWidgetItem*);
    QTreeWidgetItem* treeSearch(QTreeWidgetItem*, QString = QString(), int = -1);
    int nodeCount(QTreeWidgetItem*);

public slots:
    void accept();
    void addAttribute(int, QTreeWidgetItem* = nullptr);
    void removeAttribute(int);
    void showSub(QTreeWidgetItem*, int = 0);
    void tabChanged(int);
    void addSub();
    void removeSub();
    void textChanged(QTreeWidgetItem*, int);

signals:
    void s_valide(Category, QString);
    void s_showSub(QString);

};

typedef QPointer<CategoryEditPage> CategoryEditPagePointer;

Q_DECLARE_METATYPE(SubCategory)

#endif // CATEGORYEDITPAGE_H
