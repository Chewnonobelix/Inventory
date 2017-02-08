#ifndef VALUEEXPRESSION
#define VALUEEXPRESSION

#include "expression.h"

template<class T>
class  ValueExpression: public Expression<T>
{
protected:
    T m_value;

public:
    ValueExpression() = default;

    ValueExpression(const ValueExpression<T>&) = default;

    ~ValueExpression() = default;


    void set(const T& value)
    {
        m_value = value;
    }

    T evaluate() const
    {
        return m_value;
    }

    ValueExpression<T>* clone() const
    {
        return new ValueExpression<T>(*this);
    }
};

#endif // VALUEEXPRESSION

