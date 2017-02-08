#ifndef BINARYEXPRESSION
#define BINARYEXPRESSION

#include "expression.h"

template<class T>
class BinaryExpression: public Expression<T>
{
private:
    Expression<T>* m_e1;
    Expression<T>* m_e2;

public:
    BinaryExpression<T>() = default;
    BinaryExpression<T>(const BinaryExpression<T>& e): Expression<T>(e), m_e1(e.m_e1->clone()), m_e2(e.m_e2->clone())
    {}

    ~BinaryExpression<T>()
    {
        if(m_e1 != nullptr)
            delete m_e1;

        if(m_e2 != nullptr)
            delete m_e2;
    }

    Expression<T>* e1() const
    {
        return m_e1;
    }

    Expression<T>* e2() const
    {
        return m_e2;
    }

    void setE1(Expression<T>* e)
    {
        m_e1 = e;
    }

    void setE2(Expression<T>* e)
    {
        m_e2 = e;
    }
};

#endif // BINARYEXPRESSION

