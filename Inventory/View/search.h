#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QPointer>
#include <QDebug>
#include <QEvent>
#include "expression.h"
#include "view_global.h"

class VIEWSHARED_EXPORT Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    virtual ~Search();

    int id() const;
    void setId(int);
    virtual bool isChecked() const = 0;

protected:

private:
    int m_id;
};

#endif // SEARCH_H
