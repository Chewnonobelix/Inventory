#ifndef CONSTANTEXPRESSION_H
#define CONSTANTEXPRESSION_H

#include "valueexpression.h"

template<class T>
class ConstantExpression: public ValueExpression<T>
{
    using parent = ValueExpression<T>;

public:

    ConstantExpression(const T& v)
    {
        parent::m_value = v;
    }
    ConstantExpression(const ConstantExpression&) = default;

    ~ConstantExpression() = default;

    using parent::evaluate;
    void set(const T &) = delete;

    ConstantExpression<T>* clone() const
    {
        return new ConstantExpression<T>(*this);
    }
};
#endif // CONSTANTEXPRESSION_H
