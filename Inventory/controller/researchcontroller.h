#ifndef RESEARCHCONTROLLER_H
#define RESEARCHCONTROLLER_H

#include <QList>
#include <QVBoxLayout>
#include <QQueue>
#include "abstractcontroller.h"
#include "searchclaus.h"
#include "controller_global.h"
#include "claus.h"
#include "expression.h"
#include "groupclaus.h"
#include "researchview.h"

class CONTROLLERSHARED_EXPORT ResearchController final: public AbstractController
{
    Q_OBJECT

private:
    QList<SearchClaus*> m_claus;
    QList<MediaSPointer> m_result;

    ResearchView* m_view;

    SearchClaus* createClaus(Claus*);
    Expression<bool>* build(const GroupClaus*);
    SearchClaus::Operator fromString(QString) const;
    void clearClaus();

public:
    ResearchController(QWidget* = nullptr);
    ~ResearchController();
    int exec();
    QList<MediaSPointer> results() const;

public slots:
    void search();

signals:
    void s_find(QList<MediaSPointer>);
};

#endif // RESEARCHCONTROLLER_H
