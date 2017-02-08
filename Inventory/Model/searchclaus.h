#ifndef SEARCHCLAUS_H
#define SEARCHCLAUS_H

#include <QString>
#include <QSharedPointer>
#include "model_global.h"
#include "category.h"
#include "media.h"
#include "andexpression.h"
#include "orexpression.h"
#include "noexpression.h"
#include "valueexpression.h"

class MODELSHARED_EXPORT SearchClaus
{
public:
    enum Operator {Or, And, No, Yes};
private:
    QString m_attribute;
    QString m_value;

    ValueExpression<bool>* m_claus;

public:
    SearchClaus();
    SearchClaus(const SearchClaus&);
    ~SearchClaus();

    bool operator == (const Media&) const;
    bool operator == (const Category &) const;

    static Expression<bool>* expressionFactory(Operator);

    QString attribute() const;
    void setAttribute(QString);
    QString value() const;
    void setValue(QString);

    void constructExpression(const Media &);
    void constructExpression(const Category&);
    ValueExpression<bool> *claus() const;
};

typedef QSharedPointer<SearchClaus> SearchClausSPointer;
#endif // SEARCHCLAUS_H
