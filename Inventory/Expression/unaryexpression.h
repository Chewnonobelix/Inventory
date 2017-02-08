#ifndef UNARYEXPRESSION
#define UNARYEXPRESSION

#include "expression.h"

template<class T>
class UnaryExpression: public Expression<T>
{
private:
    Expression<T>* m_e;

public:
    UnaryExpression() = default;

    UnaryExpression(const UnaryExpression<T>& e): Expression<bool>(e), m_e(e.m_e->clone())
    {}

    ~UnaryExpression()
    {
        if(m_e != nullptr)
            delete m_e;
    }

    Expression<T>* e() const
    {
        return m_e;
    }

    void setE(Expression<T>* e)
    {
        m_e = e;
    }
};

#endif // UNARYEXPRESSION

