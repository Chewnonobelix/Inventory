#ifndef RESEARCHVIEW_H
#define RESEARCHVIEW_H

#include <QDialog>
#include <QPointer>
#include <QList>
#include <QPushButton>

#include "view_global.h"
#include "groupclaus.h"

namespace Ui {
class ResearchView;
}

class VIEWSHARED_EXPORT ResearchView : public QDialog
{
    Q_OBJECT

public:
    explicit ResearchView(QWidget *parent = 0);
    ~ResearchView();
    const GroupClaus* claus() const;

protected:
    void changeEvent(QEvent *);

private:
    Ui::ResearchView *ui;
    GroupClaus* m_first;

public slots:
    void clicked(QAbstractButton*);

signals:
    void s_search();
};


#endif // RESEARCHVIEW_H
