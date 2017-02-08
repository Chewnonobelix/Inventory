#ifndef CLAUS_H
#define CLAUS_H

#include <QWidget>
#include <QPointer>
#include "search.h"
#include "searchclaus.h"
#include "valueexpression.h"
#include "view_global.h"

namespace Ui {
class Claus;
}

class VIEWSHARED_EXPORT Claus : public Search
{
    Q_OBJECT

public:
    explicit Claus(QWidget *parent = 0);
    ~Claus();

    QString field() const;
    QString value() const;
    bool isChecked() const;


protected:
    void changeEvent(QEvent *);

private:
    Ui::Claus *ui;

signals:
    void s_remove(int);
};

#endif // CLAUS_H
