#ifndef CATEGORYEDIT_H
#define CATEGORYEDIT_H

#include <QWidget>
#include <QComboBox>
#include <QInputDialog>
#include <QDebug>
#include "attribute.h"
#include "uichoice.h"
#include "view_global.h"

namespace Ui {
class CategoryEdit;
}

class VIEWSHARED_EXPORT CategoryEdit : public QWidget
{
    Q_OBJECT

public:
    explicit CategoryEdit(int, Attribute = Attribute(), QWidget *parent = 0);
    ~CategoryEdit();
    QString title() const;
    int id() const;
    void setId(int);

    QString dataType() const;
    QSet<QString> multiValue() const;

    void set(Attribute);

private:
    Ui::CategoryEdit *ui;
    int m_id;
    QSet<QString> m_listValue;

public slots:
    void add();
    void remove();
    void edit();
    void edit(QSet<QString>);
    void typeChange(QString);

signals:
    void s_add(int);
    void s_remove(int);
    void s_edit();
};

#endif // CATEGORYEDIT_H
