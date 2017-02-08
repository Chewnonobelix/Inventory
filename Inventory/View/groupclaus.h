#ifndef GROUPCLAUS_H
#define GROUPCLAUS_H

#include <QWidget>
#include <QList>
#include <QPointer>
#include <QMessageBox>

#include "search.h"
#include "claus.h"
#include "view_global.h"

namespace Ui {
class GroupClaus;
}

class VIEWSHARED_EXPORT GroupClaus : public Search
{
    Q_OBJECT

public:
    explicit GroupClaus(QWidget *parent = 0);
    ~GroupClaus();

    int countClaus() const;
    Search* claus(int) const;
    bool isChecked() const;
    QString operation() const;

protected:
    void changeEvent(QEvent *);

private:
    Ui::GroupClaus *ui;
    QList<Search*> m_composite;

    void checkId();

public slots:
    void addClaus();
    void addGroup();
    void remove();

signals:

};

#endif // GROUPCLAUS_H
